/*----------------------------------------------------------------------
--	CLASS NAME:
--					GOM_Projectile
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
#ifndef GOM_PROJECTILE_H_
#define GOM_PROJECTILE_H_

#include "GameObjectMoveable.h"

class GOM_Projectile : public GameObjectMoveable
{
	private:
		int ttl_;
		int damage_;
		static size_t projectileCount_;
	public:
		// contructor
		explicit GOM_Projectile(int objID = 0, int type = 0, double degree = 0, double posX = 0, double posY = 0, 
			int playerID = 0, double speed = 0, int ttl = 0, int damage = 0);

		// destructor
		virtual ~GOM_Projectile(){}

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif