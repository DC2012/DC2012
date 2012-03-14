#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include "../player/GameObject.h"

#define NO_ANIMATION        0;
#define ANIMATE_MOVING      1;
#define ANIMATE_DESTRUCTION 2;

class GraphicsObject
{
public:
    GraphicsObject();
    virtual void draw(GameObject* obj);
    virtual QGraphicsPixmapItem getPixmapItem();
private:
    virtual ~GraphicsObject();
};

#endif // GRAPHICSOBJECT_H
