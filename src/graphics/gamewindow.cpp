#include "gamewindow.h"
#include "../../sprites/sprites.h"
#include "MessageWrapper.h"
#include "messagereadworker.h"
#include "../player/GameObjectFactory.h"
#include "graphicsobjectfactory.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLineEdit>
#include <QCursor>
#include "../../src/env/chat/ChatDlg.h"
#include <QMessageBox>
#include <QThread>
#include <cmath>
#include <sstream>
#include "../env/gamemap.h"

GameWindow::GameWindow(QWidget *parent)
    : QGraphicsView(parent), timer_(this), scene_(new QGraphicsScene()), timerCounter_(0), state_(DEAD), connected_(false)
{
    // typical initialization code
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setCursor(QCursor(QPixmap(":/sprites/spriteCursor.png")));
    setFixedSize(CLIENT_WIDTH, CLIENT_HEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    map_ = new GameMap(":/src/env/maps/finalMap.tmx");
    // env chat message stuff
    //change 1 to actual client ID
    chatdlg_ = new ChatDlg(this, 1);
    //
    chatdlg_->setModal(false);
    isChatting_ = false;
    chatdlg_->setGeometry(0, (this->geometry().height() - 150), 400, 150);

    scene_ = new QGraphicsScene();
    /* Change these constants later */
    scene_->setSceneRect(0, 0, 160 * 25, 120 * 25);
    setScene(scene_);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);

    // load map - this will take a few seconds
    
    for(std::map<Point, Tile*>::iterator i = map_->gameTiles_.begin(); i != map_->gameTiles_.end(); i++)
    {
        scene()->addItem(i->second);
    }

    bg.setPixmap(QPixmap(":/sprites/finalMap.png"));
    scene()->addItem(&bg);

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
    qRegisterMetaType<AudioController::Sounds>("AudioController::Sounds");
    if (!connect(this, SIGNAL(shotFired(AudioController::Sounds, double)),
                 &audio, SLOT(playSound(AudioController::Sounds, double)), Qt::QueuedConnection))
    {
        QMessageBox::information(NULL, QString("Error"), QString("connect failed"));
    }

    if (!connect(this, SIGNAL(shipExplode(AudioController::Sounds, double)),
                 &audio, SLOT(playSound(AudioController::Sounds, double)), Qt::QueuedConnection))
    {
        QMessageBox::information(NULL, QString("Error"), QString("connect failed"));
    }

    readThread->start();
    timer_.start(1000 / FRAME_RATE);
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    // one thing to take note of about this event is that unlike the keypressevent,
    // this event doesn't keep getting triggered if the user holds the mouse button down

    // shoot only when a ship is allowed to shoot which is once every ~800 ms
    // this is set by the update game timer to prevent ships from spamming shots
    if (state_ == ALIVE)
    {
        if(!ships_[clientId_]->canShoot())
            return;
        double angle = ships_[clientId_]->shoot(mapToScene(event->pos()).toPoint());

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

    if(state_ == ALIVE)
    {
        QLineEdit *le = chatdlg_->findChild<QLineEdit *>("lineEdit_input");

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
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(state_ == ALIVE)
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
    QGraphicsPixmapItem* px;
    Message sendMsg;
    std::string data;

    switch (message->getType())
    {
    case Message::CONNECTION:
		connected_ = true;
        clientId_ = message->getID();
        if (message->getData() == "Accepted")
        {
//            data = std::string("0");
//            sendMsg.setID(clientId_);
//            sendMsg.setAll(data, Message::RESPAWN);
//            client_->write(&sendMsg);
        }
        else if (message->getData() == "Refused")
        {
            QMessageBox::information(NULL, QString("Connection Problem"), QString("Connection Refused"));
            // handle the problem here somehow or just pray that the connection always succeeds
        }
        break;

    case Message::CREATION:
        obj = GameObjectFactory::create(message->getData());
        objID = GameObjectFactory::getObjectID(message->getData());
        graphic = GraphicsObjectFactory::create(obj);
        std::cerr << "creation" << std::endl;
        if (obj->getType() == SHIP1 || obj->getType() == SHIP2)
        {
            if(message->getID() == clientId_)
            {
                state_ = ALIVE;
                connect((ShipGraphicsObject*)graphic, SIGNAL(death()), this, SLOT(death()))   ;
                shipChooser.setCreating(false);
            }
            ships_[message->getID()] = (ShipGraphicsObject*) graphic;
            scene_->addItem(graphic->getPixmapItem());
        }
        else
        {
            emit shotFired(AudioController::SHOOT1, ships_[clientId_]->getGameObject()->getObjDistance(*obj));
	    std::cerr << "projectile added id: " << std::endl;
            otherGraphics_[objID] = (ProjectileGraphicsObject *) graphic;
            scene_->addItem(graphic->getPixmapItem());
        }

        break;

    case Message::UPDATE:
        // update ship only if it's not our ship
        if(message->getID() != clientId_)
        {
            if (ships_.count(message->getID()) > 0)
            {
		//std::cout << "updated the ship" << std::endl;
                ships_[message->getID()]->update(message->getData());
            }
        }
        break;


    case Message::DELETION:
	std::cerr << "deletion" << std::endl;      
        tokens = QString::fromStdString(message->getData()).split(" ");

        // 0 - object type where 's' is ship and 'p' is projectile
        // 1 - object ID for projectils or clientID for ships
        // 2 - explode flag (1 means object should explode, 0 don't explode)
	
        if (tokens[0] == "S")
        {
            std::cerr << "ship deletion" << std::endl;
            emit shipExplode(AudioController::DIE, ships_[message->getID()]->getGameObject()->getObjDistance(*(ships_[clientId_]->getGameObject())));
	    std::cerr << "shipExplode emitted" << std::endl;
            ships_[message->getID()]->explode();
	    std::cerr << "ship.explode() called" << std::endl;

            if(message->getID() == clientId_)
            {
                //we died

                state_ = DEAD;
                std::cerr << "i'm dead" << std::endl;

            }
        }
        else if (tokens[0] == "P")
        {
            otherGraphics_[tokens[1].toInt()]->setExpired();
        }
        break;

    case Message::HIT:
        // message client id = client id that was hit
        // data = object id that client id collided with
        std::cerr << "got hit" << std::endl;
        if(ships_.count(message->getID()) > 0)
	{
	  int id = QString(message->getData().c_str()).toInt();
	  std::cerr << "id: " << id << std::endl;
	  if(otherGraphics_.count(id) > 0)
	  {
	    ships_[message->getID()]->gotHit(otherGraphics_[id]->getGameObject());
	  }
	  else
	  {
	    std::cerr << "invalid objid" << std::endl; 
	  }
	}
	std::cerr << "done hitting" << std::endl;
        break;

    case Message::STATUS:
        // unimplemented
        break;

    case Message::CHAT:
            // send to ChatDlg
        chatdlg_->incomingMsg(message->getData());
        break;

    }
}

void GameWindow::updateGame()
{
    if(state_ == ALIVE)
    {
        // ship can only shoot once every ~800 ms
        timerCounter_++;
        if (timerCounter_ >= 20)
        {
            ships_[clientId_]->setCanShoot();
            timerCounter_ = 0;
        }
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

    std::map<int, ShipGraphicsObject*>::iterator explodeIterator = ships_.begin();
    while(explodeIterator != ships_.end())
    {
        if(explodeIterator->second->isExploding())
        {
            explodeIterator->second->explode();
        }
        ++explodeIterator;
    }

    processMessages();

    if(state_ == ALIVE)
    {
        // update our own ship
        GOM_Ship* shipObj = (GOM_Ship *) ships_[clientId_]->getGameObject();
        shipObj->move();

        /* Needs to move the viewport, not the ship. */

        ships_[clientId_]->getPixmapItem()->setOffset(shipObj->getSpriteTopLeft().getX(),
                                                      shipObj->getSpriteTopLeft().getY());
        ships_[clientId_]->getPixmapItem()->setTransformOriginPoint(shipObj->getPosition().getX(),
                                                                   shipObj->getPosition().getY());

        if(map_->isLand(shipObj->getPosition()))
        {
            death();
            return;
        }

        centerOn(shipObj->getPosition().getX(), shipObj->getPosition().getY());


        /* This is ok */
        ships_[clientId_]->getPixmapItem()->setRotation(shipObj->getDegree() - 270);

        // send new coordinates of our ship to server
        // the message is dynamically allocated although typically there is no need to do so
        // but for some reason we're getting segfaults
	//std::cerr << "send update: " << shipObj->toString() << std::endl;
        Message* msg = new Message;
        msg->setID(clientId_);
        msg->setData(shipObj->toString());
        msg->setType(Message::UPDATE);
        client_->write(msg);
        delete msg;
    }
    else if(state_ == DEAD && connected_)
    {
        if(!shipChooser.isCreating())
        {
            shipChooser.setCreating(true);
            shipChooser.setModal(false);
            shipChooser.show();
        }
    }
}


void GameWindow::setChatting(bool b)
{
    GameWindow::isChatting_ = b;
}

bool GameWindow::isChatting()
{
    return GameWindow::isChatting_;
}

void GameWindow::death()
{
    if(state_ == ALIVE)
    {
        Message msg(clientId_);
        msg.setType(Message::DEATH);
        msg.setData("1");
        client_->write(&msg);
        state_ = DYING;
        std::cerr << "dying" << std::endl;
    }
}

void GameWindow::removePixmap(QGraphicsPixmapItem* pixmap)
{
    scene_->removeItem(pixmap);
}

QString GameWindow::getUsername()
{
    return username_;
}
void GameWindow::setUsername(QString str)
{
    username_ = str;
}
