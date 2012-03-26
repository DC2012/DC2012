#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include <QObject>
#include <QMutex>

#include <queue>
#include "../net/Message.h"

class GraphicsController : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsController(QObject *parent = 0);
    
signals:
    
public slots:
    void addMessage(Message* message);
    
private:
    std::queue<Message *> messageQueue_;
    QMutex mutex_;

};

#endif // GRAPHICSCONTROLLER_H
