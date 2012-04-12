#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "../env/gamemap.h"
#include "../player/GOM_Ship.h"
#include "../net/client.h"
#include "MessageWrapper.h"
#include "graphicsobject.h"
#include "shipgraphicsobject.h"
#include "projectilegraphicsobject.h"
#include "audiocontroller.h"
#include "../player/Point.h"
#include "../env/menus/Ships/pickyourship.h"

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

    enum shipState
    {
        ALIVE,
        DYING,
        DEAD
    };
    
signals:
    void shotFired(AudioController::Sounds, double);
    void shipExplode(AudioController::Sounds, double);
    
public slots:
    void updateGame();
    void addMessage(MessageWrapper* msgwrap);
    void death();

private:
    static const int FRAME_RATE = 40;
    static const int CLIENT_WIDTH = 1024;
    static const int CLIENT_HEIGHT = 768;

    QGraphicsScene *scene_;
    Point curPos;
    QTimer timer_;
    Client* client_;
    GameMap* map_;
    std::queue<Message *> messageQueue_;
    std::map<int, ShipGraphicsObject *> ships_;
    std::map<int, ProjectileGraphicsObject *> otherGraphics_;
    QMutex mutex_;
    int clientId_;
    size_t timerCounter_;
    AudioController audio;
    bool isClientDead_;
    PickYourShip shipChooser;
    shipState state_;
	bool connected_;

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
