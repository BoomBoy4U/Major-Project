


#ifndef NORMALENEMY_H
#define NORMALENEMY_H
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"


class normalEnemy : public Enemy {

public:
	normalEnemy();

	normalEnemy(std::string Name, std::string info, int element, int health_point, int attack); 		//create player class


};



#endif