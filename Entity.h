#include <iostream>
#include <string>

#ifndef ENTITY_H
#define ENTITY_H



class Entity {
protected:

	std::string Name;			//name of entity
	std::string info; 			//info of entity
	int health_point;      		//health point of entity
	int skill_point;  				//skill point to use skill and ultimate
	int attack;      			//value of attack that dealt to enemy
	int element;

	int damage;



public:
	Entity();
	Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack);
	int get_Health();		//return health value
	int get_SkillPoint();   		//return skill point value
	int get_Attack();     		//return attack value
	int get_Element();   		//return element of the entity
	std::string get_name();   		//return name of the entity
	std::string get_info();      		//return the info of entity
	int get_damage();

	// arian:setters were missing 

	void set_Name(const std::string& newName);
	void set_info(const std::string& newInfo);
	void set_health_point(int newHealthPoint);
	void set_skill_point(int newSkillPoint);
	void set_attack(int newAttack);
	void set_element(int newElement);
	virtual int damageDealt(int attack);



};


#endif
