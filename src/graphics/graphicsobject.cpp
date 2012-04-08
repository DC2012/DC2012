#include "graphicsobject.h"

GraphicsObject::GraphicsObject(GameObject* gameObject)
    : gameObject_(gameObject)
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
    pixmapItem_->setOffset(gameObject_->getSpriteTopLeft().getX(),
                           gameObject_->getSpriteTopLeft().getY());

    pixmapItem_->setTransformOriginPoint(gameObject_->getPosition().getX(),
                                         gameObject_->getPosition().getY());

    pixmapItem_->setRotation(gameObject_->getDegree() - 270);
}

void GraphicsObject::setPixmapItem(QGraphicsPixmapItem* pixmap)
{
    pixmapItem_ = pixmap;
}

QGraphicsPixmapItem* GraphicsObject::getPixmapItem() const
{
    return pixmapItem_;
}
