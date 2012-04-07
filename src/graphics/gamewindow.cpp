#include "gamewindow.h"
#include "../../sprites/sprites.h"
#include "MessageWrapper.h"
#include "messagereadworker.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QCursor>
#include <QMessageBox>
#include <QThread>

GameWindow::GameWindow(QWidget *parent)
    : QGraphicsView(parent), timer_(this), scene_(new QGraphicsScene()), gcontroller_(scene_, this)
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setCursor(QCursor(QPixmap("sprites/spriteCursor.png")));
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

    // these pixmap objects will be replaced by proper
    // game objects once the implementation is complete
    QPixmap ship("sprites/spriteShip1.png");
    ship_ = new QGraphicsPixmapItem(ship);
    ship_->setPos(100, 100);
    scene_->addItem(ship_);

    connect(&timer_, SIGNAL(timeout()), this, SLOT(updateGame()));
    this->show();
}

void GameWindow::start()
{
    QThread* readThread = new QThread(this);
    MessageReadWorker* worker = new MessageReadWorker();

    worker->moveToThread(readThread);

    if(!connect(worker, SIGNAL(messageReceived(MessageWrapper *)),
            &gcontroller_, SLOT(addMessage(MessageWrapper *))))
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

void GameWindow::updateGame()
{
    // myShip_->move();
    /*
    ship_->setOffset(myShip_->getPosition().getX(), myShip_->getPosition().getY());
    ship_->setTransformOriginPoint(myShip_->getPosition());
    ship_->setRotation(myShip_->getDegree()-270);
    */

    /*
    Message msg;
    msg.setID(gcontroller_.getClientId());
    msg.setData(myShip_->toString());
    msg.setType(Message::UPDATE);
    client_->write(&msg);
    */

    gcontroller_.processMessages();
}
