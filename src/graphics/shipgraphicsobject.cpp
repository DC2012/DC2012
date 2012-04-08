#include "shipgraphicsobject.h"

ShipGraphicsObject::ShipGraphicsObject(GameObject* gameObject)
    : GraphicsObject(gameObject)
{
    QPixmap shipPixmap;
    ObjectType type = gameObject->getType();
    shipObj = (GOM_Ship*)gameOjbect;

    if (type == SHIP1)
        shipPixmap.load(SPRITE_SHIP1);
    else if (type == SHIP2)
        shipPixmap.load(SPRITE_SHIP2);

    QGraphicsPixmapItem* shipItem = new QGraphicsPixmapItem(shipPixmap);
    shipItem->setPos(gameObject->getSpriteTopLeft().getX(),
                    gameObject->getSpriteTopLeft().getY());

    GraphicsObject::setPixmapItem(shipItem);
}

/*
    ShipGraphicsObject::ShipGraphicsObject(int type, Point position)
    {
        type_ = type;
        position_ = position;
        pixmapIndex_  = 0;
        speed_ = 0;
        animateState_ = NO_ANIMATION;
        previousState_ = NO_ANIMATION;
        initGraphics();
    }

//  This method is going to go through and initialize the pixmap array.
//  Going to need to be hard set once we have all the animation frames.
//  For now we'll just need a basic set of images.

    initGraphics() {
       pixmapArray[0] = new QPixmap(new SPRITE_SHIP1);
       pixmapArray[1] = new QPixmap(new SPRITE_SHIP1_MOVE1);
       pixmapArray[2] = new QPixmap(new SPRITE_SHIP1_MOVE2);
       pixmapArray[3] = new QPixmap(new SPRITE_SHIP1_MOVE3);
       pixmapArray[4] = new QPixmap(new SPRITE_SHIP1_HIT);
       // etc etc with the proper names.
    }

//  This method requires a GameObject to be passed to it.

    void ShipGraphicsObject::draw() {
        update();
    }

//  Gets all the object's info. These methods need to be provided by
//  the team creating the objects.

    void ShipGraphicsObject::update() {
        //position_ = obj->getPosition();
        //type_ = obj->getType();
        //speed_ = obj-> getSpeed();
        if(speed_ > 0) {
            animateState_ = ANIMATE_MOVING;
        }
        animate(animateState_);
    }

    void ShipGraphicsObject::animate(int flag) {
        switch(flag) {
        case 0:
            return;
        case 1:
            break;
        }
        previousState_ = flag;
    }

 // This method will return the current pixmap item so that it can be added to the scene.

    QGraphicsPixmapItem* ShipGraphicsObject::getPixmapItem() {
        return currentPixmapItem_;
    }
*/
