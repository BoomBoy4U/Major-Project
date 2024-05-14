#pragma once
#include <iostream>
#include <string>

#ifndef ENTITY_H
#define ENTITY_H



class Entity {
protected:
	std::string Name = "NA";			//name of entity
	std::string info = "NA"; 			//info of entity
	int health_point = 0;      		//health point of entity
	int skill_point = 0;  		//skill point to use skill and ultimate
	int attack = 0;      			//value of attack that dealt to enemy
	int element = 0;
	int Result = 0;

public:
	Entity();
	Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack);
	int get_Health(int damage);		//return health value
	int get_SkillPoint();   		//return skill point value
	int get_Attack();     		//return attack value
	int get_Element();   		//return element of the entity
	std::string get_name();   		//return name of the entity
	std::string get_info();      		//return the info of entity
	int get_result();
	virtual int ActionResult();	//return the action result of the entity.



};



#endif