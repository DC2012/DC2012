#include "graphicsobject.h"

GraphicsObject::GraphicsObject(const Point &initialPos)
    : pos_(initialPos)
{

}

void GraphicsObject::setPixmapItem(const QPixmap &pixmap)
{
    pixmapItem_ = new QGraphicsPixmapItem(pixmap);
}

QGraphicsPixmapItem* GraphicsObject::getPixmapItem() const
{
    return pixmapItem_;
}
