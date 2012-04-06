#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include <QObject>
#include <QMutex>
#include <QGraphicsScene>

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
    void addMessage(int clientId, QString message, Message::MessageType type);
    
private:
    QGraphicsScene* scene_;
    std::queue<Message> messageQueue_;
    std::map<int, GraphicsObject *> ships_;
    std::map<int, GraphicsObject *> otherGraphics_;
    QMutex mutex_;
    int clientId_;

    void processGameMessage(Message message);

};

#endif // GRAPHICSCONTROLLER_H
