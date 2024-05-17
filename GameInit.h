#ifndef GAMEINIT_H
#define GAMINIT_H
#include "GameMenu.h"

class GameInit: public GameMenu
{

protected:
    GameMenu* game_menu;

public:
    GameInit ();
    GameInit (GameMenu* game_menu);

    ~GameInit ();
    void start_Message();
};





#endif