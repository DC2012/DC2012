/*----------------------------------------------------------------------
--  CLASS NAME:
--                  GameObjectStationary
--  PARENT CLASS:
--                  GameObject
--  CONSTRUCTOR:
--                  GameObjectStationary(int objID, int degree, int posX, int posY)
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
#ifndef GAMEOBJECTSTATIONARY_H_
#define GAMEOBJECTSTATIONARY_H_

#include "GameObject.h"
#include <string>
#include <sstream>

class GameObjectStationary : public GameObject
{
    protected:
    public:
        explicit GameObjectStationary(ObjectType type, int objID, double degree, double posX, double posY)
        :GameObject(type, objID, degree, posX, posY){}
        
        virtual void update(const std::string &str) = 0;
        virtual std::string toString() const = 0;

        // for testing purposes
        virtual void print(std::ostream& os) const;
};

#endif