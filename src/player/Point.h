/*----------------------------------------------------------------------
--	CLASS NAME:
--					Point
--	CONSTRUCTOR:
--					Point(int x, int y)
--	DESTROCTOR:
--					Default
--	FUNCTIONS:
--					int getX()
--					int getY()
--					Point & operator+=(const Point &rhs)
--					void print(std::ostream &os)
--	DATE:
--					March 9, 2012
--	REVISIONS:
--					March 14, 2012
--						- switched to using foating-point type, double
--
--	DESIGNER:
--					Po Hsu
--	PROGRAMMER:
--					Po Hsu
--					Roger Fan
--	NOTES:
----------------------------------------------------------------------*/
#ifndef GOPOS_H_
#define GOPOS_H_
#include <QPointF>
#include <iostream>
#include <cmath>

// A class that takes two integer values to represent x & y coordinates
class Point
{
	private:
		double x_, y_;
	public:
		// contructor
		// explicit to indicate no implicit conversion
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