#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "../player/GOM_Ship.h"
#include "../net/client.h"
#include "MessageWrapper.h"
#include "graphicsobject.h"
#include "shipgraphicsobject.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <QMutex>
#include "../../src/env/chat/ChatDlg.h"

class GameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    void start();
    void setChatting(bool b);
    bool isChatting();
    
signals:
    
public slots:
    void updateGame();
    void addMessage(MessageWrapper* msgwrap);

private:
    static const int FRAME_RATE = 40;
    static const int CLIENT_WIDTH = 1024;
    static const int CLIENT_HEIGHT = 768;
    
    QGraphicsScene *scene_;
    QTimer timer_;
    GOM_Ship* myShip_;
    ShipGraphicsObject* myShipGraphic_;
    Client* client_;
    std::queue<Message *> messageQueue_;
    std::map<int, ShipGraphicsObject *> ships_;
    std::map<int, GraphicsObject *> otherGraphics_;
    QMutex mutex_;
    int clientId_;
    size_t timerCounter_;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void processGameMessage(Message* message);
    void processMessages();
    
    //GraphicsController gcontroller_;
    //qreal currentScale_;

    // env chat message box
    ChatDlg *chatdlg_;
    bool isChatting_;
};

#endif // GAMEWINDOW_H
