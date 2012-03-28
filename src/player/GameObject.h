/*-----------------------------------------------------------------------------
--  CLASS NAME:
--                  GameObject
--  CONSTRUCTOR:
--                  GameObject(int objID, ObjectType type, double degree,
--                                                  double posX, double posY)
--  DESTROCTOR:
--                  ~GameObject()
--  FUNCTIONS:
--                  public:
--                      int    getObjID()    const;
--                      int    getType()     const;
--                      double getDegree()   const;
--                      Point  getPosition() const;
--        
--                      double getObjDistance(const GameObject &gObj) const;
--                      virtual void print(std::ostream& os) const;
--
--    DATE:
--                    March 9, 2012
--    REVISIONS:
--                    March 14, 2012 (Roger)
--                        - switched to using double type in Point & Degree
--
--    DESIGNER:
--                    Aiko Rose
--                    Po Hsu
--                    Roger Fan
--                    Zach Smoroden
--    PROGRAMMER:        
--                    Aiko Rose
--                    Po Hsu
--                    Roger Fan
--                    Zach Smoroden
--    NOTES:
--                    This is the abstract base class of all other classes that
--                      will appear on the screen.
--
--                    Classes inheriting from this:
--                                                  GameObjectMoveable
--                                                  GameObjectStationary
--                    
-----------------------------------------------------------------------------*/
#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "ObjectType.h"
#include "Point.h"
#include "Degree.h"
#include "Hitbox.h"
#include "../../sprites/sprites.h"
#include <iostream>

class GameObject
{
    protected:
        int         objID_;
        ObjectType  type_;
        Degree      degree_;
        Point       pos_;
        Point       spritePt_;
        Hitbox      hb_;

    public:
        // constructor
        // explicit to indicate no implicit conversion
        explicit GameObject(int objID, ObjectType type, double degree, double posX, double posY);

        // default destructor
        virtual ~GameObject(){}

        // getters
        int getObjID() const;
        int getType() const;
        double getDegree() const;
        Point getPosition() const;
        
        // returns distance between current GameObject and the GameObject passed in
        double getObjDistance(const GameObject &gObj) const;

        // for testing purposes
        virtual void print(std::ostream& os) const;
};

#endif
