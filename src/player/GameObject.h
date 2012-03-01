#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Point.h"
#include <iostream>

// Abstract Base Class
class GameObject
{
	private:			// private vairables will be inherited as well, no need for protected
		int GObjID_;
		int spriteID_;
		Point pos_;

	public:
		// constructor
		// explicit to indicate no implicit conversion
		explicit GameObject(const int GObjID = 0,
							const int spriteID = 0,
							const int posX = 0,
							const int poxY = 0);

		// default destructor
		virtual ~GameObject(){}

		// getters
		int getGObjID() const;
		int getSpriteID() const;
		virtual Point& getPosition() const;

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif