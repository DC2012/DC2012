#include "messagereadworker.h"
#include "../net/client.h"

MessageReadWorker::MessageReadWorker(QObject *parent) :
    QObject(parent)
{

}

void MessageReadWorker::readMessages()
{
    Client* client = Client::getInstance();
    Message *msg;

    Message mes(1);
    mes.setData("hello");
    mes.setAll("hello", Message::CREATION);
    emit messageReceived(&mes);

    while((msg = client->read()))
        emit messageReceived(msg);
}
