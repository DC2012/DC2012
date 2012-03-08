#include "Degree.h"

Degree::Degree(int degree)
{
	degree_ = degree;
}

void Degree::rotate(int degree)
{
	degree_ += degree;
	
	if(degree_ > 360)
		degree_ = (degree_ % 360);
	
	while(degree_ < 0)
		degree_ += 360;
}

void Degree::setDegree(int degree)
{
	degree_ = degree;
	rotate(0);
}

int Degree::getDegree()
{
	return degree_;
}
