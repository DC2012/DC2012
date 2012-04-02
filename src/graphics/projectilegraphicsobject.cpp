#include "projectilegraphicsobject.h"

ProjectileGraphicsObject::ProjectileGraphicsObject(const Point& initialPoint, GameObject* gameObject)
    : GraphicsObject(initialPoint, gameObject)
{
    GraphicsObject::setPixmapItem(QPixmap(SPRITE_BULLET));
}


