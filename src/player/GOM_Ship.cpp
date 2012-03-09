#include "GOM_Ship.h"

//constructor
GOM_Ship::GOM_Ship(int objID, int degree,int posX, int posY, 
	int playerID, int speed, int health, int attackPower)
:GameObjectMoveable(objID, degree ,posX ,posY ,playerID ,speed), 
	health_(health), attackPower_(attackPower)
{
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
    os << "ObjID:\t\t" << objID_ <<std::endl;
	os << "degree:\t\t" << degree_.getDegree() << std::endl;
    pos_.print(os);
	os << "playerID:\t" << playerID_ << std::endl;
	os << "speed:\t\t" << speed_ << std::endl;
	os << "health:\t\t" << health_ << std::endl;
	os << "attackPower:\t" << attackPower_ << std::endl;
}