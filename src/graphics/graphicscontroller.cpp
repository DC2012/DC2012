#include "graphicscontroller.h"

#include <QMessageBox>

GraphicsController::GraphicsController(QObject *parent) :
    QObject(parent)
{

}

void GraphicsController::addMessage(Message *message)
{
    mutex_.lock();
    messageQueue_.push(message);
    mutex_.unlock();
}
