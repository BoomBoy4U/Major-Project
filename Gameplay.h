

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Entity.h"
#include <vector>


#ifndef GAMEPLAY_H
#define GAMEPLAY_H

class Gameplay {
private:
	Player* player;
	std::vector <Entity*>& enemies;


public:

	Gameplay(std::vector<Entity*>& _enemies, Player* _player);
	void addPlayer(Player* player);
	void addenemy(Enemy* enemy);
	void addBoss(Boss* boss);
	void play(std::vector<Entity*>& enemies, Player* player);






};




#endif

