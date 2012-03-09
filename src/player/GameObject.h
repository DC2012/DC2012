#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Point.h"
#include "Degree.h"
#include <iostream>

// Abstract Base Class
class GameObject
{
	protected:
		int objID_;
		Degree degree_;
		Point pos_;

	public:
		// constructor
		// explicit to indicate no implicit conversion
		explicit GameObject(int objID, int degree, int posX, int posY)
		:objID_(objID), degree_(degree), pos_(posX, posY){}

		// default destructor
		virtual ~GameObject(){}

		// getters
		int getObjID();
		Degree getDegree();
		Point getPosition();
};

#endif