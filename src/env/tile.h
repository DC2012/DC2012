#ifndef TILE_H
#define TILE_H

#include "../player/Point.h"
#include "../graphics/tilegraphicsobject.h"
#include "../../sprites/sprites.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>

#define     SEA     0
#define     LAND    1

class Tile : public QGraphicsPixmapItem
{
    public:
        Tile(QPixmap sprite, Point position, int type);
        int getTileType();
        //virtual void setPosition(int x, int y);
        //virtual Point getPosition();
        //virtual void setGrahic();

    private:
        int                 type_;
        Point               position_;

    protected:
        //TileGraphicsObject  *graphic_;
};

#endif // TILE_H
