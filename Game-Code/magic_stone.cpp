#include "GameEngine.h"
#include "ctime"

using namespace std;

int main (int argc, char** argv)
{
    if (argc!=2)
    {
        cout << "Error in command line arguments!"<<endl<<"Usage: ./magic_stone <map file>"<<endl; 
        exit(1);
    }

    srand(time(NULL));
    
    GameEngine E;
    E.loadmap(argv[1]);
    


    initscr();
    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Green
    init_pair(2, COLOR_RED, COLOR_BLACK); // Red
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); // Yellow

    E.randomPlace();
    E.display(E.getMap());
    
    refresh(); 

    keypad (stdscr,TRUE);
    int wl=E.gameLoop();

    if(wl==1)
    {
        clear();
        printw("\n\n\n\n\n\n                    ==============================\n");
	    printw("                    ||          YOU-WIN         ||\n");
	    printw("                    ==============================\n");
	    printw("\n\n\n\n\n\n                    PRESS ANY KEY TO EXIT...");
        getch(); 
    }
    else if(wl==-1)
    {
        clear();
	    printw("\n\n\n\n\n\n                    ==============================\n");
	    printw("                    ||          YOU-LOST        ||\n");
	    printw("                    ==============================\n");
	    printw("\n\n\n\n\n\n                    PRESS ANY KEY TO EXIT...");
        getch(); 
    }

    
    endwin();



    return 0;

}