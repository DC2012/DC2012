#include "GOS_Obstacle.h"
#include "GOS_PowerUp.h"

int main()
{
	GOS_Obstacle ob(1,0,5,5);
	ob.print(std::cout);

	GOS_PowerUp pu(2,0,6,6);
	pu.print(std::cout);
	getchar();
}