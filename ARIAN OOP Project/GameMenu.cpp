#include "GameMenu.h"
#include <iostream>
#include "GameStage.h"
#include "Player.h"
#include"Entity.h"
#include "Enemy.h"

GameMenu::GameMenu() : start_or_exit(false), stage_menu(0)  {current_stage=new GameStage;}

void GameMenu::setStartExitGame(bool startOrExitGame) {
    start_or_exit = startOrExitGame;
}

void GameMenu::setStageMenu(int stageMenu) {
    stage_menu = stageMenu;
}

bool GameMenu::getStartExitGame() const {
    return start_or_exit;
}

int GameMenu::getStage() const {
    return stage_menu;
}


                                                                           
