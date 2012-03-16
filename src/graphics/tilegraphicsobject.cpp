#include "tilegraphicsobject.h"

TileGraphicsObject::TileGraphicsObject(int type, Point position)
{
    position_ = position;
    type_ = type;
    draw(type_, position_);
}

void initGraphics() {
// initialize pixmapArray[]
}

void TileGraphicsObject::draw(int type, Point pos) {
    if (type == SEA_TILE) {
        currentPixmapItem_ = new QGraphicsPixmapItem(QPixmap(TILE_WATER1, 0, 0));
    } else if (type == LAND_TILE) {
        currentPixmapItem_ = new QGraphicsPixmapItem(QPixmap(TILE_LAND1, 0, 0));
    } else {
    // error
    }
}

QGraphicsPixmapItem * TileGraphicsObject::getPixmapItem() {
    return currentPixmapItem_;
}
