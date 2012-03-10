#include "GameObjectMoveable.h"

void GameObjectMoveable::print(std::ostream& os)const
{
	GameObject::print(os);
	os << "playerID:\t" << playerID_ << std::endl;
	os << "speed:\t\t" << speed_ << std::endl;
}