#include "projectilegraphicsobject.h"

ProjectileGraphicsObject::ProjectileGraphicsObject(GameObject* gameObject)
    : GraphicsObject(gameObject)
{
    GraphicsObject::setPixmapItem(new QGraphicsPixmapItem(QPixmap(SPRITE_BULLET)));
}

void ProjectileGraphicsObject::update(const std::string &data)
{
    GraphicsObject::update(data);
    GameObject* gameObject = getGameObject();
    QGraphicsPixmapItem* pixmap = getPixmapItem();


}

