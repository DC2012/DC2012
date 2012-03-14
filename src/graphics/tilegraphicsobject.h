#ifndef TILEGRAPHICSOBJECT_H
#define TILEGRAPHICSOBJECT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "graphicsobject.h"
#include "sprites.h"

#define SEA_TILE    0
#define LAND_TILE   1

class TileGraphicsObject
{
public:
    TileGraphicsObject(int type, Position position);
    void draw(GameObject* obj);
    QGraphicsPixmapItem getPixmapItem();
private:
    ~TileGraphicsObject();
    QGraphicsPixmapItem* currentPixmapItem_;
    QPixmap pixmapArray[];
    int type_;
    Point position_;
};

#endif // TILEGRAPHICSOBJECT_H
