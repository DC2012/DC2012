/*-----------------------------------------------------------------------------
--  CLASS NAME:
--                  Point
--  CONSTRUCTOR:
--                  Point(int x, int y)
--  DESTROCTOR:
--                  Default
--  FUNCTIONS:
--                  public:
--                      double  getX()          const;
--                      double  getY()          const;
--                      QPointF getQPointF()    const;
--                      void    setX(const double& x);
--                      void    setY(const double& y);   
--                      double  getDistance(const Point &pt) const;
--                      Point&  operator+=(const Point& rhs);
--                      void    print(std::ostream& os)const;
--  DATE:
--                  March 9, 2012
--  REVISIONS:
--                  March 14, 2012
--                      - switched to using foating-point type, double
--  DESIGNER:
--                  Po Hsu
--  PROGRAMMER:
--                  Po Hsu
--                  Roger Fan
--  NOTES:
--                  This is a class that takes two integer values to represent
--                    x & y coordinates
-----------------------------------------------------------------------------*/
#ifndef GOPOS_H_
#define GOPOS_H_
#include <QPointF>
#include <iostream>
#include <cmath>

class Point
{
    private:
        double x_, y_;
    public:
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
--                  Point(double x, double y)
--  RETURNS:
--                  Constructor
--  NOTES:
--                  x   X-coordinate of the point
--                  y   Y-coordinate of the point
-----------------------------------------------------------------------------*/
        explicit Point(double x = 0, double y = 0): x_(x), y_(y) {}

        // getters
        double getX()const;
        double getY()const;
        QPointF getQPointF()const;

        // setters
        void setX(const double& x);
        void setY(const double& y);
        
        double getDistance(const Point &pt) const;

        Point& operator+=(const Point& rhs); // adding two Points
        void print(std::ostream& os)const;
};

#endif