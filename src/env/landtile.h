#ifndef LANDTILE_H
#define LANDTILE_H

#include "tile.h"

class LandTile : public Tile
{
    public:
        LandTile();

    private:
        int     type;
        Point   position_;
};

#endif // LANDTILE_H
