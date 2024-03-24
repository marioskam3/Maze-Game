#ifndef Moving_h
#define Moving_h
#include <curses.h>

class Moving
{	
    protected: 
        unsigned int x;
        unsigned int y;
	public :
		Moving();
        virtual ~Moving();
		virtual int getMove ()=0;
        void setx(unsigned int nx);
		void sety(unsigned int ny);
		unsigned int getx() const;
		unsigned int gety() const;
};

#endif