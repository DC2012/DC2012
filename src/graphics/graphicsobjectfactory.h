#ifndef GRAPHICSOBJECTFACTORY_H
#define GRAPHICSOBJECTFACTORY_H

#include "graphicsobject.h"
#include "projectilegraphicsobject.h"
#include "shipgraphicsobject.h"
#include "tilegraphicsobject.h"
#include "../player/ObjectType.h"

class GraphicsObjectFactory
{
public:
    static GraphicsObject* create(GameObject* gameObject)
    {
        if (gameObject->getType() == PROJECTILE)
        {
            return new ProjectileGraphicsObject(gameObject->getPosition(), gameObject);
        }
        else if (gameObject->getType() == SHIP1 || gameObject->getType() == SHIP2)
        {
            return new ShipGraphicsObject(gameObject->getPosition(), gameObject, gameObject->getType());
        }
        else if (gameObject->getType() == OBSTACLE)
        {
            return new TileGraphicsObject(gameObject->getPosition(), gameObject, gameObject->getType());
        }
        else
        {
            return NULL;
        }
    }
};

#endif // GRAPHICSOBJECTFACTORY_H
