#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Sprite.h"
#include "GOPos.h"

// Abstract Base Class
class GameObject
{
	protected:
		int GObjID;
		GOPos pos;
		Sprite sprite;
	public:
		virtual GOPos Position() = 0;
};

#endif