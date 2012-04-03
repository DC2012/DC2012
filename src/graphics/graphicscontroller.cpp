#include "graphicscontroller.h"
#include "graphicsobjectfactory.h"

GraphicsController::GraphicsController(QGraphicsScene *scene, QObject *parent) :
    QObject(parent), scene_(scene)
{

}

void GraphicsController::addMessage(Message *message)
{
    mutex_.lock();
    messageQueue_.push(message);
    mutex_.unlock();
}

void GraphicsController::processMessages()
{
    mutex_.lock();
    while (!messageQueue_.empty())
    {
        Message *msg = messageQueue_.front();
        processGameMessage(msg);
        free(msg);
        messageQueue_.pop();
    }
    mutex_.unlock();
}

void GraphicsController::processGameMessage(Message *message)
{
    switch (message->getType())
    {
    case Message::CREATION:
        break;

    case Message::ACTION:
        break;

    case Message::DELETION:
        break;

    case Message::STATUS:
        break;
    }
}
