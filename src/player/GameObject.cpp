#include "GameObject.h"

GameObject::GameObject(ObjectType type, int objID, double degree, double posX, double posY)
	:type_(type), objID_(objID), degree_(degree), pos_(posX, posY)
{
    double sprite_w, sprite_h, hb_w, hb_h;
    
	switch(type_)
	{
		case SHIP1:
            sprite_w = double(SHIP1_SPRITE_WIDTH);
            sprite_h = double(SHIP1_SPRITE_HEIGHT);
            hb_w = double(SHIP1_WIDTH);
            hb_h = double(SHIP1_HEIGHT);
			break;
            
		case SHIP2:
			sprite_w = double(SHIP2_SPRITE_WIDTH);
            sprite_h = double(SHIP2_SPRITE_HEIGHT);
            hb_w = double(SHIP2_WIDTH);
            hb_h = double(SHIP2_HEIGHT);
			break;
            
        case PROJECTILE:
            sprite_w = double(CANNON_SPRITE_WIDTH);
            sprite_h = double(CANNON_SPRITE_HEIGHT);
            hb_w = double(CANNON_WIDTH);
            hb_h = double(CANNON_HEIGHT);
            break;
            
        default:
            // default values??
            sprite_w = double(CANNON_SPRITE_WIDTH);
            sprite_h = double(CANNON_SPRITE_HEIGHT);
            hb_w = double(CANNON_WIDTH);
            hb_h = double(CANNON_HEIGHT);
            break;
	}
    
    spritePt_ = Point(posX-(sprite_w/2.0), posY-(sprite_h/2.0));
    hb_ = Hitbox(pos_, hb_w, hb_h);
}

int GameObject::getObjID()const
{
	return objID_;
}

ObjectType GameObject::getType()const
{
	return type_;
}

double GameObject::getDegree()const
{
	return degree_.getDegree();
}

Point GameObject::getPosition()const
{
	return pos_;
}

Hitbox GameObject::getHitbox()const
{
	return hb_;
}

double GameObject::getObjDistance(const GameObject &gObj) const
{
	return pos_.getDistance(gObj.getPosition());
}

void GameObject::print(std::ostream& os)const
{
	os << "objID:\t\t" << objID_ << std::endl;
	os << "type:\t\t" << type_ << std::endl;
	os << "degree:\t\t" << degree_.getDegree() << std::endl;
	pos_.print(os);
	hb_.print(os);
}

void GameObject::setObjID(int id)
{
    objID_ = id;
}

Point GameObject::getSpriteTopLeft() const
{
    return spritePt_;
}
