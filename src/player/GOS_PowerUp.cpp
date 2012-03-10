#include "GOS_PowerUp.h"

// constructor
GOS_PowerUp::GOS_PowerUp(int objID, int degree, int posX, int posY)
: GameObjectStationary(objID, degree, posX, posY)
{
	// empty for now
}

void GOS_PowerUp::print(std::ostream& os)const
{
	os << "objID:\t\t" << objID_ << std::endl;
	os << "degree:\t\t" << degree_.getDegree() << std::endl;
	pos_.print(os);
}

