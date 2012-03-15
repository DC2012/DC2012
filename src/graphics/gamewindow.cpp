#include "gamewindow.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMessageBox>

GameWindow::GameWindow(QWidget *parent) :
    QGraphicsView(parent)
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0, 0, 700, 500);
    setScene(scene_);

    // these pixmap objects will be replaced by proper
    // game objects once the implementation is complete
    QPixmap ship("../../sprites/spriteShip1.png");
    ship_ = new QGraphicsPixmapItem(ship);
    ship_->setPos(20, 20);
    scene_->addItem(ship_);
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
        ship_->setOffset(ship_->offset().x(), ship_->offset().y() - 1);
        break;
    case Qt::Key_A:
        ship_->setOffset(ship_->offset().x() - 1, ship_->offset().y());
        break;
    case Qt::Key_S:
        ship_->setOffset(ship_->offset().x(), ship_->offset().y() + 1);
        break;
    case Qt::Key_D:
        ship_->setOffset(ship_->offset().x() + 1, ship_->offset().y());
        break;
    case Qt::Key_Space:
        QMessageBox::information(this, "Fire!", "Assume that a bullet was fired.");
        break;
    }
}
