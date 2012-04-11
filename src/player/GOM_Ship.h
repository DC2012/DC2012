/*----------------------------------------------------------------------
--  CLASS NAME:
--                  GOM_Ship
-- PARENT CLASS:
--                  GameObjectMoveable
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
--                      - switched to using double type in Point & Degree & speed
--                  April 6, 2012 (Po)
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
#ifndef GOM_SHIP_H_
#define GOM_SHIP_H_

#include "GameObjectMoveable.h"
#include <vector>

// array indexes for the actionFlags vector
#define ROTATE_L    0
#define ROTATE_R    1
#define ACCEL       2
#define DECEL       3

class GOM_Ship : public GameObjectMoveable
{
    private:
        int health_;
        int attackPower_;
        std::vector<bool> actionFlags_;
        static size_t shipCount_;
        double accel_;
        double decel_;
        double maxSpeed_;
        
        // movement
        void accelerate();
        void decelerate();
        
    public:
        //constructor
        explicit GOM_Ship(ObjectType type = SHIP1, int objID = 0, double degree = 0, double posX = 0, double posY = 0, 
            int playerID = 0, double speed = 0, int health = 0, int attackPower = 0);

        // destructor
        virtual ~GOM_Ship(){}

        // getters
        int getHealth()const;

        // movement
        void move();
        
        // set actionFlags_
        void setActionFlag(int flag, bool val);

        // returns false if health is <= 0
        bool takeDamage(int dmg);
        
        virtual void update(const std::string &str);
        virtual std::string toString() const;

        // for testing purposes
        virtual void print(std::ostream& os) const;
};

#endif
