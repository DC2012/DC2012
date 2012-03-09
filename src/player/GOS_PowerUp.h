#ifndef GOS_POWERUP_H_
#define GOS_POWERUP_H_

#include "GameObjectStationary.h"

class GOS_PowerUp : public GameObjectStationary
{
	private:
	public:
		// constructor for now.. will be adding more stuffs to the class later
		explicit GOS_PowerUp(int objID, int degree, int posX, int posY)
		:GameObject(objID, degree, posX, posY){}
};

#endif