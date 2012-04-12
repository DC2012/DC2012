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
#include <iostream>
#include <cmath>

class Point
{
    private:
        double x_,  // x-coordinate
               y_;  // y-coordinate
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

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getX
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
--                  getX() const
--  RETURNS:
--                  double
--  NOTES:
--                  Getter for x_
-----------------------------------------------------------------------------*/
        double getX()const;

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getY
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
--                  getY() const
--  RETURNS:
--                  double
--  NOTES:
--                  Getter for y_
-----------------------------------------------------------------------------*/
        double getY()const;

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  setX
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
--                  setX(const double& x)
--  RETURNS:
--                  void
--  NOTES:
--                  Setter for x_
-----------------------------------------------------------------------------*/
        void setX(const double& x);

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  setY
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
--                  setY(const double& y)
--  RETURNS:
--                  void
--  NOTES:
--                  Setter for y_
-----------------------------------------------------------------------------*/
        void setY(const double& y);

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  getDistance
--  DATE:
--                  March 14, 2012
--  REVISIONS:
--
--  DESIGNER:
--                  Roger Fan
--  PROGRAMMER:
--                  Roger Fan
--  INTERFACE:
--                  getDistance(const Point &pt) const
--  RETURNS:
--                  double
--  NOTES:
--                  Get the distance of this Point and another Point
-----------------------------------------------------------------------------*/
        double getDistance(const Point &pt) const;

/*-----------------------------------------------------------------------------
--  FUNCTION:
--                  operator+=
--  DATE:
--                  March 9, 2012
--  REVISIONS:
--
--  DESIGNER:
--                  Po Hsu
--  PROGRAMMER:
--                  Po Hsu
--  INTERFACE:
--                  operator+=(const Point& rhs)
--  RETURNS:
--                  Point&
--  NOTES:
--                  Adds two Points together and returns the new Point
-----------------------------------------------------------------------------*/
        Point& operator+=(const Point& rhs);

/*-----------------------------------------------------------------------------
--  FUNCTION:       operator<
--
--  DATE:           April 10th, 2012
--
--  REVISIONS:
--
--  DESIGNER:       Tyler Allison
--
--  PROGRAMMER:     Tyler Allison
--
--  INTERFACE:      operator<(const Point& rhs)
--
--  RETURNS:        bool
--
--  NOTES:          Comparison function for 2 points, returns whether one is
--                  less than the other.
--
-----------------------------------------------------------------------------*/
        bool operator<(const Point& rhs) const;

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
        void print(std::ostream& os)const;
};

#endif
