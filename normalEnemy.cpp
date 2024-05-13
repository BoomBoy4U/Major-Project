#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"
#include "normalEnemy.h"

normalEnemy::normalEnemy() : Enemy() {}

normalEnemy::normalEnemy(std::string Name, std::string info, int element, int health_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->attack = attack;
}		//create normal enemy class

int normalEnemy::ActionResult() {
	int Result = 0;
	Result = attack;
	return Result;
} 		//only for basic attack