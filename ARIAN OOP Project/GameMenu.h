#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "GameStage.h"

class GameMenu {
public:
    GameMenu();  // user input for levels! for example if its level 1 it creats 1 playaer and 1 enemy, if it is level 2, player still the same but 2 normal enemy one boss enemy will be created .

    void setStartExitGame(bool startOrExitGame);
    void setStageMenu(int stageMenu);
    bool getStartExitGame() const;
    int getStage() const;
 

private:
    bool start_or_exit;
    int stage_menu;
    GameStage* current_stage;
    
};

#endif // GAME_MENU_H