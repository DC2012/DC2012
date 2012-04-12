/*----------------------------------------------------------------------
--  CLASS NAME:
--                  GOS_PowerUp
--  PARENT CLASS:
--                  GameObjectStationary
--  CONSTRUCTOR:
--
--  DESTROCTOR:
--
--  FUNCTIONS:
--
--  DATE:
--                  March 9, 2012
--  REVISIONS:
--                  March 14, 2012 (Roger)
--                      - switched to using double type in Point & Degree
--                  April 4, 2012 (Po)
--                      - modified constructor so that 'type' will be the first
--                        parameter
--
--  DESIGNER:
--                  Aiko Rose
--                  Po Hsu
--                  Roger Fan
--                  Zach Smoroden
--  PROGRAMMER:
--                  Aiko Rose
--                  Po Hsu
--                  Roger Fan
--                  Zach Smoroden
--  NOTES:
----------------------------------------------------------------------*/
#ifndef GOS_POWERUP_H_
#define GOS_POWERUP_H_

#include "GameObjectStationary.h"

class GOS_PowerUp : public GameObjectStationary
{
    
    public:
    
    	enum BONUS
		{
			HEALTH,
			SPEED,
			DAMAGE,
			KRAKIFY,
                        SLOW,
                        NON
		};
		
        // constructor for now
        explicit GOS_PowerUp(ObjectType type = POWERUP, int objID = 0, double degree = 0, double posX = 0, double posY = 0,
        int ttl = 0, BONUS bonus = NON);

        // destructor
        virtual ~GOS_PowerUp(){}
        
        virtual void update(const std::string &str);
        virtual std::string toString() const;

        // for testing purposes
        virtual void print(std::ostream& os) const;
        
        virtual BONUS getBonus();
        
        
    private:
        static size_t powerUpCount_;
        BONUS 		  bonus_;
        int ttl_;
    
};

#endif
