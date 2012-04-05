#include "GOM_Projectile.h"

size_t GOM_Projectile::projectileCount_ = 0;

// constructor
GOM_Projectile::GOM_Projectile(int objID, ObjectType type, double degree, double posX, double posY, 
	int playerID, double speed, int ttl, int damage)
:GameObjectMoveable(objID, type, degree, posX, posY, playerID, speed), 
	ttl_(ttl), damage_(damage)
{
	projectileCount_++;
}

void GOM_Projectile::update(const std::string &str)
{
	std::istringstream istr(str);
	char endCheck;
	int type = -1;
	int objID, degree, posX, posY, playerID, speed, damage, ttl;
	
	istr >> type;
	switch(ObjectType(type))
	{
	case PROJECTILE:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl >> 
			damage >> endCheck;
			
		if(!istr.good() || endCheck != PROJECTILE_STR)
			break;
		
		type_ = ObjectType(type);
		objID_ = objID;
		degree_.setDegree(double(degree));
		pos_.setX(double(posX));
		pos_.setY(double(posY));
		playerID_ = playerID;
		speed_ = double(speed);
		ttl_ = ttl;
		damage_ = damage;
		break;
	}
}

std::string GOM_Projectile::toString() const
{
	std::ostringstream ostr;
	
	ostr << int(type_) << " ";
	ostr << objID_ << " ";
	ostr << int(degree_.getDegree()) << " ";
	ostr << int(pos_.getX()) << " ";
	ostr << int(pos_.getY()) << " ";
	ostr << playerID_ << " ";
	ostr << int(speed_) << " ";
	ostr << ttl_ << " ";
	ostr << damage_ << " ";
	ostr << PROJECTILE_STR;
	
	return ostr.str();
}

void GOM_Projectile::move()
{
	Point pt;
	
	pt = getDirectionalPoint(speed_, degree_.getDegree());
	pos_.setX(pos_.getX() + pt.getX());
	pos_.setY(pos_.getY() + pt.getY());
	moveHitbox(pt.getX(), pt.getY());
}

void GOM_Projectile::print(std::ostream& os)const
{
	os << "Number #" << projectileCount_ << " projectile" << std::endl;
	GameObjectMoveable::print(os);
	os << "ttl:\t\t" << ttl_ << std::endl;
	os << "damage:\t\t" << damage_ << std::endl << std::endl << std::endl;
}