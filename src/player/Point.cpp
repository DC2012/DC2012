#include "Point.h"
#include <iostream>

int Point::getX()
{
	return x_;
}

int Point::getY()
{
	return y_;
}

Point& Point::operator+=(const Point& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;
	return *this;
}

void Point::print(std::ostream& os)
{
	os << "Point:\t\tx(" << x_ << ") y(" << y_ << ")" << std::endl;
}