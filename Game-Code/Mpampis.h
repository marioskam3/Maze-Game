#ifndef Mpampis_h
#define Mpampis_h

#include "Moving.h"
#include <vector>
#include <string>

using namespace std;

class Mpampis : public Moving
{
	private :
		unsigned int Sx;
		unsigned int Sy;
		vector <string> map;
		
	public :
		Mpampis (unsigned int nMy,unsigned int nMx,unsigned int nSy,unsigned int nSx,vector <string> &nmap);
        ~Mpampis();
		int getMove() override ;
		void setSx(unsigned int nSx);
		void setSy(unsigned int nSy);
		unsigned int getSx();
		unsigned int getSy();
};

#endif