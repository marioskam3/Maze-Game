#ifndef Lucas_h
#define Lucas_h

#include "Moving.h"

class Lucas : public Moving
{
	private :
		
	public :
		Lucas (unsigned int nLy,unsigned int nLx);
        ~Lucas ();
		int getMove() override ;
		
};

#endif