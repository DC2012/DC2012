#include "GameObject.h"

int GameObject::getObjID()const
{
	return objID_;
}

int GameObject::getType()const
{
	return type_;
}

Degree GameObject::getDegree()const
{
	return degree_;
}

Point GameObject::getPosition()const
{
	return pos_;
}

void GameObject::print(std::ostream& os)const
{
	os << "objID:\t\t" << objID_ << std::endl;
	os << "type:\t\t" << type_ << std::endl;
	os << "degree:\t\t" << degree_.getValue() << std::endl;
	pos_.print(os);
}