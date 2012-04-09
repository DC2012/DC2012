/*----------------------------------------------------------------------
--  CLASS NAME:
--                  Hitbox
--  CONSTRUCTOR:
--                  Hitbox(const Point& org, const int& width, const int& height)
--  DESTROCTOR:
--                  ~Hitbox()
--  FUNCTIONS:
--                  public:
--                      bool isCollision(const Hitbox& other);
--                      void print(std::ostream& os) const;
--  DATE:
--                  March 12, 2012
--  REVISIONS:
--                  March 14, 2012 (Roger)
--                      - switched to using double type for width & height
--  DESIGNER:
--                  Po Hsu
--  PROGRAMMER:
--                  Po Hsu
--                  Roger Fan
--  NOTES:
--                  This is a class that takes in a centre point of a
--                    rectanglular object and caculates it's respective
--                    four corners forming the 'hitbox'
----------------------------------------------------------------------*/
#ifndef HITBOX_H
#define HITBOX_H
#include "Point.h"
#include <string>
#include <sstream>
#include <iostream>

class Hitbox
{
    public:
        Point tLeft,    // top-left     corner
              tRight,   // top-right    corner
              bLeft,    // bottom-left  corner
              bRight;   // bottom-right corner

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  Constructor
--  DATE:
--                  March 9, 2012
--  REVISIONS:
--                  March 14, 2012 (Roger)
--                      - switched to using double type
--  DESIGNER:
--                  Po Hsu
--  PROGRAMMER:
--                  Po Hsu
--                  Roger Fan
--  INTERFACE:
--                  Hitbox(const Point& org, const double& width, const double& height)
--  RETURNS:
--                  Constructor
--  NOTES:
--                  org     centre of the object
--                  width   width of the object
--                  height  height of the object
-----------------------------------------------------------------------------*/
        Hitbox(const Point& org = Point(0, 0), const double& width = 0, const double& height = 0);

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  Destructor
--  DATE:
--                  March 9, 2012
--  REVISIONS:
--
--  DESIGNER:
--                  Po Hsu
--  PROGRAMMER:
--                  Po Hsu
--  INTERFACE:
--                  ~Hitbox()
--  RETURNS:
--                  Destructor
--  NOTES:
--                  Destructor
-----------------------------------------------------------------------------*/
        ~Hitbox() {}

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  isCollision
--  DATE:
--                  March 18, 2012
--  REVISIONS:
--                  April 6, 2012 (Po)
--                      - modified the comparison of coordinates to reflect
--                          screen coordinates instead of standard coordinates
--
--  DESIGNER:
--                  Tyler Allison
--  PROGRAMMER:
--                  Tyler Allison
--                  Po Hsu
--  INTERFACE:
--                  isCollision(const Hitbox& other)
--  RETURNS:
--                  bool
--  NOTES:
--                  Checks if there is a collision between two Hitbox
-----------------------------------------------------------------------------*/
        bool isCollision(const Hitbox& other);

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  print
--  DATE:
--                  March 9, 2012
--  REVISIONS:
--
--  DESIGNER:
--                  Po Hsu
--  PROGRAMMER:
--                  Po Hsu
--  INTERFACE:
--                  print(std::ostream& os) const
--  RETURNS:
--                  void.
--  NOTES:
--                  Prints out the member variable values for debugging purpose
-----------------------------------------------------------------------------*/
        void print(std::ostream& os) const;
};

#endif
