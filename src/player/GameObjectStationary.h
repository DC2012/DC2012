#ifndef GAMEOBJECTSTATIONARY_H_
#define GAMEOBJECTSTATIONARY_H_

#include "GameObject.h"

class GameObjectStationary : public GameObject
{
	protected:
	public:
		virtual GOPos Position() = 0;
};

#endif