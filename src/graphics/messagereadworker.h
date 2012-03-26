#ifndef MESSAGEREADWORKER_H
#define MESSAGEREADWORKER_H

#include <QObject>
#include "../net/Message.h"

class MessageReadWorker : public QObject
{
    Q_OBJECT
public:
    explicit MessageReadWorker(QObject *parent = 0);
    
signals:
    void messageReceived(Message* message);
    
public slots:
    void readMessages();
    
};

#endif // MESSAGEREADWORKER_H
