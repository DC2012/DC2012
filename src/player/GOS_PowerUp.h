/*----------------------------------------------------------------------
--	CLASS NAME:
--					GOS_PowerUp
--	PARENT CLASS:
--					GameObjectStationary
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
#ifndef GOS_POWERUP_H_
#define GOS_POWERUP_H_

#include "GameObjectStationary.h"

class GOS_PowerUp : public GameObjectStationary
{
	private:
		static size_t powerUpCount_;
	public:
		// constructor for now
		explicit GOS_PowerUp(int objID = 0, ObjectType type = POWERUP, double degree = 0, double posX = 0, double posY = 0);

		// destructor
		virtual ~GOS_PowerUp(){}

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif