#ifndef GameEngine_h
#define GameEngine_h
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <ncurses.h>
#include "Lucas.h"
#include "Mpampis.h"


using namespace std;

class GameEngine 
{
    private :
        vector<string> map;
        unsigned int rows;
        unsigned int cols;
        vector<pair<unsigned int, unsigned int>> coordinates;

    public :
        //constructor 
		GameEngine();
        
        //destructor
        ~GameEngine();

        //getters
        vector<string> getMap();
        unsigned int getRows();
        unsigned int getCols();
        
        //setterss
        void setMap(vector <string> map);
        void setRows(unsigned int rows);
        void setCols(unsigned int cols);
        
        //methods
	    void loadmap(string mapfile);
        void display(vector<string> map);
        void randomPlace();
        void moveStone(unsigned int x,unsigned int y);
        int gameLoop();
        bool notValidMove(int move,const Moving &entity);
        void gmeleStone();
        int wlsituation();


};




#endif