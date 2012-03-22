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
--					March 14, 2012 (Roger)
--						- added type casts for double values
--
--	DESIGNER:
--					Zach Smoroden
--	PROGRAMMER:
--					Zach Smoroden
--					Roger Fan
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
            int type;
			if (!(*in_ >> type))
			  return 0;
            //Projectile
			if (type == "P")
			{
				*in_ >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl >> damage;
				return new GOM_Projectile(objId, double(degree), double(posX), double(posY), playerID, double(speed), ttl, damage);
			}
			//Ship
			if (type == "S")
			{
				*in_ >> objID >> degree >> posX >> posY >> playerID >> speed >> health >> attackPower;
				return new GOM_Ship(objId, double(degree), double(posX), double(posY), playerID, double(speed), health, attackPower);
			}
			//Obstacle  
			if (type == "O")
			{
                *in_ >> objID >> type >> degree >> posX >> posY;
				return new GOS_Obstacle(objId, type, double(degree), double(posX), double(posY));
			}
			//Powerup  
			if (type == "B")
			{
                *in_ >> objID >> type >> degree >> posX >> posY;
				return new GOS_Powerup(objId, type, double(degree), double(posX), double(posY));
			}
			
			return 0;  // if it's not one of the valid types
		}
	private:
		std::istream  *in_;  

};

#endif