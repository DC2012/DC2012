#include "GOM_Projectile.h"
#include "GOM_Ship.h"
#include <iostream>

// testing functionality of the GOM_Projectile class 2012/03/08 -Po
int main()
{
	GOM_Projectile projectile(123,	// object id
							  0,	// degree
							  5,	// x coordinate
							  5,	// y coordinate
							  1,	// player id
							  50,	// speed
							  30,	// ttl
							  100) ;// damage
	projectile.print(std::cout);

	GOM_Ship ship(234,0,6,6,2,30,1,100,77) ;
	ship.print(std::cout);
	getchar();
}