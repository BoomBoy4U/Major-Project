#pragma once
#include <iostream>
#include <string>
#include "Entity.h"

#ifndef ENEMY_H
#define ENEMY_H



class Enemy : public Entity {
protected:
	int enemyAction = 0; 		//enemy option 
public:

	Enemy();

	Enemy(std::string Name, std::string info, int element, int health_point, int attack); 		//create player class

	int get_enemyAction(); 	//return enemy option	
 	
};



#endif