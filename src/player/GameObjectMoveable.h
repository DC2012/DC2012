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
		explicit GameObjectMoveable(int objID,
									int degree,
									int posX,
									int posY,
									int playerID,
									int speed)
		: GameObject(objID, degree, posX, posY), playerID_(playerID), speed_(speed){}
		virtual void accelerate(int amount) = 0;
		virtual void decelerate(int amount) = 0;
};

#endif