#include "GOM_Projectile.h"

size_t GOM_Projectile::projectileCount_ = 0;

// constructor
GOM_Projectile::GOM_Projectile(int objID, int type, double degree, double posX, double posY, 
	int playerID, int speed, int ttl, int damage)
:GameObjectMoveable(objID, type, degree, posX, posY, playerID, speed), 
	ttl_(ttl), damage_(damage)
{
	projectileCount_++;
}

void GOM_Projectile::accelerate(int amount)
{
	speed_ += amount;
}

void GOM_Projectile::decelerate(int amount)
{
	speed_ -= amount;
}

void GOM_Projectile::print(std::ostream& os)const
{
	os << "Number #" << projectileCount_ << " projectile" << std::endl;
	GameObjectMoveable::print(os);
	os << "ttl:\t\t" << ttl_ << std::endl;
	os << "damage:\t\t" << damage_ << std::endl << std::endl << std::endl;
}