#include "landtile.h"

LandTile::LandTile()
{
    type_ = LAND;
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
