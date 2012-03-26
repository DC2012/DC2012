/*----------------------------------------------------------------------
--	CLASS NAME:
--					Hitbox
--	CONSTRUCTOR:
--					Hitbox(const Point& org, const int& width, const int& height);
--	DESTROCTOR:
--					Default
--	FUNCTIONS:
--					void print(std::ostream &os)
--	DATE:
--					March 12, 2012
--	REVISIONS:
--					March 14, 2012 (Roger)
--						- switched to using double type for width & height
--
--	DESIGNER:
--					Po Hsu
--	PROGRAMMER:
--					Po Hsu
--					Roger Fan
--	NOTES:
----------------------------------------------------------------------*/
#ifndef HITBOX_H
#define HITBOX_H
#include "Point.h"

class Hitbox
{
	private:
		Point tLeft_, tRight_, bLeft_, bRight_;

	public:
		// constructor
		// width and height will be provided by the Graphics object
		Hitbox(const Point& org, const double& width, const double& height);

		// destructor
		~Hitbox() {}

		// for testing purposes
		void print(std::ostream& os) const;
};

#endif