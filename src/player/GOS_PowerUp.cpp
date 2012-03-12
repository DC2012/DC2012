#include "GOS_PowerUp.h"

size_t GOS_PowerUp::powerUpCount_ = 0;

// constructor
GOS_PowerUp::GOS_PowerUp(int objID, int type, int degree, int posX, int posY)
: GameObjectStationary(objID, type, degree, posX, posY)
{
	powerUpCount_++;
}

void GOS_PowerUp::print(std::ostream& os)const
{
	os << "Number #" << powerUpCount_ << " power up" << std::endl;
	GameObjectStationary::print(os);
	os << std::endl << std::endl;
}

