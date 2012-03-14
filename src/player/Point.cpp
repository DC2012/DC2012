#include "Point.h"
#include <iostream>

double Point::getX()const
{
	return x_;
}

double Point::getY()const
{
	return y_;
}

void Point::setX(const double& x)
{
	x_ = x;
}

void Point::setY(const double& y)
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