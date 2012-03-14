#include "Degree.h"

Degree::Degree(double degree)
{
	degree_ = degree;
}

void Degree::rotate(double degree)
{
	degree_ += degree;
	
	if(degree_ > 360)
		degree_ = (int(degree_) % 360);
	
	while(degree_ < 0)
		degree_ += 360;
}

void Degree::setDegree(double degree)
{
	degree_ = degree;
	(*this).rotate(0);
}

double Degree::getDegree()const
{
	return degree_;
}
