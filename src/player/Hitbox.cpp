#include "Hitbox.h"
#include <iostream>

Hitbox::Hitbox(const Point& org, const double& width, const double& height)
{
	double leftX 	= org.getX() - (width/2);
	double rightX 	= org.getX() + (width/2);
	double topY 	= org.getY() + (height/2);
	double bottomY = org.getY() - (height/2);

	tLeft_.setX(leftX);
	tLeft_.setY(topY);

	tRight_.setX(rightX);
	tRight_.setY(topY);

	bLeft_.setX(leftX);
	bLeft_.setY(bottomY);

	bRight_.setX(rightX);
	bRight_.setY(bottomY);
}

void Hitbox::print(std::ostream& os)const
{
	os << "**Hitbox**\n" << std::endl;
	os << "Top left:\t";
	tLeft_.print(os);
	os << std::endl << "Top right:\t";
	tRight_.print(os);
	os << std::endl << "Bottom left:\t";
	bLeft_.print(os);
	os << std::endl << "Bottom right:\t";
	bRight_.print(os);
	os << std::endl << std::endl;
}

bool
Hitbox::isCollision(const Hitbox& other)
{
	/* Top Left Point inside of box */
	if(other.tLeft_.getY() < tLeft_.getY() && other.tLeft_.getY() > bRight_.getY()
	&& other.tLeft_.getX() > tLeft_.getX() && other.tLeft_.getX() < bRight_.getX())
		return true;
	/* Bottom Right Point inside of box */
	if(other.bRight_.getY() > tLeft_.getY() && other.bRight_.getY() > bRight_.getY()
	&& other.bRight_.getX() > tLeft_.getX() && other.bRight_.getX() < bRight_.getX())
		return true;
	/* Bottom Left Point inside of box */
	if(other.bLeft_.getY() < tRight_.getY() && other.bLeft_.getY() > bLeft_.getY()
	&& other.bLeft_.getX() > tLeft_.getX() && other.bLeft_.getX() < bRight_.getX())
		return true;
	/* Top Right Point inside of box */
	if(other.tRight_.getY() < tRight_.getY() && other.tRight_.getY() > bRight_.getY()
	&& other.tRight_.getX() > tLeft_.getX() && other.tRight_.getX() < bRight_.getX())
		return true;
	return false;
}