#ifndef TILEGRAPHICSOBJECT_H
#define TILEGRAPHICSOBJECT_H

#include "graphicsobject.h"

#define SEA_TILE    0
#define LAND_TILE   1

class TileGraphicsObject : public GraphicsObject
{
public:
    TileGraphicsObject(const Point& initialPoint, int type);
};

#endif // TILEGRAPHICSOBJECT_H
