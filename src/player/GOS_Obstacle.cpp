#include "GOS_Obstacle.h"

size_t GOS_Obstacle::obstacleCount_;

// constructor
GOS_Obstacle::GOS_Obstacle(int objID, int type, int degree, int posX, int posY)
: GameObjectStationary(objID, type, degree, posX, posY)
{
	obstacleCount_++;
}

void GOS_Obstacle::print(std::ostream& os)const
{
	os << "Number #" << obstacleCount_ << " obstacle" << std::endl;
	os << "objID:\t\t" << objID_ << std::endl;
	os << "type:\t\t" << type_ << std::endl;
	os << "degree:\t\t" << degree_.getDegree() << std::endl;
	pos_.print(os);
	os << std::endl << std::endl << std::endl;
}
