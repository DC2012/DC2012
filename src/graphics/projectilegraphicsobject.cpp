#include "projectilegraphicsobject.h"

ProjectileGraphicsObject::ProjectileGraphicsObject(GameObject* gameObject)
    : GraphicsObject(gameObject)
{
    QGraphicsPixmapItem* projectile = new QGraphicsPixmapItem(QPixmap(SPRITE_BULLET));

    projectile->setOffset(gameObject->getSpriteTopLeft().getX(),
                          gameObject->getSpriteTopLeft().getY());

    GraphicsObject::setPixmapItem(projectile);
}

void ProjectileGraphicsObject::update(const std::string &data)
{
    GameObject* gameObject = getGameObject();
    QGraphicsPixmapItem* pixmap = getPixmapItem();

    pixmap->setOffset(pixmap->offset().x() + 1, pixmap->offset().y() + 1);
}

