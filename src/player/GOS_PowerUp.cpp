#include "GOS_PowerUp.h"

size_t GOS_PowerUp::powerUpCount_ = 0;

// constructor
GOS_PowerUp::GOS_PowerUp(ObjectType type, int objID, double degree, double posX, double posY,
	int ttl, BONUS bonus)
    : GameObjectStationary(type, objID, degree, posX, posY), ttl_(ttl), bonus_(bonus)
{

}

GOS_PowerUp::BONUS GOS_PowerUp::getBonus()
{
	return bonus_;
}


void GOS_PowerUp::print(std::ostream& os)const
{
}

void GOS_PowerUp::update(const std::string &str)
{

}

std::string GOS_PowerUp::toString() const
{
    std::string str;
    return str;
}

