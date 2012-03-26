/*----------------------------------------------------------------------
--	CLASS NAME:
--					GameObject
--	CONSTRUCTOR:
--					GameObject(int objID, int degree, int posX, int posY)
--	DESTROCTOR:
--					~GameObject()
--	FUNCTIONS:
--
--	DATE:
--					March 9, 2012
--	REVISIONS:
--					March 14, 2012 (Roger)
--						- switched to using double type in Point & Degree
--
--	DESIGNER:
--					Aiko Rose
--					Po Hsu
--					Roger Fan
--					Zach Smoroden
--	PROGRAMMER:		
--					Aiko Rose
--					Po Hsu
--					Roger Fan
--					Zach Smoroden
--	NOTES:
----------------------------------------------------------------------*/
#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "ObjectType.h"
#include "Point.h"
#include "Degree.h"
#include "Hitbox.h"
#include "../../sprites/sprites.h"
#include <iostream>

// Abstract Base Class
class GameObject
{
	protected:
		int objID_;
		ObjectType type_;
		Degree degree_;
		Point pos_;
		Point spritePt_;
		Hitbox hb_;

	public:
		// constructor
		// explicit to indicate no implicit conversion
        explicit GameObject(int objID, ObjectType type, double degree, double posX, double posY);

		// default destructor
		virtual ~GameObject(){}

		// getters
		int getObjID() const;
		int getType() const;
		double getDegree() const;
		Point getPosition() const;

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif
