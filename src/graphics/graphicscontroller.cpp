#include "graphicscontroller.h"

GraphicsController::GraphicsController(QGraphicsScene *scene, QObject *parent) :
    QObject(parent), scene_(scene)
{

}

void QGraphicsController::addGraphic(const GraphicsObject *graphic)
{
    scene->addItem(graphic->getPixmapItem());
}

void QGraphicsController::removeGraphic(const GraphicsObject *graphic)
{
    scene->removeItem(graphic->getPixmapItem());
}
