#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"

Enemy::Enemy(): Enemy("enemy","no info",1,60,10)  {this->enemy_attack_opction=3;}  //arian enemy action set 0

Enemy::Enemy(std::string Name, std::string info, int element, int health_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->attack_value = attack;
	this->damage_result=0;  //arian added this and above too
}//create Enemy class

void Enemy::set_enemyAction(int enemyOption) {
	enemy_attack_opction = enemyOption;
}

int Enemy:: get_enemyAction() { 
	return enemy_attack_opction; 
}  //return enemy option


