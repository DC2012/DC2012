#ifndef SEATILE_H
#define SEATILE_H

#include "tile.h"



#define     SEA     O
#define     LAND    1

class SeaTile : public Tile
{
    public:
        SeaTile();

    private:
        int     type_;
        Point   position_;
};

#endif // SEATILE_H
