#include "GOS_PowerUp.h"

size_t GOS_PowerUp::powerUpCount_ = 0;

// constructor
GOS_PowerUp::GOS_PowerUp(ObjectType type, int objID, double posX, double posY, 
	int ttl, BONUS bonus)
: GOM_Projectile(type, objID, 0, posX, posY, 0, 0, ttl) : bonus_(bonus)
{

}

BONUS GOS_PowerUp::getBonus()
{
	return bonus_;
}


void GOS_PowerUp::print(std::ostream& os)const
{
    os << "Number #" << powerUpCount_ << " power up" << std::endl;
    GOM_Projectile::print(os);
    os << std::endl;
}

