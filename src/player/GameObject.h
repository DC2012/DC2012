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
		explicit GameObject(int objID,
							int posX,
							int posY)
		: objID_(objID), pos_(posX, posY){}

		// default destructor
		virtual ~GameObject(){}

		// getters
		virtual int getGObjID() const;
		virtual int getSpriteID() const;
		virtual Point getPosition() const;

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif