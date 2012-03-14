#include "Hitbox.h"
#include <cstdio>

int main()
{
	Point org(0,0);

	Hitbox hb(org, 30, 40);
	hb.print(std::cout);
	getchar();
}