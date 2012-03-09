#ifndef GAMEOBJECTSTATIONARY_H_
#define GAMEOBJECTSTATIONARY_H_

#include "GameObject.h"

class GameObjectStationary : public GameObject
{
	protected:
	public:
		explicit GameObjectStationary(	int objID,
										int degree,
										int posX,
										int posY)
		:GameObject(objID, degree, posX, posY){}
};

#endif