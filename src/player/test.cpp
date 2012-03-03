#include "Point.h"
#include "GameObject.h"
#include <iostream>

// testing functionality of the Point and GameObject class 2012/03/01
int main()
{
	GameObject go(1,2,3,4) ;
	go.print(std::cout);
	go.getPosition().print(std::cout);
}