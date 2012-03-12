#include "shipgraphicsobject.h"

class ShipGraphicsObject : public GraphicsObject {

    ShipGraphicsObject::ShipGraphicsObject(int type, Point position)
    {
        type_ = type;
        position_ = position;
        pixmapIndex_  = 0;
        speed_ = 0;
        animateState_ = NO_ANIMATION;
        previousState = NO_ANIMATION;

    }

    ~ShipGraphicsObject() {

    }

    initGraphics() {
        int counter;
        for (counter = 0; counter < numOfPixmaps; counter++) {

        }
    }

    void draw(GameObject* obj) {
        update(obj);

    }

    void update(GameObject* obj) {
        position_ = obj->getPosition();
        type_ = obj->getType();
        speed_ = obj-> getSpeed();
        if(speed > 0) {
            animateState_ = ANIMATE_MOVING;
        }
        animate(animateState_);
    }

    void animate(int flag) {
        switch(flag) {
        case 0:
            return;
        }
        previousState_ = flag;
    }

    QGraphicsPixmapItem getPixmap() {
        return currentPixmapItem_;
    }
}
