#include "graphicscontroller.h"

GraphicsController::GraphicsController(QWidget *parent) :
    QGraphicsView(parent)
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    scene_ = new QGraphicsScene();
    setScene(scene_);

    scene_->setSceneRect(0, 0, 700, 500);
}

void GraphicsController::addGraphic(const GraphicsObject *graphic) const
{
    scene_->addItem(graphic->getPixmapItem());
}

void GraphicsController::removeGraphic(const GraphicsObject *graphic) const
{
    scene_->removeItem(graphic->getPixmapItem());
}
