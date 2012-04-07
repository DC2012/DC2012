#ifndef MESSAGEWRAPPER_H
#define MESSAGEWRAPPER_H

#include <QObject>
#include "../net/Message.h"

class MessageWrapper : public QObject
{
    Q_OBJECT

public:
    MessageWrapper(Message *msg, QObject *parent = 0) : QObject(parent), message(msg)
    {

    }

    Message* message;
};

#endif // MESSAGEWRAPPER_H
