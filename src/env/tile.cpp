#include "tile.h"

Tile::Tile(const Point& position)
    : position_(position)
{

}

void Tile::setPosition(int x, int y)
{
    position_.setX(x);
    position_.setY(y);
}

Point Tile::getPosition()
{
    return position_;
}
