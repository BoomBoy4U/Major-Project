#include "GameInit.h"
using namespace std;
GameInit ::GameInit ()
{
}

GameInit::GameInit(GameMenu* game_menu)
{
    this->game_menu=game_menu;
}

GameInit ::~GameInit ()
{
}
void GameInit::start_Message()
{   cout<<endl<<endl<<"Level: "<<this->game_menu->getStartLevel()<<" | Elementus Game"<<" | is Starting"<<endl;
    this->game_menu->getPlayer()->print_info();
    cout<<"You need to fight with "<<this->game_menu->getEnemiesNumber()<<" enemy/enemies!"<<endl<<" HOOOOORAAaaaAYyyyyyYYY"<<endl;
   
}