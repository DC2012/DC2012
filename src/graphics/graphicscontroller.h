#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include <QObject>
#include <QMutex>

#include <queue>
#include <map>
#include "../net/Message.h"
#include "../player/GameObject.h"
#include "../graphics/graphicsobject.h"

class GraphicsController : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsController(QGraphicsScene *scene, QObject *parent = 0);
    void processMessages();
    
signals:
    
public slots:
    void addMessage(Message* message);
    
private:
    QGraphicsScene* scene_;
    std::queue<Message *> messageQueue_;
    std::map<int, GraphicsObject *> graphicObjects_;
    QMutex mutex_;

    void processGameMessage(Message *msg);

};

#endif // GRAPHICSCONTROLLER_H
