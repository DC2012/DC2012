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
#include <cmath>
#include <sstream>

GameWindow::GameWindow(QWidget *parent)
    : QGraphicsView(parent), timer_(this), scene_(new QGraphicsScene()), timerCounter_(0)
{
    // typical initialization code
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

    // get instance to client so we can send and receive
    // at this point, client should be connected already
    client_ = Client::getInstance();

    connect(&timer_, SIGNAL(timeout()), this, SLOT(updateGame()));
    this->show();
}

void GameWindow::start()
{
    // all the code below starts the client's reading thread that reads
    // from the server's blocking queue
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

    // audio is disabled for now since it's still a bit flaky
    //qRegisterMetaType<AudioController::Sounds>("AudioController::Sounds");
    //if (!connect(this, SIGNAL(shotFired(AudioController::Sounds, double)),
    //             &audio, SLOT(playSound(AudioController::Sounds, double)), Qt::QueuedConnection))
    //{
    //    QMessageBox::information(NULL, QString("Error"), QString("connect failed"));
    //}

    readThread->start();
    timer_.start(1000 / FRAME_RATE);
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    // one thing to take note of about this event is that unlike the keypressevent,
    // this event doesn't keep getting triggered if the user holds the mouse button down

    // shoot only when a ship is allowed to shoot which is once every ~800 ms
    // this is set by the update game timer to prevent ships from spamming shots
    if (ships_[clientId_]->canShoot())
    {
        double angle = ships_[clientId_]->shoot(event->pos());

        Message msg;
        msg.setID(clientId_);
        msg.setType(Message::ACTION);

        // the message data expected by the server is "shipX shipY shotAngle"
        std::ostringstream oss;
        oss << ships_[clientId_]->getGameObject()->getPosition().getX() << " "
            << ships_[clientId_]->getGameObject()->getPosition().getY() << " "
            << angle;

        msg.setData(oss.str());
        client_->write(&msg);
    }
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    GOM_Ship* myShip = (GOM_Ship *) ships_[clientId_]->getGameObject();

    switch(event->key())
    {
    case Qt::Key_W:
    case Qt::Key_Up:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(ACCEL, true);
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(ROTATE_L, true);
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(DECEL, true);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(ROTATE_R, true);
        break;
    case Qt::Key_Space:
        QMessageBox::information(this, "Fire!", "Assume that a bullet was fired.");
        break;
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    GOM_Ship* myShip = (GOM_Ship *) ships_[clientId_]->getGameObject();

    switch(event->key())
    {
    case Qt::Key_W:
    case Qt::Key_Up:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(ACCEL, false);
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(ROTATE_L, false);
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(DECEL, false);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        if(!event->isAutoRepeat())
            myShip->setActionFlag(ROTATE_R, false);
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
    int objID;
    Hitbox shipBox;

    // for debugging hit box
    static QGraphicsItem *line1, *line2, *line3, *line4;
    QPen pen;

    switch (message->getType())
    {
    case Message::CONNECTION:
        clientId_ = message->getID();
        if (message->getData() == "Refused")
        {
            QMessageBox::information(NULL, QString("Connection Problem"), QString("Connection Refused"));
            // handle the problem here somehow or just pray that the connection always succeeds
        }
        break;

    case Message::CREATION:
        obj = GameObjectFactory::create(message->getData());
        objID = GameObjectFactory::getObjectID(message->getData());
        graphic = GraphicsObjectFactory::create(obj);

        if (obj->getType() == SHIP1 || obj->getType() == SHIP2)
        {
            ships_[message->getID()] = (ShipGraphicsObject*) graphic;
            scene_->addItem(graphic->getPixmapItem());
        }
        else
        {
            //emit shotFired(AudioController::SHOOT1, 50);
            //QMessageBox::information(NULL, QString("Creation Message Received!"), QString::fromStdString(message->getData()));
            otherGraphics_[objID] = (ProjectileGraphicsObject *) graphic;
            scene_->addItem(graphic->getPixmapItem());
        }

        break;

    case Message::UPDATE:
        // update ship only if it's not our ship
        if(message->getID() != clientId_)
        {
            ships_[message->getID()]->update(message->getData());
        }

        // these lines are temporary to help us determine if the hitboxes
        // are being updated properly for collision detection
        scene_->removeItem(line1);
        scene_->removeItem(line2);
        scene_->removeItem(line3);
        scene_->removeItem(line4);
        shipBox = ships_[clientId_]->getGameObject()->getHitbox();
        //scene_->addRect(QRectF(QPointF(shipBox.tLeft.getX(), shipBox.tLeft.getY()),
        //                       QPointF(shipBox.bRight.getX(), shipBox.bRight.getY())));
        pen = QPen(Qt::SolidLine);
        pen.setWidth(1);
        line1 = scene_->addLine(shipBox.tLeft.getX(), shipBox.tLeft.getY(), shipBox.tRight.getX(), shipBox.tRight.getY(), pen);
        line2 = scene_->addLine(shipBox.tRight.getX(), shipBox.tRight.getY(), shipBox.bRight.getX(), shipBox.bRight.getY(), pen);
        line3 = scene_->addLine(shipBox.bRight.getX(), shipBox.bRight.getY(), shipBox.bLeft.getX(), shipBox.bLeft.getY(), pen);
        line4 = scene_->addLine(shipBox.bLeft.getX(), shipBox.bLeft.getY(), shipBox.tLeft.getX(), shipBox.tLeft.getY(), pen);
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
        std::cerr << "I got a hit!\n";
        break;

    case Message::STATUS:
        // unimplemented
        break;

    }
}

void GameWindow::updateGame()
{
    // ship can only shoot once every ~800 ms
    timerCounter_++;
    if (timerCounter_ >= 20)
    {
        ships_[clientId_]->setCanShoot();
        timerCounter_ = 0;
    }

    // update all the projectiles since the server doesn't send us
    // UPDATE messages for projectiles
    std::map<int, ProjectileGraphicsObject*>::iterator it = otherGraphics_.begin();
    while(it != otherGraphics_.end())
    {
        it->second->update("");
        if (it->second->isExpired())
        {
            // remove image from scene and perform a cleanup once the projectile expires
            scene_->removeItem(it->second->getPixmapItem());
            delete it->second;
            otherGraphics_.erase(it++);
        }
        else
        {
            ++it;
        }
    }


    processMessages();

    // update our own ship
    GOM_Ship* shipObj = (GOM_Ship *) ships_[clientId_]->getGameObject();
    shipObj->move();
    ships_[clientId_]->getPixmapItem()->setOffset(shipObj->getSpriteTopLeft().getX(),
                                                  shipObj->getSpriteTopLeft().getY());

    ships_[clientId_]->getPixmapItem()->setTransformOriginPoint(shipObj->getPosition().getX(),
                                                               shipObj->getPosition().getY());

    ships_[clientId_]->getPixmapItem()->setRotation(shipObj->getDegree() - 270);

    // send new coordinates of our ship to server
    // the message is dynamically allocated although typically there is no need to do so
    // but for some reason we're getting segfaults
    Message* msg = new Message;
    msg->setID(clientId_);
    msg->setData(shipObj->toString());
    msg->setType(Message::UPDATE);
    client_->write(msg);
    delete msg;
}
