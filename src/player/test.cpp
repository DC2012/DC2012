#include "Point.h"
//#include "GameObject.h"
#include <iostream>
using namespace std;

// testing functionality of the Point class 2012/03/01
int main()
{
	Point p(12,34);
	p.print(cout);	// Point x(12) y(34)
	Point p2(-11, -33);
	p += p2;
	p.print(cout);	// Point x(1) y(1)
}