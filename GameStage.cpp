#include "GameStage.h"

GameStage::GameStage(int level, Player* player, std::vector<Enemy*> enemies)
    : level_of_game(level), player(player), enemies(enemies) {}

void GameStage::addPlayer(Player* player) {
    this->player = player;
}

void GameStage::addEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

Player* GameStage::getPlayer() const {
    return player;
}

std::vector<Enemy*> GameStage::getEnemies() const {
    return enemies;
}

int GameStage::getLevel() const {
    return level_of_game;
}
