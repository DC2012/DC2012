#include "GOM_Projectile.h"
#include "GOM_Ship.h"

int main()
{
	GOM_Ship ship(1,	// object id
				  3,	// type
				  0,	// degree
				  5,	// x coordinate
				  5,	// y coordinate
				  2,	// player id
				  0,	// speed
				  100,	// health
				  1000);// attack power
	ship.print(std::cout);

	GOM_Projectile projectile(2,	// object id
							  5,	// type
							  50,	// degree
							  6,	// x
							  6,	// y
							  5,	// player id
							  30,	// speed
							  20,	// ttl
							  40);	// damage
	projectile.print(std::cout);
	getchar();
}