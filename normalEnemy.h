#pragma once
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"

#ifndef NORMALENEMY_H
#define NORMALENEMY_H



class normalEnemy : public Enemy {

public:
	normalEnemy();

	normalEnemy(std::string Name, std::string info, int element, int health_point, int attack); 		//create player class

	int ActionResult(); 		//only for basic attack

};



#endif