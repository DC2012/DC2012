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
#ifndef GAMEOBJECTFACTORY_H_
#define GAMEOBJECTFACTORY_H_

#include <string>
#include <sstream>
#include "GOM_Projectile.h"
#include "GOM_Ship.h"
#include "GOS_Obstacle.h"
#include "GOS_PowerUp.h"
#include "ObjectType.h"
#include "ObjectStringCheck.h"

class GameObjectFactory
{
	public:
		// call to create the new object
		static GameObject *create(const std::string &in);
		
		// retrieves the object ID from an object string
		// returns -1 if invalid object string is passed in
		static int getObjectID(const std::string &str);
};

#endif