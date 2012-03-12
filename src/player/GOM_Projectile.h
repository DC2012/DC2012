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
		explicit GOM_Projectile(int objID = 0, int type = 0, int degree = 0, int posX = 0, int posY = 0, 
			int playerID = 0, int speed = 0, int ttl = 0, int damage = 0);

		// destructor
		virtual ~GOM_Projectile(){}

		// inherited from GameObjectMoveable
		virtual void accelerate(int amount);
		virtual void decelerate(int amount);

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif