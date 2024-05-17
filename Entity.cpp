#include <iostream>
#include <string>
#include "Entity.h"
using namespace std;

Entity::Entity() : Name("NA"), info("NA"), element(0), health_point(100), skill_point(60), attack_value(5), damage_result(0) {}
Entity::Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack2) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->skill_point = skill_point;
	this->attack_value = attack2;
	this->damage_result=0;  //arian added this and above too
}

int Entity::get_Health() { return health_point;}	//return health value //arian changed 

int Entity::get_SkillPoint() {return skill_point;}  		//return skill point value

int Entity::get_Attack() {return attack_value;}     		//return attack value

int Entity::get_Element() { return element; }   		//return element of the entity

std::string Entity::get_name() {return Name;}  		//return name of the entity

std::string Entity::get_info() { return info; }    		//return the info of entity

int Entity::get_damage_result() { return damage_result;}
void Entity::set_name(const std::string& newName) {Name = newName;}
void Entity::set_info(const std::string& newInfo) {info = newInfo;}
void Entity::set_health_point(int newHealthPoint) {health_point = newHealthPoint;}
void Entity::set_skill_point(int newSkillPoint) {skill_point = newSkillPoint;}
void Entity::set_attack(int newAttack) {attack_value = newAttack; }
void Entity::set_element(int newElement) { element = newElement;    }
void Entity::set_damage_result(int newResult) {    damage_result = newResult; }
void Entity:: print_info()
{
	cout<<"Entity Name:"<<this->get_name()<<endl;
    cout<<"Entity Age/info:"<<this->get_info()<<endl;
}
