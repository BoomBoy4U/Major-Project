#include <iostream>
#include <string>
#include "Player.h"
#include "Entity.h"
using namespace std;

Player::Player() : Entity() {}

Player::Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->skill_point = skill_point;
	this->attack = attack;
	this->dodge = false;
}   //create player class	


void Player::set_dodge(bool newdodge) { dodge = newdodge; };  //arian:added this

bool Player::get_dodge() { return dodge; }

int Player::damageDealt(int attack, int playerOption) {
	if (playerOption == 1) {
		//std::cout << "use dodge" << std::endl;
		srand(time(NULL));
		int chance = rand() % 2 + 1;
		if (chance == 1) {
			dodge = true;
		}
		else if (chance == 2) {
			dodge = false;
		}

		damage= 0;
	}
	else if (playerOption == 2) {
		//std::cout << "use elemental attack" << std::endl;
		skill_point -= 10;
		srand(time(NULL));
		element = rand() % 3 + 1;
		 damage = attack;
	}
	else if (playerOption == 3) {
		//std::cout << "use ultimate attack" << std::endl;
		this->health_point -= 20;
		 damage = attack * 5;
	}
	return damage;
}




