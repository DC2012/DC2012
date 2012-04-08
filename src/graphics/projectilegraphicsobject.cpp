#include "projectilegraphicsobject.h"
#include "../player/GOM_Projectile.h"

ProjectileGraphicsObject::ProjectileGraphicsObject(GameObject* gameObject)
    : GraphicsObject(gameObject), expired_(false)
{
    QGraphicsPixmapItem* projectile = new QGraphicsPixmapItem(QPixmap(SPRITE_CANNONBALL));

    projectile->setOffset(gameObject->getSpriteTopLeft().getX(),
                          gameObject->getSpriteTopLeft().getY());

    GraphicsObject::setPixmapItem(projectile);
}

void ProjectileGraphicsObject::update(const std::string &data)
{
    GOM_Projectile* projectile = (GOM_Projectile *) getGameObject();
    QGraphicsPixmapItem* pixmap = getPixmapItem();

    expired_ = projectile->move();
    pixmap->setOffset(projectile->getPosition().getX(), projectile->getPosition().getY());
}

bool ProjectileGraphicsObject::isExpired()
{
    return expired_;
}

