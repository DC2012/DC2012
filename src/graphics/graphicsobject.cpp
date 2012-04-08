#include "graphicsobject.h"

GraphicsObject::GraphicsObject(GameObject* gameObject)
    : gameObject_(gameObject)
{

}

GameObject* GraphicsObject::getGameObject()
{
    return gameObject_;
}

void GraphicsObject::update(const std::string &data)
{
    gameObject_->update(data);
}

void GraphicsObject::setPixmapItem(QGraphicsPixmapItem* pixmap)
{
    pixmapItem_ = pixmap;
}

QGraphicsPixmapItem* GraphicsObject::getPixmapItem() const
{
    return pixmapItem_;
}
