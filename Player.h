#pragma once
#include <iostream>
#include <string>
#include "Entity.h"

#ifndef PLAYER_H
#define PLAYER_H



class Player : public Entity {
protected:
	int playerActionOption = 0;    	//player option to choose to act
	bool dodge;

public: 
int get_playerOption(); 	//return player option

Player(); 

Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack); 		//create player class

void set_playerActionOption(int playerOption);	// prompt for player option of action (attack, ult, skill)

int ActionResult(int playerOption); 		//return value of damage dealt by player or dodge action    //return player action result function value
                                       
int get_hitMiss();   //player dodge status




};



#endif
