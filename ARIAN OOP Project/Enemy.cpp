#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"

Enemy::Enemy(): Entity()  {this->enemyAction=0;}  //arian enemy action set 0

Enemy::Enemy(std::string Name, std::string info, int element, int health_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->attack = attack;
	this->Result=0;  //arian added this and above too
}//create Enemy class

void Enemy::set_enemyAction(int enemyOption) {
	enemyAction = enemyOption;
}

int Enemy:: get_enemyAction() { 
	return enemyAction; 
}  //return enemy option


