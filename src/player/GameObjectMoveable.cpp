#include "GameObjectMoveable.h"

int GameObjectMoveable::getPlayerID()const
{
	return playerID_;
}

int GameObjectMoveable::getSpeed()const
{
	return speed_;
}

void GameObjectMoveable::print(std::ostream& os)const
{
	GameObject::print(os);
	os << "playerID:\t" << playerID_ << std::endl;
	os << "speed:\t\t" << speed_ << std::endl;
}