#include <iostream>
#include <string>
#include "Entity.h"

Entity::Entity() : Name("NA"), info("NA"), element(0), health_point(0), skill_point(0), attack(0) {}
Entity::Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->skill_point = skill_point;
	this->attack = attack;
}

int Entity::get_Health(int damage) { return health_point -= damage;}	//return health value

int Entity::get_SkillPoint() {return skill_point;}  		//return skill point value

int Entity::get_Attack() {return attack;}     		//return attack value

int Entity::get_Element() { return element; }   		//return element of the entity

std::string Entity::get_name() {return Name;}  		//return name of the entity

std::string Entity::get_info() { return info; }    		//return the info of entity

int Entity::get_result() { return Result;}

int Entity::ActionResult() { return 0; };	//return the action result of the entity.
