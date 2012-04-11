#include "GOM_Projectile.h"

size_t GOM_Projectile::projectileCount_ = 0;

// constructor
GOM_Projectile::GOM_Projectile(ObjectType type, int objID, double degree, double posX, double posY, 
	int playerID, double speed, int ttl, int damage)
:GameObjectMoveable(type, objID, degree, posX, posY, playerID, speed), 
	ttl_(ttl), damage_(damage)
{
	projectileCount_++;
}

void GOM_Projectile::update(const std::string &str)
{
	std::istringstream istr(str);
	char endCheck;
	int type = -1;
        double degree, posX, posY, speed;
        int objID, playerID, damage, ttl;
        double sprite_w, sprite_h, hb_w, hb_h;
        double tl_x, tl_y;
        double tr_x, tr_y;
        double bl_x, bl_y;
        double br_x, br_y;
	
	istr >> type;
	switch(ObjectType(type))
	{
	case PROJECTILE:
            sprite_w = double(CANNON_SPRITE_WIDTH);
            sprite_h = double(CANNON_SPRITE_HEIGHT);
            hb_w = double(CANNON_WIDTH);
            hb_h = double(CANNON_HEIGHT);

            istr >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl
                 >> damage
                 >> tl_x >> tl_y
                 >> tr_x >> tr_y
                 >> bl_x >> bl_y
                 >> br_x >> br_y
                 >> endCheck;

            if(!istr.good() || endCheck != PROJECTILE_STR)
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
            ttl_ = ttl;
            damage_ = damage;
            spritePt_.setX(pos_.getX()-(sprite_w/2));
            spritePt_.setY(pos_.getY()-(sprite_h/2));
            break;
	}
}

std::string GOM_Projectile::toString() const
{
	std::ostringstream ostr;
	
	ostr << int(type_) << " ";
	ostr << objID_ << " ";
        ostr << degree_.getDegree() << " ";
        ostr << pos_.getX() << " ";
        ostr << pos_.getY() << " ";
	ostr << playerID_ << " ";
        ostr << speed_ << " ";
	ostr << ttl_ << " ";
	ostr << damage_ << " ";
        ostr << hb_.tLeft.getX() << " ";
        ostr << hb_.tLeft.getY() << " ";
        ostr << hb_.tRight.getX() << " ";
        ostr << hb_.tRight.getY() << " ";
        ostr << hb_.bLeft.getX() << " ";
        ostr << hb_.bLeft.getY() << " ";
        ostr << hb_.bRight.getX() << " ";
        ostr << hb_.bRight.getY() << " ";
	ostr << PROJECTILE_STR;
	
	return ostr.str();
}

bool GOM_Projectile::move()
{
    Point pt;

    //std::cout << "ttl_: " << (ttl_ + 1) << std::endl;

    if(--ttl_ <= 0)
        return true;

    pt = getDirectionalPoint(speed_, degree_.getDegree());
    pos_.setX(pos_.getX() + pt.getX());
    pos_.setY(pos_.getY() + pt.getY());
    spritePt_.setX(spritePt_.getX() + pt.getX());
    spritePt_.setY(spritePt_.getY() + pt.getY());
    moveHitbox(pt.getX(), pt.getY());

    return false;
}

void GOM_Projectile::print(std::ostream& os)const
{
	os << "Number #" << projectileCount_ << " projectile" << std::endl;
	GameObjectMoveable::print(os);
	os << "ttl:\t\t" << ttl_ << std::endl;
	os << "damage:\t\t" << damage_ << std::endl << std::endl << std::endl;
}

int GOM_Projectile::getDamage() const
{
    return damage_;
}
