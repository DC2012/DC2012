#include "GOM_Ship.h"

size_t GOM_Ship::shipCount_ = 0;

//constructor
GOM_Ship::GOM_Ship(int objID, int type, double degree, double posX, double posY, 
	int playerID, int speed, int health, int attackPower)
:GameObjectMoveable(objID, type, degree ,posX ,posY ,playerID ,speed), 
	health_(health), attackPower_(attackPower)
{
	actionFlags_.push_back(false);
	actionFlags_.push_back(false);
	actionFlags_.push_back(false);
	actionFlags_.push_back(false);
	shipCount_++;
}

int GOM_Ship::getHealth()const
{
	return health_;
}
    
void GOM_Ship::accelerate()
{
    speed_++;
}    

void GOM_Ship::decelerate()
{
    speed_--;
}

void GOM_Ship::print(std::ostream& os)const
{
	os << "Number #" << shipCount_ << " ship" << std::endl;
	GameObjectMoveable::print(os);
	os << "health:\t\t" << health_ << std::endl;
	os << "attackPower:\t" << attackPower_ << std::endl;
	os << "flags:\t\t";
	os << "rotateL=" << actionFlags_[ROTATEL];
	os << " rotateR=" << actionFlags_[ROTATER];
	os << " accelerate=" << actionFlags_[ACCELERATE];
	os << " decelerate=" << actionFlags_[DECELERATE] << std::endl << std::endl;
}