#include "gamewindow.h"
#include "../../sprites/sprites.h"
#include "messagereadworker.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLineEdit>
#include <QCursor>
#include "../../src/env/chat/ChatDlg.h"
#include <QMessageBox>
#include <QThread>

GameWindow::GameWindow(QWidget *parent)
    : QGraphicsView(parent), timer_(this), scene_(new QGraphicsScene()), gcontroller_(scene_, this), currentScale_(1)
{

    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setCursor(QCursor(QPixmap("sprites/spriteCursor.png")));
    setFixedSize(CLIENT_WIDTH, CLIENT_HEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // env chat message stuff
    //change 1 to actual client ID
    chatdlg_ = new ChatDlg(this, 1);
    //
    chatdlg_->setModal(false);
    isChatting_ = false;
    chatdlg_->setGeometry(0, (this->geometry().height() - 150), 400, 150);

    scene_ = new QGraphicsScene();
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
    qRegisterMetaType<Message *>("Message *");
    connect(worker, SIGNAL(messageReceived(Message*)), &gcontroller_, SLOT(addMessage(Message*)));
    connect(readThread, SIGNAL(started()), worker, SLOT(readMessages()));

    readThread->start();
    timer_.start(1000 / FRAME_RATE);
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    QLineEdit *le = chatdlg_->findChild<QLineEdit *>("lineEdit_input");

    switch(event->key())
    {
    case Qt::Key_W:
    case Qt::Key_Up:
        scale(currentScale_ + .10, currentScale_ + .10);
        ship_->setOffset(ship_->offset().x(), ship_->offset().y() - 1);
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        ship_->setOffset(ship_->offset().x() - 1, ship_->offset().y());
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        scale(currentScale_ - .10, currentScale_ - .10);
        ship_->setOffset(ship_->offset().x(), ship_->offset().y() + 1);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        ship_->setOffset(ship_->offset().x() + 1, ship_->offset().y());
        break;
    case Qt::Key_Space:
        QMessageBox::information(this, "Fire!", "Assume that a bullet was fired.");
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        // this will change when we have the chat portion as it's own
        // frame/widget. We also set the lineEdit_input to have focus()
        if(!this->isChatting())
        {
            if(!chatdlg_->isVisible())
                chatdlg_->show();
            le->setVisible(true);
            le->setFocus();

            this->setChatting(true);
        }
        else
        {
            // eventually we will just hide the lineEdit control
            le->setVisible(false);
            this->setChatting(false);
        }
        break;

    }
}

void GameWindow::updateGame()
{
    gcontroller_.processMessages();
}

void GameWindow::setChatting(bool b)
{
    GameWindow::isChatting_ = b;
}

bool GameWindow::isChatting()
{
    return GameWindow::isChatting_;
}
