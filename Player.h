
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Entity.h"
#include "Enemy.h"


class Player :public Entity
{
private:
	int player_attack_option;    	//player option to choose to act  //arian: removed intialization
	bool dodge ;
	

public:
	Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack );
	Player(); 
	~Player(){};

	int get_player_option(); 	//return player option
	void set_playerActionOption(int playerOption);	// prompt for player option of action (attack, ult, skill)
	void set_dodge(bool dodge);	//arian:: new added                                
	bool get_hit_miss();
	
	//functions
	int rand_element();
	void print_info();  
	// void attack() const;

};



#endif
