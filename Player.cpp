#include <iostream>
#include <string>
#include "Player.h"
#include "Entity.h"

Player::Player() : Entity() {}

Player::Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->skill_point = skill_point;
	this->attack = attack;
}   //create player class	

void Player::set_playerActionOption(int playerOption) { 
	playerActionOption = playerOption;

	while (playerActionOption < 1 || playerActionOption > 3) {
		std::cout << "Invalid option, please press number from 1 to 3: ";
		std::cin >> playerActionOption;
	}
	
}	// prompt for player option of action (attack, ult, skill)

int Player::get_playerOption() { return playerActionOption; }  //return player option

int Player::ActionResult(int playerOption) {
	if (playerActionOption == 1 && skill_point > 0) {
		srand(time(NULL));
		element = rand() % 3 + 1;

		Result = attack;
		skill_point = skill_point - 5;
		dodge = true;

        if (element == 1) {
			std::cout << Name << " use fire." << std::endl;
			std::cout << std::endl;
		}
		else if (element == 2) {
			std::cout << Name << " use water." << std::endl;
			std::cout << std::endl;
		}
		else if (element == 3) {
			std::cout << Name << " use earth." << std::endl;
			std::cout << std::endl;
		}

	}
	else if (playerActionOption == 2) {
		Result = attack * 5;
		dodge = true;
		health_point = health_point - 20;

		std::cout << Name << " use ultimate." << std::endl;
		std::cout << std::endl;


	}
	else if (playerActionOption == 3) {
		srand(time(NULL));
		Result = 0;
		dodge = rand() % 2;

		std::cout << Name << " use dodge. " << std::endl;
		std::cout << std::endl;
	} 

	else if (playerActionOption == 1 && skill_point <= 0) {
		while (playerActionOption < 2 || playerActionOption > 3) {
			std::cout << "Invalid skill_point, please press number from 2 to 3: ";
			std::cin >> playerActionOption;
			std::cout << std::endl;

			while (playerActionOption < 1 || playerActionOption > 3) {
				std::cout << "Invalid option, please press number from 2 to 3: ";
				std::cin >> playerActionOption;
			}
		}

		if (playerActionOption == 2) {
			Result = attack * 5;
			dodge = true;
			health_point = health_point - 20;

			std::cout << Name << " use ultimate" << " and deal: " << Result << " damage." << std::endl;
		}
		else if (playerActionOption == 3) {
			srand(time(NULL));
			Result = 0;
			dodge = rand() % 2;

			std::cout << Name << " use dodge. " << std::endl;
		}
	}
	return Result;
}//return value of damage dealt by player or dodge action


int Player::get_hitMiss() { return dodge; }                    //return player action result function value
