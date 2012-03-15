#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class GameWindow : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    QGraphicsScene *scene_;

    // this will be removed later, just for testing until the proper
    // graphic object interfaces are implemented
    QGraphicsPixmapItem *ship_;

    void keyPressEvent(QKeyEvent *event);
    
};

#endif // GAMEWINDOW_H
