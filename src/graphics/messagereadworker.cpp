#include "messagereadworker.h"
#include "MessageWrapper.h"
#include "../net/client.h"

MessageReadWorker::MessageReadWorker(QObject *parent) :
    QObject(parent)
{

}

void MessageReadWorker::readMessages()
{
    Client* client = Client::getInstance();
    Message *msg;

    while((msg = client->read()))
    {
        emit messageReceived(new MessageWrapper(msg));
    }
}
