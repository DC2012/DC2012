#include "seatile.h"

SeaTile::SeaTile()
{
    type_ = SEA;
}

Tile :: getTileType
{
    return type_;
}

Tile ::setPosition(int x, int y)
{
    position_ = new Point(x, y);
}

Tile ::getPosition()
{
    return position_;
}


