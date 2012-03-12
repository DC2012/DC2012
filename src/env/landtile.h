#ifndef LANDTILE_H
#define LANDTILE_H

#include "tile.h"

class LandTile : public Tile
{
    public:
        LandTile();
        LandTile(Point point);

    private:
        int                 type_;
        Point               position_;
        TileGraphicObject   graphic_;
};

#endif // LANDTILE_H
