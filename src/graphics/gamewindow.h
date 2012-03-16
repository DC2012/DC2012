#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

class GameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    void start();
    
signals:
    
public slots:
    void updateGame();

private:
    static const int FRAME_RATE = 40;
    static const int CLIENT_WIDTH = 1024;
    static const int CLIENT_HEIGHT = 768;

    QGraphicsScene *scene_;
    QTimer timer_;

    // this will be removed later, just for testing until the proper
    // graphic object interfaces are implemented
    QGraphicsPixmapItem *ship_;

    void keyPressEvent(QKeyEvent *event);
};

#endif // GAMEWINDOW_H
