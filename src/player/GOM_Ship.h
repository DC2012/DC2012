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

class GOM_Ship : public GameObjectMoveable
{
	private:
		int health_;
		int attackPower_;
		static size_t shipCount_;
		
	public:
		//constructor
		explicit GOM_Ship(int GObjID = 0, int degree = 0, int posX = 0, int posY = 0, 
			int playerID = 0, int speed = 0, int health = 0, int attackPower = 0);
		// destructor
		virtual ~GOM_Ship(){}

		// inherited from GameObjectMoveable
		virtual void accelerate(int amount);
		virtual void decelerate(int amount);

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif