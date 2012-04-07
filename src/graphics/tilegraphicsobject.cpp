#include "tilegraphicsobject.h"

TileGraphicsObject::TileGraphicsObject(GameObject *gameObject)
    : GraphicsObject(gameObject)
{
    QPixmap tile;

    if (gameObject->getType() == SEA_TILE)
        tile.load(TILE_WATER2);
    else if (gameObject->getType() == LAND_TILE)
        tile.load(TILE_LAND1);

    GraphicsObject::setPixmapItem(new QGraphicsPixmapItem(tile));
}
