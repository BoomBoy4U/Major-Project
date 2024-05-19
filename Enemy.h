
#include <iostream>
#include <string>
#include "Entity.h"

#ifndef ENEMY_H
#define ENEMY_H



class Enemy : public Entity {
public:

	Enemy();

	Enemy(std::string Name, std::string info, int element, int health_point, int attack);

	int damageDealt(int attack);


};



#endif
