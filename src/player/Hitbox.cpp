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

bool Hitbox::isCollisionNew(Hitbox other, Point shipPos, double shipDegree)
{
    rotatePointAround(other.tLeft, shipPos, -shipDegree);
    rotatePointAround(other.tRight, shipPos, -shipDegree);
    rotatePointAround(other.bLeft, shipPos, -shipDegree);
    rotatePointAround(other.bRight, shipPos, -shipDegree);

    if(other.tLeft.getX() >= tLeft.getX() && other.tLeft.getX() <= tRight.getX()
    && other.tLeft.getY() <= tLeft.getY() && other.tLeft.getY() >= bLeft.getY())
        return true;
    if(other.tRight.getX() >= tLeft.getX() && other.tRight.getX() <= tRight.getX()
    && other.tRight.getY() <= tLeft.getY() && other.tRight.getY() >= bLeft.getY())
        return true;
    if(other.bLeft.getX() >= tLeft.getX() && other.bLeft.getX() <= tRight.getX()
    && other.bLeft.getY() <= tLeft.getY() && other.bLeft.getY() >= bLeft.getY())
        return true;
    if(other.bRight.getX() >= tLeft.getX() && other.bRight.getX() <= tRight.getX()
    && other.bRight.getY() <= tLeft.getY() && other.bRight.getY() >= bLeft.getY())
        return true;
    return false;
}

void Hitbox::rotatePointAround(Point &pt,
    const Point &centre_pt, const double &degree)
{
        double radians = degree * (PII / 180.0);
        double pt_x = pt.getX();
        double pt_y = pt.getY();

        // translate pt_x and pt_y so centre_pt becomes the origin (0, 0)
        pt_x += -centre_pt.getX();
        pt_y += -centre_pt.getY();

        // rotate the point
        pt.setX((pt_x * cos(radians) - pt_y * sin(radians)));
        pt.setY((pt_x * sin(radians) + pt_y * cos(radians)));

        // translate the point back
        pt.setX(pt.getX() + centre_pt.getX());
        pt.setY(pt.getY() + centre_pt.getY());
}
