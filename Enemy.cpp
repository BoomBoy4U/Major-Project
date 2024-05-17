#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"
Enemy::Enemy() : Entity() {};

Enemy::Enemy(std::string Name, std::string info, int element, int health_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->attack = attack;
}//create Enemy class

int Enemy::damageDealt(int attack) {
	//std::cout << "use basic attack" << std::endl;
	damage = attack;
	return damage;
}


