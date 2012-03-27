#include "projectilegraphicsobject.h"

ProjectileGraphicsObject::ProjectileGraphicsObject(const Point& initialPoint)
    : GraphicsObject(initialPoint)
{
    ProjectileGraphicsObject::setPixmapItem(QPixmap(SPRITE_BULLET));
}


