#ifndef SHIPGRAPHICSOBJECT_H
#define SHIPGRAPHICSOBJECT_H

#include <QGraphicsPixmapItem>
#include "graphicsobject.h"

class ShipGraphicsObject
{
public:
    ShipGraphicsObject();
    void draw(GameObject* obj);
    QGraphicsPixmapItem getPixmapItem();
private:
    ~ShipGraphicsObject();
    QGraphicsPixmapItem* currentPixmapItem_;
    QPixmap pixmapArray[];
    int type_;
    int pixmapIndex_;
    int animateState_;
    int previousState_;
    int speed_;
    Point position_;
    void update(GameObject* obj);
    void animate(int flag);
};

#endif // SHIPGRAPHICSOBJECT_H
