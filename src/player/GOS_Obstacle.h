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
#ifndef GOS_OBSTACLE_H_
#define GOS_OBSTACLE_H_

#include "GameObjectStationary.h"

class GOS_Obstacle : public GameObjectStationary
{
	private:
		static size_t obstacleCount_;
	public:
		// constructor for now
		explicit GOS_Obstacle(int objID = 0, ObjectType type = OBSTACLE, double degree = 0, double posX = 0, double posY = 0);

		// destructor
		virtual ~GOS_Obstacle(){}

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif