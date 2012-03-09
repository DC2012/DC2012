/*----------------------------------------------------------------------
--	SORCE FILE:
--
--	CLASS NAME:
--
--	CONSTRUCTOR:
--
--	DESTROCTOR:
--
--	FUNCTIONS:
--
--	DATE:
--
--	REVISIONS:
--
--	DESIGNERS:
--
--	PROGRAMMER:
--
--	NOTES:
----------------------------------------------------------------------*/
#ifndef GOS_OBSTACLE_H_
#define GOS_OBSTACLE_H_

#include "GameObjectStationary.h"

class GOS_Obstacle : public GameObjectStationary
{
	private:
	public:
		// constructor for now.. will be adding more stuffs to the class later
		explicit GOS_Obstacle(int objID, int degree, int posX, int posY)
		:GameObject(objID, degree, posX, posY){}
};

#endif