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
--  DATE:
--                  March 9, 2012
--  REVISIONS:
--                  March 14, 2012 (Roger)
--                      - switched to using double type in Point & Degree
--
--  DESIGNER:
--                  Aiko Rose
--                  Po Hsu
--                  Roger Fan
--                  Zach Smoroden
--
--  PROGRAMMER:
--                  Aiko Rose
--                  Po Hsu
--                  Roger Fan
--                  Zach Smoroden
--  NOTES:
--                  This is the base class of all other classes that is going
--                    to appear on the screen.
--
--                  Classes inheriting from this:
--                                                GameObjectMoveable
--                                                GameObjectStationary
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
/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  Constructor
--
--  DATE:
--                  March 9, 2012
--
--  REVISIONS:
--                  March 14, 2012 (Roger)
--                      - switched to using double type in Point & Degree
--
--  DESIGNER:
--                  Aiko Rose
--                  Po Hsu
--                  Roger Fan
--                  Zach Smoroden
--
--  PROGRAMMER:
--                  Po Hsu
--                  Roger Fan
--
--  INTERFACE:
--                  GameObject(int objID, ObjectType type, double degree,
--                                                  double posX, double posY);
--
--  RETURNS:
--                  Constructor
--
--  NOTES:
--                  objID   Unique object ID
--                  type    Object type used by the graphics team
--                  degree  Initial orientation
--                  posX    X-coordinate
--                  posY    Y-coordinate
-----------------------------------------------------------------------------*/
        explicit GameObject(int objID, ObjectType type, double degree,
                                                    double posX, double posY);

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  Destructor
--
--  DATE:
--                  March 9, 2012
--
--  REVISIONS:
--
--  DESIGNER:
--                  Po Hsu
--
--  PROGRAMMER:
--                  Po Hsu
--
--  INTERFACE:
--                  ~GameObject()
--
--  RETURNS:
--                  Destructor
--
--  NOTES:
--                  Default destructor that gets inherited by all children                
-----------------------------------------------------------------------------*/
        virtual ~GameObject(){}

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getObjID
--
--  DATE:
--                  March 9, 2012
--
--  REVISIONS:
--
--  DESIGNER:
--                  Po Hsu
--
--  PROGRAMMER:
--                  Po Hsu
--
--  INTERFACE:
--                  getObjectID() const
--
--  RETURNS:
--                  int
--
--  NOTES:
--                  Getter for objID_
-----------------------------------------------------------------------------*/
        int getObjID() const;

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getType
--
--  DATE:
--                  March 9, 2012
--
--  REVISIONS:
--                  March 14, 2012 (Roger)
--                      - created enum type ObjectType replacing the int
--
--  DESIGNER:
--                  Po Hsu
--
--  PROGRAMMER:
--                  Po Hsu
--                  Roger Fan
--
--  INTERFACE:
--                  getType() const
--
--  RETURNS:
--                  ObjectType
--
--  NOTES:
--                  Getter for type_
-----------------------------------------------------------------------------*/
        ObjectType getType() const;

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getDegree
--
--  DATE:
--                  March 9, 2012
--
--  REVISIONS:
--                  March 14, 2012 (Roger)
--                      - switched to using double type
--
--  DESIGNER:
--                  Po Hsu
--
--  PROGRAMMER:
--                  Po Hsu
--                  Roger Fan
--
--  INTERFACE:
--                  getDegree() const
--
--  RETURNS:
--                  double
--
--  NOTES:
--                  Getter for degree_
-----------------------------------------------------------------------------*/
        double getDegree() const;

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getPosition
--
--  DATE:
--                  March 9, 2012
--
--  REVISIONS:
--
--  DESIGNER:
--                  Po Hsu
--
--  PROGRAMMER:
--                  Po Hsu
--
--  INTERFACE:
--                  getPosition() const
--
--  RETURNS:
--                  Point
--
--  NOTES:
--                  Getter for pos_
-----------------------------------------------------------------------------*/
        Point getPosition() const;
        
/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getObjDistance
--
--  DATE:
--                  March 15, 2012
--
--  REVISIONS:
--
--  DESIGNER:
--                  Roger Fan
--
--  PROGRAMMER:
--                  Roger Fan
--
--  INTERFACE:
--                  getObjDistance(const GameObject &gObj) const
--
--  RETURNS:
--                  double
--
--  NOTES:
--                  Get the distance between this GameObject and another
--                      GameObject
-----------------------------------------------------------------------------*/
        double getObjDistance(const GameObject &gObj) const;

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  print
--
--  DATE:
--                  March 9, 2012
--
--  REVISIONS:
--
--  DESIGNER:
--                  Po Hsu
--
--  PROGRAMMER:
--                  Po Hsu
--
--  INTERFACE:
--                  print(std::ostream& os) const
--
--  RETURNS:
--                  void.
--
--  NOTES:
--                  Prints out the member variable values for debugging purpose
-----------------------------------------------------------------------------*/
        virtual void print(std::ostream& os) const;
};

#endif
