#include "tilegraphicsobject.h"

TileGraphicsObject::TileGraphicsObject(int type, Position position)
{
    position_ = position;
    type_ = type;
    draw(type_), positon_;
}

void initGraphics() {
// initialize pixmapArray[]
}

void draw(int type, Position pos) {
    if (type == SEA_TILE) {
        currentPixmapItem_ = new QPixmapItem(new QPixmap(new TILE_WATER1));
    } else if (type == LAND_TILE) {
        currentPixmapItem_ = new QPixmapItem(new QPixmap(new TILE_LAND1));
    } else {
    // error
    }
}

QGraphicsPixmapItem* getPixmapItem() {
    return currentPixmapitem_;
}
