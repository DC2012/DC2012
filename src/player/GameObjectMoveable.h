/*----------------------------------------------------------------------
--	CLASS NAME:
--					GameObjectMoveable
--	PARENT CLASS:
--					GameObject
--	CONSTRUCTOR:
--
--	DESTROCTOR:
--
--	FUNCTIONS:
--
--	DATE:
--					March 9, 2012
--	REVISIONS:
--					March 14, 2012 (Roger)
--						- switched to using double type in Point & Degree
--						- implemented object movement functions
--						- removed accelerate() & decelerate(), they'll be
--						implemented in GOM_Ship class
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
#ifndef GAMEOBJECTMOVEABLE_H_
#define GAMEOBJECTMOVEABLE_H_

#include "GameObject.h"
#include <cmath>

const double PI = 4.0 * atan(1.0);

class GameObjectMoveable : public GameObject
{
	protected:
		int playerID_;
		int speed_;
	public:
		explicit GameObjectMoveable(int objID, int type, double degree, double posX, double posY, int playerID, int speed)
		:GameObject(objID, type, degree, posX, posY), playerID_(playerID), speed_(speed){}

		// destructor
		virtual ~GameObjectMoveable(){}

		// getters
		int getPlayerID()const;
		int getSpeed()const;
		
		// rotates Point "pt" around Point "centre_pt" by "degree" degrees
		void rotatePointAround(Point &pt, const Point &centre_pt, const double &degree);
		
		// returns a directional Point that's used to be added to another Point to
		// move it with a specifed distance and direction (degree)
		Point getDirectionalPoint(double move_distance, double degree);

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif