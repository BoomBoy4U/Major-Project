#include "GameMenu.h"
#include <iostream>

GameMenu::GameMenu() : start_or_exit(false), stage_menu(0), current_stage(nullptr) {}

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

bool GameMenu::gameplay() {
    while (current_stage->getPlayer()->getHealth() > 0 && 
           std::any_of(current_stage->getEnemies().begin(), current_stage->getEnemies().end(),
                       [](Enemy* enemy){ return enemy->getHealth() > 0; })) {

        for (auto& enemy : current_stage->getEnemies()) {
            if (enemy->getHealth() > 0) {
                int player_action;
                std::cout << "Choose your action (1: Dodge, 2: Elemental Skill, 3: Ultimate Attack): ";
                std::cin >> player_action;

                current_stage->getPlayer()->setPlayerActionOption(player_action);
                enemy->setEnemyAction();

                int player_result = current_stage->getPlayer()->actionResult();
                int enemy_result = enemy->actionResult();

                if (player_action == 1) {
                    if (player_result) {
                        std::cout << "Dodge successful!" << std::endl;
                    } else {
                        std::cout << "Dodge failed! Taking damage." << std::endl;
                        current_stage->getPlayer()->health_point -= enemy_result;
                    }
                } else if (player_action == 2 || player_action == 3) {
                    std::cout << "Player deals " << player_result << " damage!" << std::endl;
                    enemy->health_point -= player_result;
                }

                if (enemy_result > 0) {
                    std::cout << "Enemy deals " << enemy_result << " damage!" << std::endl;
                    current_stage->getPlayer()->health_point -= enemy_result;
                }
            }
        }
    }

    return
