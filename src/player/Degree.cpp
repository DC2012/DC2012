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
