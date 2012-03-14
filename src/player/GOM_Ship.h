/*----------------------------------------------------------------------
--	CLASS NAME:
--					GOM_Ship
--	PARENT CLASS:
--					GameObjectMoveable
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
--						- switched to using double type in Point & Degree & speed
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
#ifndef GOM_SHIP_H_
#define GOM_SHIP_H_

#include "GameObjectMoveable.h"
#include <vector>

// array indexes for the actionFlags vector
#define ROTATE_L	0
#define ROTATE_R	1
#define ACCEL		2
#define DECEL		3
#define ACCEL_MULT	1.5
#define DECEL_MULT	0.8

class GOM_Ship : public GameObjectMoveable
{
	private:
		int health_;
		int attackPower_;
		std::vector<bool> actionFlags_;
		static size_t shipCount_;
		
	public:
		//constructor
		explicit GOM_Ship(int objID = 0, int type = 0, double degree = 0, double posX = 0, double posY = 0, 
			int playerID = 0, double speed = 0, int health = 0, int attackPower = 0);

		// destructor
		virtual ~GOM_Ship(){}

		// getters
		int getHealth()const;

		// inherited from GameObjectMoveable
		virtual void accelerate();
		virtual void decelerate();

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif