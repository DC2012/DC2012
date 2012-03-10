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

#include "Point.h"
#include "Degree.h"
#include <iostream>

// Abstract Base Class
class GameObject
{
	protected:
		int objID_;
		int type_;
		Degree degree_;
		Point pos_;

	public:
		// constructor
		// explicit to indicate no implicit conversion
		explicit GameObject(int objID, int type, int degree, int posX, int posY)
		:objID_(objID), type_(type), degree_(degree), pos_(posX, posY){}

		// default destructor
		virtual ~GameObject(){}

		// getters
		int getObjID();
		int getType();
		Degree getDegree();
		Point getPosition();

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif