#include "GOM_Ship.h"

size_t GOM_Ship::shipCount_ = 0;

//constructor
GOM_Ship::GOM_Ship(int objID, int type, double degree, double posX, double posY, 
	int playerID, double speed, int health, int attackPower)
:GameObjectMoveable(objID, type, degree ,posX ,posY ,playerID ,speed), 
	health_(health), attackPower_(attackPower)
{
	actionFlags_.push_back(false);
	actionFlags_.push_back(false);
	actionFlags_.push_back(false);
	actionFlags_.push_back(false);
	accel_ = 0.5;
	decel_ = 0.5;
	maxSpeed_ = 5;
	shipCount_++;
}

int GOM_Ship::getHealth()const
{
	return health_;
}
    
void GOM_Ship::accelerate()
{
    speed_ += accel_;
	if(speed_ > maxSpeed_)
		speed_ = maxSpeed_;
}    

void GOM_Ship::decelerate()
{
    speed_ -= decel_;
	if(speed_ < -maxSpeed_)
		speed_ = -maxSpeed_;
}

void GOM_Ship::move()
{
	Point pt;
	
	if(actionFlags_[ROTATE_L])
	{
		degree_.rotate(-1);
		rotatePointAround(spritePt_, pos_, -1);
	}
	
	if(actionFlags_[ROTATE_R])
	{
		degree_.rotate(1);
		rotatePointAround(spritePt_, pos_, 1);
	}
	
	if(actionFlags_[ACCEL])
	{
		accelerate();
	}
	
	if(actionFlags_[DECEL])
	{
		decelerate();
	}
	
	pt = getDirectionalPoint(speed_, degree_.getDegree());
	pos_.setX(pos_.getX() + pt.getX());
	pos_.setY(pos_.getY() + pt.getY());
}

void GOM_Ship::setActionFlag(int flag, bool val)
{
	if(flag >= 0 && flag < (int)actionFlags_.size())
	{
		actionFlags_[flag] = val;
	}
}

void GOM_Ship::print(std::ostream& os)const
{
	os << "Number #" << shipCount_ << " ship" << std::endl;
	GameObjectMoveable::print(os);
	os << "health:\t\t" << health_ << std::endl;
	os << "attackPower:\t" << attackPower_ << std::endl;
	os << "flags:\t\t";
	os << "rotateL=" << actionFlags_[ROTATE_L];
	os << " rotateR=" << actionFlags_[ROTATE_R];
	os << " accelerate=" << actionFlags_[ACCEL];
	os << " decelerate=" << actionFlags_[DECEL] << std::endl << std::endl;
}