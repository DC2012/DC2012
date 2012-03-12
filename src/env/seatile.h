#ifndef SEATILE_H
#define SEATILE_H

#include "tile.h"

class SeaTile : public Tile
{
    public:
        SeaTile();
        SeaTile(Point point);

    private:
        int                 type_;
        Point               position_;
        TileGraphicObject   graphic_;
};

#endif // SEATILE_H
