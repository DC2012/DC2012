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
--
--	DESIGNER:
--					Po Hsu
--	PROGRAMMER:
--					Po Hsu
--	NOTES:
----------------------------------------------------------------------*/
#ifndef GOPOS_H_
#define GOPOS_H_
#include <iostream>

// A class that takes two integer values to represent x & y coordinates
class Point
{
	private:
		int x_, y_;
	public:
		// contructor
		// explicit to indicate no implicit conversion
		explicit Point(int x = 0, int y = 0): x_(x), y_(y) {}

		// getters
		int getX()const;
		int getY()const;

		// setters
		void setX(const int& x);
		void setY(const int& y);

		Point& operator+=(const Point& rhs); // adding two Points
		void print(std::ostream& os)const;
};

#endif