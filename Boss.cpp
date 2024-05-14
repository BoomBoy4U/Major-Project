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

int Boss::ActionResult(int bossOption) {
	if (bossOption == 1) {
		Result = attack;
		std::cout << Name << " use basic attack." << std::endl;
		std::cout << std::endl;
	}
	else if (bossOption == 2) {
		Result = attack * 10;
		std::cout << Name << " use ultimat attack." << std::endl;
		std::cout << std::endl;
	}


	return Result;
} 		