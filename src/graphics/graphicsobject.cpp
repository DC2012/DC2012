#include "graphicsobject.h"

GraphicsObject::GraphicsObject(const Point &initialPos, GameObject* gameObject)
    : pos_(initialPos), gameObject_(gameObject)
{

}

GameObject* GraphicsObject::getGameObject()
{
    return gameObject_;
}

void GraphicsObject::update(const std::string& data)
{
    gameObject_->update(data);

    Point pos = gameObject_->getPosition();
    pixmapItem_->setOffset(pixmapItem_->offset().x() + pos.getX(),
                           pixmapItem_->offset().y() + pos.getY());

    // other stuff to update the object position
}

void GraphicsObject::setPixmapItem(const QPixmap &pixmap)
{
    pixmapItem_ = new QGraphicsPixmapItem(pixmap);
}

QGraphicsPixmapItem* GraphicsObject::getPixmapItem() const
{
    return pixmapItem_;
}
