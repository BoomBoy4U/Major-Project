#include <iostream>
#include <string>
#include "Player.h"
#include "Entity.h"
using namespace std;

Player::Player() : Entity() {playerActionOption=0; dodge=true;}  //arian:intialized 

Player::Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->skill_point = skill_point;
	this->attack = attack;
	this->Result=0;  //arian added this and above too
}   //create player class	

void Player::set_playerActionOption(int playerOption) { 
	playerActionOption = playerOption;     //arian not necessary

	while (playerActionOption < 1 || playerActionOption > 3) {
		std::cout << "Invalid option, please press number from 1 to 3: ";
		std::cin >> playerActionOption;
	}
	if (playerOption < 1 || playerOption > 3)
			{
				std::cout<<"Invalid option, please press number from 1 to 3: "<<endl;
			}
	else{playerActionOption=playerOption;}
	
	
}	// prompt for player option of action (attack, ult, skill)
void Player::set_dodge(bool dodge){this->dodge;};  //arian:added this
int Player::get_playerOption() { return playerActionOption; }  //return player option


bool Player::get_hitMiss() { srand(time(NULL));
                            dodge = rand() % 2;
							return dodge; }           
int Player:: rand_element(){
	int randElement;
	srand(time(NULL));
	randElement=rand() % 3+1;
	return randElement;

}         
