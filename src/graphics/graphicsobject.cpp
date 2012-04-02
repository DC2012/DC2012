#include "graphicsobject.h"

GraphicsObject::GraphicsObject(const Point &initialPos, GameObject* gameObject)
    : pos_(initialPos), gameObject_(gameObject)
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
