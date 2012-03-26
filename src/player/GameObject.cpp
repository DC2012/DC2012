#include "GameObject.h"

GameObject::GameObject(int objID, int type, double degree, double posX, double posY)
	:objID_(objID), type_(type), degree_(degree), pos_(posX, posY)
{
	switch(type_)
	{
		case SHIP1:
            spritePt_ = Point(posX-(double(SHIP1_SPRITE_WIDTH)/2.0),
                posY-(double(SHIP1_SPRITE_HEIGHT)/2.0));
			hb_ = Hitbox(pos_, double(SHIP1_SPRITE_WIDTH), double(SHIP1_SPRITE_HEIGHT));
			break;
		case SHIP2:
			spritePt_ = Point(posX-(double(SHIP2_SPRITE_WIDTH)/2.0), 
                posY-(double(SHIP2_SPRITE_HEIGHT)/2.0));
			hb_ = Hitbox(pos_, double(SHIP2_SPRITE_WIDTH), double(SHIP2_SPRITE_HEIGHT));
			break;
	}
}

int GameObject::getObjID()const
{
	return objID_;
}

int GameObject::getType()const
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

void GameObject::print(std::ostream& os)const
{
	os << "objID:\t\t" << objID_ << std::endl;
	os << "type:\t\t" << type_ << std::endl;
	os << "degree:\t\t" << degree_.getDegree() << std::endl;
	pos_.print(os);
}
