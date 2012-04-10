#ifndef TILE_H
#define TILE_H

#include "../player/Point.h"
#include "../graphics/tilegraphicsobject.h"

#define     SEA     0
#define     LAND    1

class Tile
{
    public:
        Tile(Point position);
        //virtual int getTileType();
        //virtual void setPosition(int x, int y);
        //virtual Point getPosition();
        //virtual void setGraphic();

    private:
        //int                 type_;
        Point               position_;

    protected:
        //TileGraphicsObject  *graphic_;
};

#endif // TILE_H
