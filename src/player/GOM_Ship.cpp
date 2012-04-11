#include "GOM_Ship.h"

size_t GOM_Ship::shipCount_ = 0;

//constructor
GOM_Ship::GOM_Ship(ObjectType type, int objID, double degree, double posX, double posY, 
	int playerID, double speed, int health, int attackPower)
:GameObjectMoveable(type, objID, degree ,posX ,posY ,playerID ,speed), 
	health_(health), attackPower_(attackPower)
{
    actionFlags_.push_back(false);
    actionFlags_.push_back(false);
    actionFlags_.push_back(false);
    actionFlags_.push_back(false);
    accel_ = 0.02;
    decel_ = 0.02;
    maxSpeed_ = 3.6;
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
        if(speed_ < 0)
                speed_ = 0;
}

void GOM_Ship::move()
{
    Point pt;

    if(actionFlags_[ROTATE_L])
    {
        if(speed_ > 2)
        {
            degree_.rotate(-1);
            rotateHitbox(-1);
        }
        else if(speed_ != 0)
        {
            degree_.rotate(-1.5);
            rotateHitbox(-1.5);
        }
    }

    if(actionFlags_[ROTATE_R])
    {
        if(speed_ > 2)
        {
            degree_.rotate(1);
            rotateHitbox(1);
        }
        else if(speed_ != 0)
        {
            degree_.rotate(2);
            rotateHitbox(2);
        }
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
    spritePt_.setX(spritePt_.getX() + pt.getX());
    spritePt_.setY(spritePt_.getY() + pt.getY());
    moveHitbox(pt.getX(), pt.getY());
}

void GOM_Ship::setActionFlag(int flag, bool val)
{
	if(flag >= 0 && flag < (int)actionFlags_.size())
	{
		actionFlags_[flag] = val;
	}
}

void GOM_Ship::update(const std::string &str)
{
	std::istringstream istr(str);
	char endCheck;
        int type = -1;
        double degree, posX, posY, speed;
        int objID, playerID, health, attackPower;
        double sprite_w, sprite_h, hb_w, hb_h;
        double tl_x, tl_y;
        double tr_x, tr_y;
        double bl_x, bl_y;
        double br_x, br_y;
	
	istr >> type;
	switch(ObjectType(type))
	{
	case SHIP1:
		sprite_w = double(SHIP1_SPRITE_WIDTH);
		sprite_h = double(SHIP1_SPRITE_HEIGHT);
		hb_w = double(SHIP1_WIDTH);
		hb_h = double(SHIP1_HEIGHT);
		
	case SHIP2:
		sprite_w = double(SHIP2_SPRITE_WIDTH);
		sprite_h = double(SHIP2_SPRITE_HEIGHT);
		hb_w = double(SHIP2_WIDTH);
		hb_h = double(SHIP2_HEIGHT);

		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> health
                        >> attackPower
                        >> tl_x >> tl_y
                        >> tr_x >> tr_y
                        >> bl_x >> bl_y
                        >> br_x >> br_y
                        >> endCheck;
		
		if(!istr.good() || endCheck != SHIP_STR)
			break;

                hb_.tLeft = Point(tl_x, tl_y);
                hb_.tRight = Point(tr_x, tr_y);
                hb_.bLeft = Point(bl_x, bl_y);
                hb_.bRight = Point(br_x, br_y);
		
		type_ = ObjectType(type);
		objID_ = objID;
                degree_.setDegree(degree);
                pos_.setX(posX);
                pos_.setY(posY);
		playerID_ = playerID;
                speed_ = speed;
		health_ = health;
		attackPower_ = attackPower;
		spritePt_.setX(pos_.getX()-(sprite_w/2));
		spritePt_.setY(pos_.getY()-(sprite_h/2));
		break;
	}
}

std::string GOM_Ship::toString() const
{
	std::ostringstream ostr;
	
	ostr << int(type_) << " ";
	ostr << objID_ << " ";
        ostr << degree_.getDegree() << " ";
        ostr << pos_.getX() << " ";
        ostr << pos_.getY() << " ";
	ostr << playerID_ << " ";
        ostr << speed_ << " ";
	ostr << health_ << " ";
	ostr << attackPower_ << " ";
        ostr << hb_.tLeft.getX() << " ";
        ostr << hb_.tLeft.getY() << " ";
        ostr << hb_.tRight.getX() << " ";
        ostr << hb_.tRight.getY() << " ";
        ostr << hb_.bLeft.getX() << " ";
        ostr << hb_.bLeft.getY() << " ";
        ostr << hb_.bRight.getX() << " ";
        ostr << hb_.bRight.getY() << " ";
	ostr << SHIP_STR;
	
	return ostr.str();
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

bool GOM_Ship::takeDamage(int dmg)
{
    health_ -= dmg;
    if(health_ <= 0)
        return false;
    return true;
}
