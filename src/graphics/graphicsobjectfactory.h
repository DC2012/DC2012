#ifndef GRAPHICSOBJECTFACTORY_H
#define GRAPHICSOBJECTFACTORY_H

#include "graphicsobject.h"
#include "projectilegraphicsobject.h"
#include "shipgraphicsobject.h"
#include "tilegraphicsobject.h"

class GraphicsObjectFactory
{
    static GraphicsObject* create(const std::string& objectType, GameObject* gameObject)
    {
        QString type = QString::fromStdString(objectType);
        QStringList tokens = type.split(" ");

        Point initial(tokens.at(1).toDouble(), tokens.at(2).toDouble());

        if (tokens.at(0) == "P")
        {
            return new ProjectileGraphicsObject(initial, gameObject);
        }
        else if (tokens.at(0) == "S")
        {
            return new ShipGraphicsObject(initial, gameObject, tokens.at(3).toInt());
        }
        else if (tokens.at(0) == "T")
        {
            return new TileGraphicsObject(initial, gameObject, tokens.at(3).toInt());
        }
        else
        {
            return NULL;
        }
    }
};

#endif // GRAPHICSOBJECTFACTORY_H
