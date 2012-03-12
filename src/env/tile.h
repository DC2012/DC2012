#ifndef TILE_H
#define TILE_H

#include "../../../player/Point.h"
#include "TileGraphicObject.h"


#define     SEA     O
#define     LAND    1

class Tile
{
    public:
        Tile();
        Tile(Point point);
        virtual int getTileType();
        virtual void setPosition(int x, int y);
        virtual Point getPosition();
        virtual void setGraphic(int type_, Point position_);
};

#endif // TILE_H
