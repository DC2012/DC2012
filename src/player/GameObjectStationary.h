/*----------------------------------------------------------------------
--	CLASS NAME:
--					GameObjectStationary
--	PARENT CLASS:
--					GameObject
--	CONSTRUCTOR:
--					GameObjectStationary(int objID, int degree, int posX, int posY)
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
#ifndef GAMEOBJECTSTATIONARY_H_
#define GAMEOBJECTSTATIONARY_H_

#include "GameObject.h"

class GameObjectStationary : public GameObject
{
	protected:
	public:
		explicit GameObjectStationary(int objID, int type, double degree, double posX, double posY)
		:GameObject(objID, type, degree, posX, posY){}

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif