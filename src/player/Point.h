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

		int getX() const
		{
			return x_;
		}

		int getY() const
		{
			return y_;
		}

		// adding two Points
		Point& operator+=(const Point& rhs) {
			x_ += rhs.getX();
			y_ += rhs.getY();
			return *this;
		}

		void print(std::ostream& os) const
		{
			os << "Point: \t\tx(" << x_ << ") y(" << y_ << ")" << std::endl;
		}
};

#endif