#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Gameplay.h"
#include <iostream>
#include <fstream>
#include <vector>

class GameMenu : public Gameplay {
public:
    GameMenu(Player* player);

    void start();
    void showResults();

    int startOrExit;
    int pass_stage1;
    int pass_stage2;
    int pass_stage3;
    std::string name;

    void playStage(int stage);
    void recordResults();
};

#endif // GAMEMENU_H
