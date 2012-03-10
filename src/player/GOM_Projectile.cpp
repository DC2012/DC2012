#include "GOM_Projectile.h"

size_t GOM_Projectile::projectileCount_ = 0;

// constructor
GOM_Projectile::GOM_Projectile(int objID, int type, int degree, int posX, int posY, 
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
	os << "objID:\t\t" << objID_ << std::endl;
	os << "type:\t\t" << type_ << std::endl;
	os << "degree:\t\t" << degree_.getDegree() << std::endl;
	pos_.print(os);
	os << "playerID:\t" << playerID_ << std::endl;
	os << "speed:\t\t" << speed_ << std::endl;
	os << "ttl:\t\t" << ttl_ << std::endl;
	os << "damage:\t\t" << damage_ << std::endl << std::endl << std::endl;
}