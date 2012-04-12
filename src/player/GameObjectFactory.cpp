#include "GameObjectFactory.h"

GameObject* GameObjectFactory::create(const std::string &in)
{
        GameObject *gameObject;
	std::istringstream istr(in);
	char endCheck;
	int type = -1;
        int objID, playerID, health, attackPower,
		damage, ttl, bonus;
        double posX, degree, posY, speed;
        double tl_x, tl_y;
        double tr_x, tr_y;
        double bl_x, bl_y;
        double br_x, br_y;
        Point tl, tr, bl, br;
	
	istr >> type;
	switch(ObjectType(type))
	{
	case SHIP1:
	case SHIP2:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> health
                        >> attackPower
                        >> tl_x >> tl_y
                        >> tr_x >> tr_y
                        >> bl_x >> bl_y
                        >> br_x >> br_y
                        >> endCheck;
		
		if(!istr.good() || endCheck != SHIP_STR)
			break;

                tl = Point(tl_x, tl_y);
                tr = Point(tr_x, tr_y);
                bl = Point(bl_x, bl_y);
                br = Point(br_x, br_y);

                gameObject = new GOM_Ship(ObjectType(type), objID, degree, posX,
                                          posY, playerID, speed, health, attackPower);
                gameObject->setHitBox(tl, tr, bl, br);
		
                return gameObject;
		
	case PROJECTILE:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl >> 
                        damage
                     >> tl_x >> tl_y
                     >> tr_x >> tr_y
                     >> bl_x >> bl_y
                     >> br_x >> br_y
                     >> endCheck;
			
		if(!istr.good() || endCheck != PROJECTILE_STR)
			break;

                tl = Point(tl_x, tl_y);
                tr = Point(tr_x, tr_y);
                bl = Point(bl_x, bl_y);
                br = Point(br_x, br_y);

                gameObject = new GOM_Projectile(ObjectType(type), objID, degree,
                                                posX, posY, playerID, speed, ttl, damage);
                gameObject->setHitBox(tl, tr, bl, br);
		
                return gameObject;
		
	case OBSTACLE:
		istr >> objID >> degree >> posX >> posY >> endCheck;
		
		if(!istr.good() || endCheck != OBSTACLE_STR)
			break;
			
                return new GOS_Obstacle(ObjectType(type), objID, degree,
                        posX, posY);
		
	case POWERUP:
		istr >> objID >> degree >> posX >> posY >> bonus >> endCheck;
		
		if(!istr.good() || endCheck != POWERUP_STR)
			break;
			
            return new GOS_PowerUp(ObjectType(type), objID, posX, posY, ttl, GOS_PowerUp::BONUS(bonus));
	}
	return NULL;
}

int GameObjectFactory::getObjectID(const std::string &str)
{
	std::istringstream istr(str);
	char endCheck;
	int type = -1;
    double degree, posX, posY, speed;
    int objID, playerID, health, attackPower,
	damage, ttl, bonus;
    double tl_x, tl_y;
    double tr_x, tr_y;
    double bl_x, bl_y;
    double br_x, br_y;
	
	istr >> type;
	switch(ObjectType(type))
	{
	case SHIP1:
	case SHIP2:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> health
                        >> attackPower
                        >> attackPower
                        >> tl_x >> tl_y
                        >> tr_x >> tr_y
                        >> bl_x >> bl_y
                        >> br_x >> br_y
                        >> endCheck;
		
		if(!istr.good() || endCheck != SHIP_STR)
			break;
		
		return objID;
		
	case PROJECTILE:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl >> 
                        damage
                     >> tl_x >> tl_y
                     >> tr_x >> tr_y
                     >> bl_x >> bl_y
                     >> br_x >> br_y
                     >> endCheck;
			
		if(!istr.good() || endCheck != PROJECTILE_STR)
			break;
		
		return objID;
		
	case OBSTACLE:
		istr >> objID >> degree >> posX >> posY >> endCheck;
		
		if(!istr.good() || endCheck != OBSTACLE_STR)
			break;
			
		return objID;
		
	case POWERUP:
		istr >> objID >> degree >> posX >> posY >> bonus >> endCheck;
		
		if(!istr.good() || endCheck != POWERUP_STR)
			break;
			
		return objID;
	}
	
	// returns -1 if invalid object string is passed in
	return -1;
}
