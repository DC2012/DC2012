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
		explicit GameObjectStationary(int objID, int type, int degree, int posX, int posY)
		:GameObject(objID, type, degree, posX, posY){}

		// for testing purposes
		virtual void print(std::ostream& os) const;
};

#endif