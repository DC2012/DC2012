#include "GameObject.h"

int GameObject::getObjID()
{
	return objID_;
}

int GameObject::getType()
{
	return type_;
}

Degree GameObject::getDegree()
{
	return degree_;
}

Point GameObject::getPosition()
{
	return pos_;
}