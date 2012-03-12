#include "Point.h"
#include <iostream>

int Point::getX()const
{
	return x_;
}

int Point::getY()const
{
	return y_;
}

void Point::setX(const int& x)
{
	x_ = x;
}

void Point::setY(const int& y)
{
	y_ = y;
}

Point& Point::operator+=(const Point& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;
	return *this;
}

void Point::print(std::ostream& os)const
{
	os << "Point:\t\tx(" << x_ << ") y(" << y_ << ")" << std::endl;
}