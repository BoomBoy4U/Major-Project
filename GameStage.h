#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include "Player.h"
#include "Enemy.h"
#include <vector>

class GameStage {
public:
    GameStage(int level, Player* player, std::vector<Enemy*> enemies);

    void addPlayer(Player* player);
    void addEnemy(Enemy* enemy);
    Player* getPlayer() const;
    std::vector<Enemy*> getEnemies() const;
    int getLevel() const;

private:
    int level_of_game;
    Player* player;
    std::vector<Enemy*> enemies;
};

#endif // GAME_STAGE_H
