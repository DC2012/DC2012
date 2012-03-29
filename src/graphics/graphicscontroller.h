#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include <QObject>
#include <QMutex>

#include <queue>
#include <map>
#include "../net/Message.h"
#include "../player/GameObject.h"

class GraphicsController : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsController(QObject *parent = 0);
    void processMessages();
    
signals:
    
public slots:
    void addMessage(Message* message);
    
private:
    std::queue<Message *> messageQueue_;
    std::map<int, GameObject *> gameObjects_;
    QMutex mutex_;

    void processGameMessage(Message *msg);

};

#endif // GRAPHICSCONTROLLER_H
