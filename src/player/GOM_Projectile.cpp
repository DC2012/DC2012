#include "GOM_Projectile.h"

size_t GOM_Projectile::projectileCount_ = 0;

// constructor
GOM_Projectile::GOM_Projectile(int objID,
							   int posX,
							   int posY,
							   int playerID,
							   int speed,
							   int ttl,
							   int damage)
: GameObject::objID_(objID),
  GameObject::pos_(posX,posY),
  GameObjectMoveable::playerID_(playerID),
  GameObjectMoveable::speed_(speed),
  ttl_(ttl),
  damage_(damage)
{
	projectileCount_++;
}

void GOM_Projectile::print(std::ostream& os)const
{
	os << "objID:\t\t" << objID_ << std::endl;
	pos_.print(os);
	os << "playerID:\t\t" << playerID_ << std::endl;
	os << "speed:\t\t" << speed_ << std::endl;
	os << "ttl:\t\t" << ttl_ << std::endl;
	os << "damage:\t\t" << damage_ << std::endl;
}