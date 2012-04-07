#include "Hitbox.h"
#include <iostream>

Hitbox::Hitbox(const Point& org, const double& width, const double& height)
{
	double leftX 	= org.getX() - (width/2);
	double rightX 	= org.getX() + (width/2);
	double topY 	= org.getY() - (height/2);
	double bottomY = org.getY() + (height/2);

	tLeft.setX(leftX);
	tLeft.setY(topY);

	tRight.setX(rightX);
	tRight.setY(topY);

	bLeft.setX(leftX);
	bLeft.setY(bottomY);

	bRight.setX(rightX);
	bRight.setY(bottomY);
}

void Hitbox::print(std::ostream& os)const
{
	os << std::endl  << "**Hitbox**" << std::endl;
	os << "Top left:\t";
	tLeft.print(os);
	os << "Top right:\t";
	tRight.print(os);
	os << "Bottom left:\t";
	bLeft.print(os);
	os << "Bottom right:\t";
	bRight.print(os);
	os << std::endl;
}

bool
Hitbox::isCollision(const Hitbox& other)
{
	/* Top Left Point inside of box */
	if(other.tLeft.getY() > tLeft.getY() && other.tLeft.getY() < bRight.getY()
	&& other.tLeft.getX() > tLeft.getX() && other.tLeft.getX() < bRight.getX())
		return true;
	/* Bottom Right Point inside of box */
	if(other.bRight.getY() > tLeft.getY() && other.bRight.getY() < bRight.getY()
	&& other.bRight.getX() > tLeft.getX() && other.bRight.getX() < bRight.getX())
		return true;
	/* Bottom Left Point inside of box */
	if(other.bLeft.getY() > tRight.getY() && other.bLeft.getY() < bLeft.getY()
	&& other.bLeft.getX() > tLeft.getX() && other.bLeft.getX() < bRight.getX())
		return true;
	/* Top Right Point inside of box */
	if(other.tRight.getY() > tRight.getY() && other.tRight.getY() < bRight.getY()
	&& other.tRight.getX() > tLeft.getX() && other.tRight.getX() < bRight.getX())
		return true;
	return false;
}