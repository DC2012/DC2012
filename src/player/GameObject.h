#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Point.h"

// Abstract Base Class
class GameObject
{
	protected:
		int GObjID;
		int spriteID;
		Point pos;
	public:
		virtual GOPos Position() = 0;
};

#endif