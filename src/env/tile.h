#ifndef TILE_H
#define TILE_H

#include "Point.h"

class Tile
{
public:
    Tile();

    virtual int     getTileType();
    virtual void    setPosition(int x, int y);
    virtual Point   getPosition();
};

#endif // TILE_H
