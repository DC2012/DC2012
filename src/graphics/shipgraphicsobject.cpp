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
        initGraphics();
    }

    ~ShipGraphicsObject() {

    }
/**
  This method is going to go through and initialize the pixmap array.
  Going to need to be hard set once we have all the animation frames.
  For now we'll just need a basic set of images.
  */
    initGraphics() {
       //pixmapArray[0] = Ship image one
       // etc etc with the proper names.
    }
/**
  This method requires a GameObject to be passed to it.
  */
    void draw(GameObject* obj) {
        update(obj);

    }
/**
<<<<<<< HEAD
  Gets all the object's information
=======
  Gets all the object's info. These methods need to be provided by
  the team creating the objects.
>>>>>>> 9094163dbc18e55838ccfd5443a5922597374f49
  */
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
        case 1:
            for(animateCounter = 0; animateCounter < 4; animateCounter++) {
                pixmapIndex
            }
            break;
        previousState_ = flag;
    }
/**
  This method will return the current pixmap item so that it can be added to the scene.
  */
    QGraphicsPixmapItem getPixmapItem() {
        return currentPixmapItem_;
    }
}
