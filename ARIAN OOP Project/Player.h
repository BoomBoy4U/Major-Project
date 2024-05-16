
#include <iostream>
#include <string>
#include "Entity.h"

#ifndef PLAYER_H
#define PLAYER_H



class Player : public Entity {
protected:
	int playerActionOption;    	//player option to choose to act  //arian: removed intialization
	bool dodge ;

public: 
int get_playerOption(); 	//return player option

Player(); 

Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack); 		//create player class

void set_playerActionOption(int playerOption);	// prompt for player option of action (attack, ult, skill)
void set_dodge(bool dodge);	//arian:: new added
int rand_element();
                                       
bool get_hitMiss();   //player dodge status




};



#endif
