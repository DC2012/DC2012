#ifndef SHIPGRAPHICSOBJECT_H
#define SHIPGRAPHICSOBJECT_H

#include "graphicsobject.h"

class ShipGraphicsObject : public GraphicsObject
{
public:
    ShipGraphicsObject(GameObject* gameObject);
    GOM_Ship *shipObj;
    //void draw();
    //QGraphicsPixmapItem* getPixmapItem();
private:
    //QGraphicsPixmapItem* currentPixmapItem_;
    //QPixmap pixmapArray[];
    //int type_;
    //int pixmapIndex_;
    //int animateState_;
    //int previousState_;
    //int animateCounter_;
    //int speed_;
    //Point position_;
    //void update();
    //void animate(int flag);
    //void initGraphics();
};

#endif // SHIPGRAPHICSOBJECT_H
