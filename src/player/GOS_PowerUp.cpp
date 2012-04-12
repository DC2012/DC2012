#include "GOS_PowerUp.h"

GOS_PowerUp::BONUS GOS_PowerUp::getBonus() const
{
	return bonus_;
}

void GOS_PowerUp::update(const std::string &str)
{
    std::istringstream istr(str);
    char endCheck;
    int type = -1;
    int bonus;
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
    case POWERUP:
        // !!! needs to be changed when sizes are defined in sprites.h
        sprite_w = double(CANNON_SPRITE_WIDTH);
        sprite_h = double(CANNON_SPRITE_HEIGHT);
        hb_w = double(CANNON_WIDTH);
        hb_h = double(CANNON_HEIGHT);
        // !!! needs to be changed when sizes are defined in sprites.h

        istr >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl
             >> damage
             >> tl_x >> tl_y
             >> tr_x >> tr_y
             >> bl_x >> bl_y
             >> br_x >> br_y
             >> bonus
             >> endCheck;

        if(!istr.good() || endCheck != POWERUP_STR)
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
        bonus_ = BONUS(bonus);
        break;
    }
}

std::string GOS_PowerUp::toString() const
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
    ostr << int(bonus_) << " ";
    ostr << POWERUP_STR;

    return ostr.str();
}

bool GOS_PowerUp::move()
{
    return true;
}
