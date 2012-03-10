#include "GOM_Ship.h"

size_t GOM_Ship::shipCount_ = 0;

//constructor
GOM_Ship::GOM_Ship(int objID, int type, int degree,int posX, int posY, 
	int playerID, int speed, int health, int attackPower)
:GameObjectMoveable(objID, type, degree ,posX ,posY ,playerID ,speed), 
	health_(health), attackPower_(attackPower)
{
	shipCount_++;
}
    
void GOM_Ship::accelerate(int amount)
{
    speed_ += amount;
}    

void GOM_Ship::decelerate(int amount)
{
    speed_ -= amount;
}

void GOM_Ship::print(std::ostream& os)const
{
	os << "Number #" << shipCount_ << " ship" << std::endl;
	GameObjectMoveable::print(os);
	os << "health:\t\t" << health_ << std::endl;
	os << "attackPower:\t" << attackPower_ << std::endl << std::endl << std::endl;
}