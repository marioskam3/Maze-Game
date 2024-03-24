#include "Moving.h"

Moving::Moving()
{
	
}

Moving::~Moving()
{

}

void Moving::setx(unsigned int nx)
{
	x=nx;
}

void Moving::sety(unsigned int ny)
{
	y=ny;
}

unsigned int Moving::getx() const
{
	return x;
}

unsigned int Moving::gety() const
{
	return y;
}