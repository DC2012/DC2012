#include "shipgraphicsobject.h"

#define M_PI 3.14159265358979323846
#define DEG_CIRCLE 360
#define DEG_TO_RAD (M_PI / (DEG_CIRCLE / 2))
#define RAD_TO_DEG ((DEG_CIRCLE / 2) / M_PI)

ShipGraphicsObject::ShipGraphicsObject(GameObject* gameObject)
    : GraphicsObject(gameObject), canShoot_(true), pixmapSwitchTimer_(this)
{
    QPixmap shipPixmap;
    ObjectType type = gameObject->getType();

    if (type == SHIP1)
        shipPixmap.load(SPRITE_SHIP1);
    else if (type == SHIP2)
        shipPixmap.load(SPRITE_SHIP2);

    ShipGraphicsObject::ex1 = new QPixmap(SPRITE_EXPLOSION1);
    ShipGraphicsObject::ex2 = new QPixmap(SPRITE_EXPLOSION2);
    ShipGraphicsObject::ex3 = new QPixmap(SPRITE_EXPLOSION3);
    ShipGraphicsObject::ex4 = new QPixmap(SPRITE_EXPLOSION4);
    ShipGraphicsObject::ex5 = new QPixmap(SPRITE_EXPLOSION5);
    ShipGraphicsObject::ex6 = new QPixmap(SPRITE_EXPLOSION6);
    ShipGraphicsObject::ex7 = new QPixmap(SPRITE_EXPLOSION7);
    ShipGraphicsObject::ex8 = new QPixmap(SPRITE_EXPLOSION8);

    //Load the list of explosion pictures
    exAnim.push_back(ex1);
    exAnim.push_back(ex2);
    exAnim.push_back(ex3);
    exAnim.push_back(ex4);
    exAnim.push_back(ex5);
    exAnim.push_back(ex6);
    exAnim.push_back(ex7);
    exAnim.push_back(ex8);
    curPic = exAnim.begin();

    QGraphicsPixmapItem* shipItem = new QGraphicsPixmapItem(shipPixmap);

    shipItem->setOffset(gameObject->getSpriteTopLeft().getX(),
                        gameObject->getSpriteTopLeft().getY());

    shipItem->setTransformOriginPoint(gameObject->getPosition().getX(),
                                      gameObject->getPosition().getY());

    shipItem->setRotation(gameObject->getDegree() - 270);

    GraphicsObject::setPixmapItem(shipItem);
}

ShipGraphicsObject::~ShipGraphicsObject()
{
    delete ex1;
    delete ex2;
    delete ex3;
    delete ex4;
    delete ex5;
    delete ex6;
    delete ex7;
    delete ex8;
}

void ShipGraphicsObject::update(const std::string& data)
{
    GraphicsObject::update(data);
    GameObject* gameObject = getGameObject();
    QGraphicsPixmapItem* pixmap = getPixmapItem();

    pixmap->setOffset(gameObject->getSpriteTopLeft().getX(),
                      gameObject->getSpriteTopLeft().getY());

    pixmap->setTransformOriginPoint(gameObject->getPosition().getX(),
                                    gameObject->getPosition().getY());

    pixmap->setRotation(gameObject->getDegree() - 270);
}

void ShipGraphicsObject::setCanShoot()
{
    canShoot_ = true;
}

double ShipGraphicsObject::shoot(QPoint clickPos)
{
    if (!canShoot_)
        return -1;

    double h, angle, x, y;
    GameObject* gameObject = getGameObject();

    //Move the click point to 0,0 according to the ship position
    x = clickPos.x() - gameObject->getPosition().getX();
    y = clickPos.y() - gameObject->getPosition().getY();

    angle = 0;
    h = sqrt((x * x) + (y * y));

    //If bullet is being shot directly below the ship
    if(x == 0 && y > 0)
    {
        angle = 90;
    }

    //If bullet is being shot directly above the ship
    if(x == 0 && y < 0)
    {
        angle = 270;
    }

    //If bullet is being shot directly to the right of the ship
    if(x > 0 && y == 0)
    {
        angle = 0;
    }

    //If bullet is being shot directly to the left of the ship
    if(x < 0 && y == 0)
    {
        angle = 180;
    }

    //If bullet is being shot to the bottom right of the ship
    if(x > 0 && y > 0)
    {
        //any trig function
        angle = atan(y / x);
        angle *= RAD_TO_DEG;
    }

    //If bullet is being shot to the bottom left of the ship
    if(x < 0 && y > 0)
    {
        //cos trig function
        angle = acos(x / h);
        angle *= RAD_TO_DEG;
    }

    //If the bullet is being shot to the top left of the ship
    if(x < 0 && y < 0)
    {
        //tan trig function
        angle = atan(y / x);
        angle *= RAD_TO_DEG;
        angle += 180;
    }

    //If the bullet is being shot to the top right of the ship
    if(x > 0 && y < 0)
    {
        //sin trig function
        angle = asin(y / h);
        angle *= RAD_TO_DEG;
        angle += 360;
    }

    canShoot_ = false;
    return angle;
}

bool ShipGraphicsObject::canShoot()
{
    return canShoot_;
}

void ShipGraphicsObject::gotHit(GameObject* hitter)
{
    QGraphicsPixmapItem* pixmapItem;

    switch(hitter->getType())
    {
    case PROJECTILE:
        if(!((GOM_Ship*)this->getGameObject())->takeDamage(((GOM_Projectile*)hitter)->getDamage()))
        {
            emit death();
        }
        pixmapItem = getPixmapItem();
        pixmapItem->setPixmap(QPixmap(SPRITE_SHIP1_HIT));
        pixmapSwitchTimer_.start(100);
        connect(&pixmapSwitchTimer_, SIGNAL(timeout()), this, SLOT(explode()));
        break;
    case POWERUP:
        //get powerup
        //((GOM_Ship*)this->getGameObject())->applyPowerUp(((GOS_PowerUp*)hitter)->getBonus());
        break;

    }
}

void ShipGraphicsObject::explode()
{
    QGraphicsPixmapItem* pixmapItem = getPixmapItem();
    pixmapItem->setPixmap(**curPic);
    if(++curPic == exAnim.end())
    {
        pixmapSwitchTimer_.stop();
        delete this; //done explosion animation
    }
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
