#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#include "Mpampis.h"

Mpampis::Mpampis(unsigned int nMy,unsigned int nMx,unsigned int nSy,unsigned int nSx,vector <string> &nmap)
{
	x=nMx;
	y=nMy;
    Sx=nSx;
	Sy=nSy;
	map=nmap;
}

Mpampis::~Mpampis()
{

}

int Mpampis::getMove() 
{
	int dx = Sx - x;
    int dy = Sy - y;

    if (dx > 0 && map[y][x + 1] != '*')
        return RIGHT;
    else if (dx < 0 && map[y][x - 1] != '*')
        return LEFT;
    else if (dy > 0 && map[y + 1][x] != '*')
        return DOWN;
    else if (dy < 0 && map[y - 1][x] != '*')
        return UP;

    //If the initially calculated move is not valid, prioritize vertical movement
    if (dy > 0 && map[y + 1][x] != '*')
        return DOWN;
    else if (dy < 0 && map[y - 1][x] != '*')
        return UP;
    
    //If vertical movement is not possible, generate a random valid move
    int randomMove;
    do
    {
        randomMove = rand() % 4;
        switch (randomMove)
        {
            case 0: //UP
                if (map[y - 1][x] != '*')
                    return UP;
                break;
            case 1: //DOWN
                if (map[y + 1][x] != '*')
                    return DOWN;
                break;
            case 2: //RIGHT
                if (map[y][x + 1] != '*')
                    return RIGHT;
                break;
            case 3: //LEFT
                if (map[y][x - 1] != '*')
                    return LEFT;
                break;
        }
    } while (true);

    
    return 0;

}

void Mpampis::setSx(unsigned int nSx)
{
	Sx=nSx;
}

void Mpampis::setSy(unsigned int nSy)
{
	Sy=nSy;
}

unsigned int Mpampis::getSx()
{
	return Sx;
}

unsigned int Mpampis::getSy()
{
	return Sy;
}