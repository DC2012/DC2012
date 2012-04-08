#include "gamewindow.h"
#include "../../sprites/sprites.h"
#include "MessageWrapper.h"
#include "messagereadworker.h"
#include "../player/GameObjectFactory.h"
#include "graphicsobjectfactory.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QCursor>
#include <QMessageBox>
#include <QThread>
#include <iostream>

GameWindow::GameWindow(QWidget *parent)
    : QGraphicsView(parent), timer_(this), scene_(new QGraphicsScene())
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setCursor(QCursor(QPixmap(":/sprites/spriteCursor.png")));
    setFixedSize(CLIENT_WIDTH, CLIENT_HEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene_->setSceneRect(0, 0, CLIENT_WIDTH, CLIENT_HEIGHT);
    setScene(scene_);

    // load map - the positions will eventually be stored in an xml file
    QPixmap land(TILE_LAND1);
    QPixmap sea(TILE_WATER1);
    for (int x = 0; x < CLIENT_WIDTH; x += 50)
    {
        for(int y = 0; y < CLIENT_HEIGHT / 3; y += 50)
        {
            QGraphicsPixmapItem *landTile = new QGraphicsPixmapItem(land);
            landTile->setOffset(x, y);
            scene_->addItem(landTile);
        }

        for(int y = CLIENT_HEIGHT / 3; y < CLIENT_HEIGHT; y += 50)
        {
            QGraphicsPixmapItem *seaTile = new QGraphicsPixmapItem(sea);
            seaTile->setOffset(x, y);
            scene_->addItem(seaTile);
        }
    }

    client_ = Client::getInstance();

    connect(&timer_, SIGNAL(timeout()), this, SLOT(updateGame()));
    this->show();
}

void GameWindow::start()
{
    QThread* readThread = new QThread(this);
    MessageReadWorker* worker = new MessageReadWorker();

    worker->moveToThread(readThread);

    if(!connect(worker, SIGNAL(messageReceived(MessageWrapper *)),
            this, SLOT(addMessage(MessageWrapper *))))
    {
        QMessageBox::information(NULL, QString("Error"), QString("connect failed"));
    }

    if (!connect(readThread, SIGNAL(started()), worker, SLOT(readMessages())))
    {
        QMessageBox::information(NULL, QString("Error"), QString("connect failed"));
    }

    readThread->start();
    timer_.start(1000 / FRAME_RATE);
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
    case Qt::Key_Up:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(ACCEL, true);
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(ROTATE_L, true);
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(DECEL, true);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(ROTATE_R, true);
        break;
    case Qt::Key_Space:
        QMessageBox::information(this, "Fire!", "Assume that a bullet was fired.");
        break;
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
    case Qt::Key_Up:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(ACCEL, false);
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(ROTATE_L, false);
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(DECEL, false);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        if(!event->isAutoRepeat())
            myShip_->setActionFlag(ROTATE_R, false);
        break;
    case Qt::Key_Space:
        QMessageBox::information(this, "Fire!", "Assume that a bullet was fired.");
        break;
    }
}

void GameWindow::addMessage(MessageWrapper* msgwrap)
{
    mutex_.lock();
    messageQueue_.push(msgwrap->message);
    delete msgwrap;
    mutex_.unlock();
}

void GameWindow::processMessages()
{
    mutex_.lock();
    while (!messageQueue_.empty())
    {
        Message* msg = messageQueue_.front();
        processGameMessage(msg);
        messageQueue_.pop();
        delete msg;
    }
    mutex_.unlock();
}

void GameWindow::processGameMessage(Message* message)
{
    GameObject* obj;
    GraphicsObject* graphic;
    QStringList tokens;
    int objID; // game object map should be indexed by object ID

    switch (message->getType())
    {
    case Message::CONNECTION:
        QMessageBox::information(NULL, QString("Connection Message Received!"), QString::fromStdString(message->getData()));
        clientId_ = message->getID();
        if (message->getData() == "Refused")
        {
            QMessageBox::information(NULL, QString("Connection Problem"), QString("Connection Refused"));
            // handle the problem here somehow
        }
        break;

    case Message::CREATION:
        QMessageBox::information(NULL, QString("Creation Message Received!"), QString::fromStdString(message->getData()));
        obj = GameObjectFactory::create(message->getData());
        objID = GameObjectFactory::getObjectID(message->getData());
        graphic = GraphicsObjectFactory::create(obj);

        if (obj->getType() == SHIP1 || obj->getType() == SHIP2)
        {
            if (message->getID() == clientId_)
            {
                myShip_ = new GOM_Ship(obj->getType(), obj->getObjID(),
                                       obj->getDegree(), obj->getPosition().getX(), obj->getPosition().getY(),
                                       clientId_, 0, 100, 100);

                myShipGraphic_ = new ShipGraphicsObject(myShip_);
                scene_->addItem(myShipGraphic_->getPixmapItem());
            }
            else
            {
                ships_[message->getID()] = (ShipGraphicsObject*) graphic;
                scene_->addItem(graphic->getPixmapItem());
            }
        }
        else
        {
            otherGraphics_[objID] = graphic;
            scene_->addItem(graphic->getPixmapItem());
        }


        break;

    case Message::UPDATE:
        // check to not update client's own ship
        if(message->getID() != clientId_)
        {
            ships_[message->getID()]->update(message->getData());
        }
        break;


    case Message::DELETION:
        tokens = QString::fromStdString(message->getData()).split(" ");

        // 0 - object type where 'S' is ship and 'P' is projectile
        // 1 - object ID
        // 2 - explode flag (1 means object should explode, 0 don't explode)

        if (tokens[0] == "S")
            scene_->removeItem(ships_[tokens[1].toInt()]->getPixmapItem());
        else
            scene_->removeItem(otherGraphics_[tokens[1].toInt()]->getPixmapItem());

        // explosions not handled yet
        break;

    case Message::HIT:
        // unimplemented for now
        break;

    case Message::STATUS:
        // unimplemented
        break;

    }
}

void GameWindow::updateGame()
{
    processMessages();
    myShip_->move();
    myShipGraphic_->getPixmapItem()->setOffset(myShip_->getSpriteTopLeft().getX(),
                                               myShip_->getSpriteTopLeft().getY());

    myShipGraphic_->getPixmapItem()->setTransformOriginPoint(myShip_->getPosition().getX(),
                                                             myShip_->getPosition().getY());

    myShipGraphic_->getPixmapItem()->setRotation(myShip_->getDegree() - 270);

    Message msg;
    msg.setID(clientId_);
    msg.setData(myShip_->toString());
    msg.setType(Message::UPDATE);
    client_->write(&msg);
}
