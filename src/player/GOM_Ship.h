#ifndef GOM_SHIP_H_
#define GOM_SHIP_H_

#include "GameObjectMoveable.h"

class GOM_Ship : public GameObjectMoveable
{
	private:
		int health_;
		int attackPower_;
		
	public:
		//constructor
		explicit GOM_Ship(int GObjID = 0, int degree = 0, int posX = 0, int posY = 0, 
			int playerID = 0, int speed = 0, int health = 0, int attackPower = 0);
		// destructor
		virtual ~GOM_Projectile(){}

		// inherited from GameObjectMoveable
		virtual void accelerate(int amount);
		virtual void decelerate(int amount);

		//for testing
		virtual void print(std::ostream& os) const;
};

#endif