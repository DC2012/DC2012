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

double Point::getDistance(const Point &pt) const
{
	return sqrt(pow((x_ - pt.getX()), 2) + pow((y_ - pt.getY()), 2));
}

Point& Point::operator+=(const Point& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;
	return *this;
}

bool Point::operator<(const Point& rhs) const
{
    if(x_ == rhs.x_)
    {
        if(y_ == rhs.y_)
            return false; //equal
        if(y_ < rhs.y_)
            return true;
        else
            return false;
    }
    else
    {
        if(x_ < rhs.x_)
            return true;
        else
            return false;
    }
}

void Point::print(std::ostream& os)const
{
	os << "Point:\t\tx(" << x_ << ") y(" << y_ << ")" << std::endl;
}
