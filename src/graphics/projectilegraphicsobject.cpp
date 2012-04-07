#include "projectilegraphicsobject.h"

ProjectileGraphicsObject::ProjectileGraphicsObject(GameObject* gameObject)
    : GraphicsObject(gameObject)
{
    GraphicsObject::setPixmapItem(new QGraphicsPixmapItem(QPixmap(SPRITE_BULLET)));
}


