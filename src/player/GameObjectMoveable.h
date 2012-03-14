/*----------------------------------------------------------------------
--	CLASS NAME:
--					GameObjectMoveable
--	PARENT CLASS:
--					GameObject
--	CONSTRUCTOR:
--
--	DESTROCTOR:
--
--	FUNCTIONS:
--
--	DATE:
--					March 9, 2012
--	REVISIONS:
--					March 14, 2012 (Roger)
--						- switched to using double type in Point & Degree
--
--	DESIGNER:
--					Aiko Rose
--					Po Hsu
--					Roger Fan
--					Zach Smoroden
--	PROGRAMMER:
--					Aiko Rose
--					Po Hsu
--					Roger Fan
--					Zach Smoroden
--	NOTES:
----------------------------------------------------------------------*/
#ifndef GAMEOBJECTMOVEABLE_H_
#define GAMEOBJECTMOVEABLE_H_

#include "GameObject.h"

class GameObjectMoveable : public GameObject
{
	protected:
		int playerID_;
		int speed_;
	public:
		explicit GameObjectMoveable(int objID, int type, double degree, double posX, double posY, int playerID, int speed)
		:GameObject(objID, type, degree, posX, posY), playerID_(playerID), speed_(speed){}

		// destructor
		virtual ~GameObjectMoveable(){}

		// getters
		int getPlayerID()const;
		int getSpeed()const;

		virtual void accelerate(int amount) = 0;
		virtual void decelerate(int amount) = 0;

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif