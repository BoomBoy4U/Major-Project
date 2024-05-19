

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
	int stage =0;


public:

	Gameplay(std::vector<Entity*>& _enemies, Player* _player);
	//void addPlayer(Player* player);
	//void addenemy(Enemy* enemy);
	//void addBoss(Boss* boss);
	int play(std::vector<Entity*>& enemies, Player* player);



	int get_stage();
	void set_stage(int _stage);






};




#endif

