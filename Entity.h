
#include <iostream>
#include <string>

#ifndef ENTITY_H
#define ENTITY_H



class Entity {
protected:
	std::string Name ;			//name of entity
	std::string info ; 			//info of entity
	int health_point ;      		//health point of entity
	int skill_point;  				//skill point to use skill and ultimate
	int attack_value ;      			//value of attack that dealt to enemy
	int element ;
	int damage_result ;

public:
	Entity();
	Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack);

	//getters
	int get_Health();		//return health value
	int get_SkillPoint();   		//return skill point value
	int get_Attack();     		//return attack value
	int get_Element();   		//return element of the entity
	std::string get_name();   		//return name of the entity
	std::string get_info();      		//return the info of entity
	int get_damage_result();
	
	//setters
	void set_name(const std::string& newName);
    void set_info(const std::string& newInfo);
    void set_health_point(int newHealthPoint);
    void set_skill_point(int newSkillPoint) ;
    void set_attack(int newAttack) ;
    void set_element(int newElement);
	void set_damage_result(int newResult);

	//functions
	virtual void print_info();
	// virtual void attack() const=0 ;


};



#endif