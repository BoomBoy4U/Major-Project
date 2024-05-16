#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include "Player.h"
#include "Enemy.h"
#include <vector>

class GameStage {
public:
    GameStage(int level, Player* player, Enemy* enemy);
    GameStage();

    void addPlayer(Player* player);
    // void addEnemy(Enemy* enemy);
    Player* getPlayer() ;
    Enemy* getEnemies() const;
    int getLevel() const;
    void gameplay();
    void printStatus();

private:
    int level_of_game;
    Player* player;
    Enemy* enemy;
    
};

#endif // GAME_STAGE_H