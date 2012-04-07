#include "GameObjectFactory.h"

GameObject* GameObjectFactory::create(const std::string &in)
{
	std::istringstream istr(in);
	char endCheck;
	int type = -1;
	int objID, degree, posX, posY, playerID, speed, health, attackPower, 
		damage, ttl;
	
	istr >> type;
	switch(ObjectType(type))
	{
	case SHIP1:
	case SHIP2:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> health
			>> attackPower >> endCheck;
		
		if(!istr.good() || endCheck != SHIP_STR)
			break;
		
		return new GOM_Ship(ObjectType(type), objID, double(degree), double(posX),
			double(posY), playerID, double(speed), health, attackPower);
		
	case PROJECTILE:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl >> 
			damage >> endCheck;
			
		if(!istr.good() || endCheck != PROJECTILE_STR)
			break;
		
		return new GOM_Projectile(ObjectType(type), objID, double(degree), 
			double(posX), double(posY), playerID, double(speed), ttl, damage);
		
	case OBSTACLE:
		istr >> objID >> degree >> posX >> posY >> endCheck;
		
		if(!istr.good() || endCheck != OBSTACLE_STR)
			break;
			
		return new GOS_Obstacle(ObjectType(type), objID, double(degree), 
			double(posX), double(posY));
		
	case POWERUP:
		istr >> objID >> degree >> posX >> posY >> endCheck;
		
		if(!istr.good() || endCheck != POWERUP_STR)
			break;
			
		return new GOS_PowerUp(ObjectType(type), objID, double(degree), 
			double(posX), double(posY));
	}
	return NULL;
}

int GameObjectFactory::getObjectID(const std::string &str)
{
	std::istringstream istr(str);
	char endCheck;
	int type = -1;
	int objID, degree, posX, posY, playerID, speed, health, attackPower, 
		damage, ttl;
	
	istr >> type;
	switch(ObjectType(type))
	{
	case SHIP1:
	case SHIP2:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> health
			>> attackPower >> endCheck;
		
		if(!istr.good() || endCheck != SHIP_STR)
			break;
		
		return objID;
		
	case PROJECTILE:
		istr >> objID >> degree >> posX >> posY >> playerID >> speed >> ttl >> 
			damage >> endCheck;
			
		if(!istr.good() || endCheck != PROJECTILE_STR)
			break;
		
		return objID;
		
	case OBSTACLE:
		istr >> objID >> degree >> posX >> posY >> endCheck;
		
		if(!istr.good() || endCheck != OBSTACLE_STR)
			break;
			
		return objID;
		
	case POWERUP:
		istr >> objID >> degree >> posX >> posY >> endCheck;
		
		if(!istr.good() || endCheck != POWERUP_STR)
			break;
			
		return objID;
	}
	
	// returns -1 if invalid object string is passed in
	return -1;
}