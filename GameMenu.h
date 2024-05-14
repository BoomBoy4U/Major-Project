#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "GameStage.h"

class GameMenu {
public:
    GameMenu();

    void setStartExitGame(bool startOrExitGame);
    void setStageMenu(int stageMenu);
    bool getStartExitGame() const;
    int getStage() const;
    bool gameplay();

private:
    bool start_or_exit;
    int stage_menu;
    GameStage* current_stage;
};

#endif // GAME_MENU_H
