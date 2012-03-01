#include "GameObject.h"

GameObject::GameObject(const int GObjID,
					   const int spriteID,
					   const int posX,
					   const int poxY)
: GObjID_(GObjID), spriteID_(spriteID), pos_(posX, posY)
{
	// constructor
}

int GameObject::getGObjID() const
{
	return GObjID_;
}

int GameObject::getSpriteID() const
{
	return spriteID_;
}

Point::Point& GameObject::getPosition() const
{
	return &pos_;
}

// for testing purposes
void GameObject::print(ostream& os) const
{
	os << "GObjID: \t" << GObjID_ << std::endl;
	os << "spriteID: \t" << spriteID_ << std::endl;
	pos_.print(os);
}