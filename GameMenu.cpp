#include "GameMenu.h"
using namespace std;
GameMenu::GameMenu():start_Exit(false),_Level(1)
{
    player=new Player;
    enemies=new Enemy[1];
    enemies_Number=1;
}

GameMenu::GameMenu(bool start_Exit,int start_Level)
{
    this->start_Exit=start_Exit;
    this->_Level=start_Level;
    player=new Player;
   
        switch (_Level)
        {
        case 1:
            enemies=new Enemy[1];  //level 1 , one enemy
            enemies_Number=1;
            break;
        case 2:
            enemies=new Enemy[3]; //level 2 , 3 enemy
            enemies_Number=3;
            break;
        case 3:
            enemies=new Enemy[4]; //level 3, 4 enemy
            enemies_Number=4;
            break;
        
        default:
            cout<<"this game has only 3 level: 1 or 2 or 3 is accepted."<<endl;
            break;
    
    }

   
}



void GameMenu::init_Player_Info()
{   string name;
    string info;
    cout<<"Enter your first name! (only one word phrase/string , no space then press entre)"<<endl;
    cin>>name;
    cout<<"Enter your info/age! (only one word phrase/string , no space then press entre)"<<endl;
    cin>>info;
    this->player->set_name(name);
    this->player->set_info(info);
    
}
GameMenu::~GameMenu()
{   
 
  
}