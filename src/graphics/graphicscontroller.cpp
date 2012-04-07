#include "graphicscontroller.h"
#include "graphicsobjectfactory.h"
#include "../player/GameObjectFactory.h"
#include <QMessageBox>

GraphicsController::GraphicsController(QGraphicsScene *scene, QObject *parent) :
    QObject(parent), scene_(scene)
{

}

void GraphicsController::addMessage(MessageWrapper* msgwrap)
{
    mutex_.lock();
    messageQueue_.push(msgwrap->message);
    delete msgwrap;
    mutex_.unlock();
}

void GraphicsController::processMessages()
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

void GraphicsController::processGameMessage(Message* message)
{
    GameObject* obj;
    GraphicsObject* graphic;
    QStringList tokens;

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
        graphic = GraphicsObjectFactory::create(obj);

        if (obj->getType() == SHIP1 || obj->getType() == SHIP2)
            ships_[message->getID()] = graphic;
        else
            otherGraphics_[message->getID()] = graphic;

        scene_->addItem(graphic->getPixmapItem());
        break;

    case Message::UPDATE:
        ships_[message->getID()]->update(message->getData());
        // other objects are not handled yet
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
