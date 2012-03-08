#ifndef GAMEOBJECTMOVEABLE_H_
#define GAMEOBJECTMOVEABLE_H_

#include "GameObject.h"
//#include "Direction.h"

class GameObjectMoveable : public GameObject
{
	protected:
		int playerID_;
		//Direction dir_;
		int speed_;
	public:
		explicit GameObjectMoveable(int playerID, int speed)
		: playerID_(playerID), speed_(speed){}
		//virtual void Accelerate() = 0;
		//virtual void Decelerate() = 0;
		//virtual GOPos Position() = 0;
};

#endif