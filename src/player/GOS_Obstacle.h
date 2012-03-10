/*----------------------------------------------------------------------
--	CLASS NAME:
--					GOS_Obstacle
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
#ifndef GOS_OBSTACLE_H_
#define GOS_OBSTACLE_H_

#include "GameObjectStationary.h"

class GOS_Obstacle : public GameObjectStationary
{
	private:
	public:
		// constructor for now
		explicit GOS_Obstacle(int objID = 0, int degree = 0, int posX = 0, int posY = 0);

		// destructor
		virtual ~GOS_Obstacle(){}

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif