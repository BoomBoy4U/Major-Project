#pragma once
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"

#ifndef BOSS_H
#define BOSS_H



class Boss : public Enemy {

public:
	Boss();

	Boss(std::string Name, std::string info, int element, int health_point, int attack); 		//create Boss class

	int ActionResult(int bossOption); 		//basic and ult

};



#endif