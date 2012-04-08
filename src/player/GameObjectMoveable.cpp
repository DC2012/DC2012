#include "GameObjectMoveable.h"

int GameObjectMoveable::getPlayerID()const
{
	return playerID_;
}

double GameObjectMoveable::getSpeed()const
{
	return speed_;
}

void GameObjectMoveable::print(std::ostream& os)const
{
	GameObject::print(os);
	os << "playerID:\t" << playerID_ << std::endl;
	os << "speed:\t\t" << speed_ << std::endl;
}

void GameObjectMoveable::rotatePointAround(Point &pt, 
	const Point &centre_pt, const double &degree)
{
	double radians = degree * (PI / 180.0);
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

Point GameObjectMoveable::getDirectionalPoint(double distance, double degree)
{
	Point centre(0.0, 0.0), pt(distance, 0.0);
	rotatePointAround(pt, centre, degree);
	
	return pt;
}

void GameObjectMoveable::rotateHitbox(double degree)
{
	rotatePointAround(hb_.tLeft, pos_, degree);
	rotatePointAround(hb_.tRight, pos_, degree);
	rotatePointAround(hb_.bLeft, pos_, degree);
	rotatePointAround(hb_.bRight, pos_, degree);
}

void GameObjectMoveable::moveHitbox(double x, double y)
{
	// tLeft
	hb_.tLeft.setX(hb_.tLeft.getX() + x);
	hb_.tLeft.setY(hb_.tLeft.getY() + y);
	// tRight
	hb_.tRight.setX(hb_.tRight.getX() + x);
	hb_.tRight.setY(hb_.tRight.getY() + y);
	// bLeft
	hb_.bLeft.setX(hb_.bLeft.getX() + x);
	hb_.bLeft.setY(hb_.bLeft.getY() + y);
	// bRight
	hb_.bRight.setX(hb_.bRight.getX() + x);
	hb_.bRight.setY(hb_.bRight.getY() + y);
}