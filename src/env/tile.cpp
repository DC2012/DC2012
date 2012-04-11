#include "tile.h"

Tile::Tile(QPixmap sprite, Point position, int type) : QGraphicsPixmapItem(sprite)
{
        type_ = type;
        position_ = position;
        setOffset(position.getX(), position.getY());
}

int Tile::getTileType()
{
    return type_;
}
