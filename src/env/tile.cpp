#include "tile.h"

Tile::Tile(QPixmap sprite, Point position) : QGraphicsPixmapItem(sprite)
{
        position_ = position;
        setOffset(position.getX(), position.getY());
}
