#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define ESC 9
#define SPACE 0
#define FAIL 3
#include "GameEngine.h"
#include <fstream>


//constructor
GameEngine::GameEngine()
{

}

//destuctor
GameEngine::~GameEngine()
{

}

//getters
vector<string> GameEngine::getMap()
{
    return map;
}

unsigned int GameEngine::getRows()
{
    return rows;
}

unsigned int GameEngine::getCols()
{
    return cols;
}

//setter
void GameEngine::setMap(vector <string> nmap)
{
    map=nmap;
}

void GameEngine::setRows(unsigned int nrows)
{
    rows=nrows;
}

void GameEngine::setCols(unsigned int ncols)
{
    cols=ncols;
}

//methods 
void GameEngine::loadmap(string mapfile)
{
    string line;
	int countl=0;
	
	ifstream file (mapfile.c_str());
	if (!file)
	{
        cout << " File didn't open! " ;
	    exit(1);
	} 
	
	while (!file.eof()) 
	{
	    getline(file,line);
	    map.push_back(line);
		countl++; 
	}
	
	
	
	rows=countl;
	cols=line.length();
	file.close();
}

void GameEngine::display(vector<string> map)
{
    char c;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            c=map[i][j];
            
            switch(c)
            {
                case '*':
                    addch('#');
                    break;
                case '.':
                    addch(' ');
                    break;
                case 'L':
                    attron(COLOR_PAIR(1));
                    addch('L');
                    attroff(COLOR_PAIR(1));
                    break;
                case 'M':
                    attron(COLOR_PAIR(2));
                    addch('M');
                    attroff(COLOR_PAIR(2));
                    break;
                case 'o':
                    attron(COLOR_PAIR(3));
                    addch('o');
                    attroff(COLOR_PAIR(3));
                    break;
            }


        }
        addch('\n');
    }
    
}

void GameEngine::randomPlace()
{
    vector<unsigned int> rand_row,rand_col;

    for (int i=0; i < 3; i++)
    {
        rand_row.push_back(rand()%rows);
        rand_col.push_back(rand()%cols);

        while(map[rand_row[i]][rand_col[i]]=='*')
        {
            rand_row[i]=(rand()%rows);
            rand_col[i]=(rand()%cols);
        }

        for (int j=i-1;j>-1;j--)
        {
            if(map[rand_row[i]][rand_col[i]]==map[rand_row[j]][rand_col[j]])
                while(map[rand_row[i]][rand_col[i]]=='*')
            {
                rand_row[i]=(rand()%rows);
                rand_col[i]=(rand()%cols);
            }

        }
   
    }
    
        map[rand_row[0]][rand_col[0]]='L';
        map[rand_row[1]][rand_col[1]]='M';
        map[rand_row[2]][rand_col[2]]='o';
        
        for (int k=0;k<3;k++)
        {
            coordinates.push_back(make_pair(rand_row[k], rand_col[k]));

        }
    
}

int GameEngine::gameLoop()
{
    Lucas L(coordinates[0].first,coordinates[0].second);
    Mpampis M(coordinates[1].first,coordinates[1].second,coordinates[2].first,coordinates[2].second,map);
    int Lmove;
    int Mmove;
    int change_stone_position=0;
    int wl=0;
    

    do
    {
        Lmove=L.getMove();
        
        
		move(L.gety(),L.getx());
        addch(' ');
        move(M.gety(),M.getx());
        addch(' ');
        

        
        
        if(!this->notValidMove(Lmove,L))
        {
            
            map[L.gety()][L.getx()]='.';
            map[M.gety()][M.getx()]='.';

            switch (Lmove)
            {
                case UP     : L.sety(L.gety()-1);  break;
                case DOWN   : L.sety(L.gety()+1);  break;
                case RIGHT  : L.setx(L.getx()+1);  break;
                case LEFT   : L.setx(L.getx()-1);  break;
                case SPACE  : move(L.gety(),L.getx()+1); map[L.gety()][L.getx()+1]=='*' ? addch('#') : addch(' '); break;
                case ESC    : break;
            }

            if(change_stone_position==3)
            {   
                if((rand()%10)%2==0)
                {
                    this->gmeleStone();
                    M.setSy(coordinates[2].first);
                    M.setSx(coordinates[2].second);
                }
                

            }
            
            Mmove=M.getMove();
            while(this->notValidMove(Mmove,M))
            {
                Mmove=M.getMove();
            }
            
            move(M.gety(),M.getx()+1);
            map[M.gety()][M.getx()+1]=='*' ?  addch('#') : addch(' ');
            

            switch (Mmove)
            {
                case UP     : M.sety(M.gety()-1);  break;
                case DOWN   : M.sety(M.gety()+1);  break;
                case RIGHT  : M.setx(M.getx()+1);  break;
                case LEFT   : M.setx(M.getx()-1);  break;
            }

            

        }
        else
        { 
            move(L.gety(),L.getx()+1);
            map[L.gety()][L.getx()+1]=='*' ? addch('#') : addch(' ');
        }



        coordinates[0].first=L.gety();
        coordinates[0].second=L.getx();

        coordinates[1].first=M.gety();
        coordinates[1].second=M.getx();

        

        

        move(M.gety(),M.getx());
	    attron(COLOR_PAIR(2));
        addch('M');
        attroff(COLOR_PAIR(2));

        move(L.gety(),L.getx());
	    attron(COLOR_PAIR(1));
        addch('L');
        attroff(COLOR_PAIR(1));
        
        map[L.gety()][L.getx()]='L';
        map[M.gety()][M.getx()]='M';
        
        if(change_stone_position<=3)
            change_stone_position++;
        else 
            change_stone_position=0;
        
      
        wl=this->wlsituation();
        
        
        refresh();

    } while (wl==0 && Lmove!=ESC) ;
    

    return wl;

}

bool GameEngine::notValidMove(int move,const Moving &entity)
{
    bool flag=0;
    switch (move)
		{
			case UP     : map[entity.gety()-1][entity.getx()]=='*' ? flag=1 : flag =0; break;
			case DOWN   : map[entity.gety()+1][entity.getx()]=='*' ? flag=1 : flag =0; break;
			case RIGHT  : map[entity.gety()][entity.getx()+1]=='*' ? flag=1 : flag =0; break;
			case LEFT   : map[entity.gety()][entity.getx()-1]=='*' ? flag=1 : flag =0; break;
            case SPACE  : flag=0; break;
            case FAIL   : flag=1; break;
            default     : flag=1; break;
		}

    return flag;
}

void GameEngine::gmeleStone()
{
    map[coordinates[2].first][coordinates[2].second]='.';
    move(coordinates[2].first,coordinates[2].second);
    addch(' ');
    
    coordinates[2].first=rand()%rows;
    coordinates[2].second=rand()%cols;
    
    
    while(map[coordinates[2].first][coordinates[2].second]=='*')
    {
        coordinates[2].first=rand()%rows;
        coordinates[2].second=rand()%cols;
    }
        

    map[coordinates[2].first][coordinates[2].second]='o';
    move(coordinates[2].first,coordinates[2].second);
    attron(COLOR_PAIR(3));
    addch('o');
    attroff(COLOR_PAIR(3));


}

int GameEngine::wlsituation()
{
    if (coordinates[0].first==coordinates[2].first && coordinates[0].second==coordinates[2].second)
        return 1;
    else if ((coordinates[1].first==coordinates[2].first && coordinates[1].second==coordinates[2].second))
        return -1;
    else 
        return 0;
}

