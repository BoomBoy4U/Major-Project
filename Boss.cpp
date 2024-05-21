#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"
#include "Boss.h"

Boss::Boss() : Enemy() {}

Boss::Boss(std::string Name, std::string info, int element, int health_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->attack = attack;
}

int Boss::damageDealt(int attack) {
	srand(time(NULL));
	int enemyOption = rand() % 2 + 1;

	if (enemyOption == 1) {
		//std::cout << "use basic attack" << std::endl;
		 damage = attack;
	}
	else if (enemyOption == 2) {
		//std::cout << "use utimate attack" << std::endl;
		damage = attack * 3;
	}
	return damage;
}