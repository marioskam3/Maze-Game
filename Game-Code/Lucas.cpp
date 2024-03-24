#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define ESC 9
#define SPACE 0
#define FAIL 3

#include "Lucas.h"

Lucas::Lucas(unsigned int nLy,unsigned int nLx)
{
	x=nLx;
	y=nLy;
}

Lucas::~Lucas()
{

}

int Lucas::getMove() 
{
	int ch;
	
	ch=getch();
	
	switch (ch)
	{
	    case KEY_UP :  return UP;
		case KEY_DOWN :  return DOWN;
		case KEY_LEFT:  return LEFT;
		case KEY_RIGHT: return RIGHT;
	    case 0x1b : return ESC;
	    case 0x20 : return SPACE;
		default : return FAIL;
	}
	
	

}

