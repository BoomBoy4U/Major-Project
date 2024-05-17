
#include <iostream>
#include <string>
#include "Entity.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity {
protected:
	bool dodge;
public:

	Player();

	Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack); 		//create player class

	void set_dodge(bool dodge);	//arian:: new added
	int damageDealt(int attack, int playerOption);
	bool get_dodge();

};



#endif

