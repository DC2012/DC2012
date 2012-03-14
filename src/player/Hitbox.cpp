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