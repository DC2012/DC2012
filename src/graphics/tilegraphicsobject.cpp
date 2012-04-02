#include "tilegraphicsobject.h"

TileGraphicsObject::TileGraphicsObject(const Point& initialPosition, GameObject *gameObject, int type)
    : GraphicsObject(initialPosition, gameObject)
{
    QPixmap tile;

    if (type == SEA_TILE)
        tile.load(TILE_WATER2);
    else if (type == LAND_TILE)
        tile.load(TILE_LAND1);

    GraphicsObject::setPixmapItem(tile);
}
