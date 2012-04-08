/*-----------------------------------------------------------------------------
--	CLASS NAME:
--					GameObjectMoveable
--	PARENT CLASS:
--					GameObject
--	CONSTRUCTOR:
--					GameObjectMoveable(int objID, ObjectType type, double degree,
--						double posX, double posY, int playerID, double speed)
--	DESTROCTOR:
--
--	DATA MEMBER:
--					private:
--						int playerID_
--						double speed_;
--	FUNCTIONS:
--					public:
--						int getPlayerID()
--						double getSpeed()
--						void rotatePointAround(Point &pt, const Point &centre_pt, 
--							const double &degree)
--						Point getDirectionalPoint(double distance, double degree)
--
--	DATE:
--					March 9, 2012
--	REVISIONS:
--					March 14, 2012 (Roger)
--						- switched to using double type in Point & Degree & speed
--						- implemented object movement functions
--						- removed accelerate() & decelerate(), they'll be
--						implemented in GOM_Ship class
--                  April 4, 2012 (Po)
--                      - modified constructor so that 'type' will be the first
--                        parameter
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
-----------------------------------------------------------------------------*/
#ifndef GAMEOBJECTMOVEABLE_H_
#define GAMEOBJECTMOVEABLE_H_

#include "GameObject.h"
#include <cmath>
#include <string>
#include <sstream>

const double PI = 4.0 * atan(1.0);

class GameObjectMoveable : public GameObject
{
	protected:
		int 	playerID_;
		double 	speed_; // speed's unit is pixel
	public:
		explicit GameObjectMoveable(ObjectType type, int objID, double degree, double posX, double posY, int playerID, double speed)
		:GameObject(type, objID, degree, posX, posY), playerID_(playerID), speed_(speed){}

/*-----------------------------------------------------------------------------
--	FUNCTION:
--				getPlayerID
--	DATE:
--				March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--				Roger Fan
--	PROGRAMMER:
--				Roger Fan
--	INTERFACE:
--				int getPlayerID() const
--	RETURNS:
--				Returns playerID_ variable.
--	NOTES:
-----------------------------------------------------------------------------*/
		int getPlayerID() const;
		
/*-----------------------------------------------------------------------------
--	FUNCTION:
--				getSpeed
--	DATE:
--				March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--				Roger Fan
--	PROGRAMMER:
--				Roger Fan
--	INTERFACE:
--				double getSpeed() const
--	RETURNS:
--				Returns speed_ variable.
--	NOTES:
-----------------------------------------------------------------------------*/
		double getSpeed() const;
		
/*-----------------------------------------------------------------------------
--	FUNCTION:
--				rotatePointAround
--	DATE:
--				March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--				Roger Fan
--	PROGRAMMER:
--				Roger Fan
--	INTERFACE:
--				void rotatePointAround(Point &pt, const Point &centre_pt, 
--					const double &degree)
--	RETURNS:
--				void
--	NOTES:
--				This function operates on parameter pt. It updates the (x, y)
--				coordinates of Point pt to the position after it rotates around
--				Point centre_pt for the number of degree specified.
-----------------------------------------------------------------------------*/
		void rotatePointAround(Point &pt, const Point &centre_pt, const double &degree);
		
/*-----------------------------------------------------------------------------
--	FUNCTION:
--				getDirectionalPoint
--	DATE:
--				March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--				Roger Fan
--	PROGRAMMER:
--				Roger Fan
--	INTERFACE:
--				Point getDirectionalPoint(double distance, double degree)
--	RETURNS:
--				Returns a Point object.
--	NOTES:
--				Example of this function's usage:
--				
--				Point a(2, 2);
--				Point temp = getDirectionalPoint(10, 30);
--				a += temp;
--
--				Point a now has moved 10 units into 30 degree direction.
-----------------------------------------------------------------------------*/
		Point getDirectionalPoint(double distance, double degree);
        
        // rotate hitbox
		void rotateHitbox(double degree);
		// move hitbox
		void moveHitbox(double x, double y);
		
		virtual void update(const std::string &str) = 0;
		virtual std::string toString() const = 0;

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif