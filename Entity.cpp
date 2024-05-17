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

int Entity::get_Health() { return health_point; }	//return health value //arian changed 

int Entity::get_SkillPoint() { return skill_point; }  		//return skill point value

int Entity::get_Attack() { return attack; }     		//return attack value

int Entity::get_Element() { return element; }   		//return element of the entity

std::string Entity::get_name() { return Name; }  		//return name of the entity

std::string Entity::get_info() { return info; }    		//return the info of entity

int Entity::get_damage() { return damage; }



void Entity::set_Name(const std::string& newName) {
    Name = newName;
}

void Entity::set_info(const std::string& newInfo) {
    info = newInfo;
}

void Entity::set_health_point(int newHealthPoint) {
    health_point = newHealthPoint;
}

void Entity::set_skill_point(int newSkillPoint) {
    skill_point = newSkillPoint;
}

void Entity::set_attack(int newAttack) {
    attack = newAttack;
}

void Entity::set_element(int newElement) {
    element = newElement;
}

int Entity::damageDealt(int attack) {
    return 0;
}
