/*----------------------------------------------------------------------
--	CLASS NAME:
--					GameObjectFactory
--	CONSTRUCTOR:
--
--	DESTROCTOR:
--
--	FUNCTIONS:
--
--	DATE:
--					March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--					Zach Smoroden
--	PROGRAMMER:
--					Zach Smoroden
--	NOTES:
----------------------------------------------------------------------*/
#ifndef GAMEOBJECTMOVEABLE_H_
#define GAMEOBJECTMOVEABLE_H_

#include "GameObjectMoveable.h"
#include "GameObjectStationary.h"
#include "GameObject.h"

class GameObjectFactory
{
	public:
		//empty constructor, takes in a istream
		GameObjectFactory(std::istream& is): in_(&is) {}
		//call to create the new object
		GameObject *create()
		{
			std::string type;
			int objID, degree, posX, posY, playerID, speed, health, ttl, damage, attackPower;
			if (!(*in_ >> type))
			  return 0;
			if (type == "P")
			{
				*in_ >> objID >> degree >> posX >> playerID >> speed >> ttl >> damage;
				return new GOM_Projectile(objId, degree, posX, posY, playerID, speed, ttl, damage);
			}
			  
			if (type == "S")
			{
				*in_ >> objID >> degree >> posX >> playerID >> speed >> health >> attackPower;
				return new GOM_Ship(objId, degree, posX, posY, playerID, speed, health, attackPower);
			}
			  
			if (type == "O")
			{
				return new GOS_Obstacle(*in_);
			}
			  
			if (type == "B")
			{
				return new GOS_Powerup(*in_);
			}
			
			return 0;  // if it's not one of the valid types
		}
	private:
		std::istream  *in_;  

};

#endif