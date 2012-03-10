#include "GOS_Obstacle.h"

// constructor
GOS_Obstacle::GOS_Obstacle(int objID, int type, int degree, int posX, int posY)
: GameObjectStationary(objID, type, degree, posX, posY)
{
	// empty for now
}

void GOS_Obstacle::print(std::ostream& os)const
{
	os << "objID:\t\t" << objID_ << std::endl;
	os << "degree:\t\t" << degree_.getDegree() << std::endl;
	pos_.print(os);
}
