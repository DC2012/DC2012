#ifndef SHIPGRAPHICSOBJECT_H
#define SHIPGRAPHICSOBJECT_H

#include <QGraphicsPixmapItem>
#include "graphicsobject.h"

class ShipGraphicsObject
{
public:
    ShipGraphicsObject(int type, Point position);
    void draw();
    QGraphicsPixmapItem* getPixmapItem();
private:
    QGraphicsPixmapItem* currentPixmapItem_;
    QPixmap pixmapArray[];
    int type_;
    int pixmapIndex_;
    int animateState_;
    int previousState_;
    int animateCounter_;
    int speed_;
    Point position_;
    void update();
    void animate(int flag);
    void initGraphics();
};

#endif // SHIPGRAPHICSOBJECT_H
