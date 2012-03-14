#include "Point.h"
#include <cmath>

const double PI = 4.0 * atan(1.0);

void rotatePointAround(Point &pt, const Point &centre_pt, const double &degree)
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

Point getDirectionalPoint(double move_distance, double degree)
{
	Point centre(0.0, 0.0), pt(move_distance, 0.0);
	rotatePointAround(pt, centre, degree);
	
	return pt;
}