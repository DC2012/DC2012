#include "GOS_Obstacle.h"

size_t GOS_Obstacle::obstacleCount_;

// constructor
GOS_Obstacle::GOS_Obstacle(int objID, ObjectType type, double degree, double posX, double posY)
: GameObjectStationary(objID, type, degree, posX, posY)
{
	obstacleCount_++;
}

void GOS_Obstacle::print(std::ostream& os)const
{
	os << "Number #" << obstacleCount_ << " obstacle" << std::endl;
	GameObjectStationary::print(os);
	os << std::endl << std::endl;
}
