#include <iostream>
#include <string>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

using namespace std;

Player::Player() : Entity() {player_attack_option=3; dodge=true;}  

Player::Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->player_attack_option=3;
	this->health_point = health_point;
	this->skill_point = skill_point;
	this->attack_value = attack;
	this->damage_result=1;  //arian added this and above too

}   //create player class	

void Player::set_playerActionOption(int playerOption) { 
	player_attack_option = playerOption;     //arian not necessary
}	
void Player::set_dodge(bool dodge){this->dodge;};  //arian:added this
int Player::get_player_option() { return player_attack_option; }  //return player option


bool Player::get_hit_miss()
{ 	
	srand(time(NULL));
    dodge = rand() % 2;
	return dodge; }  

int Player:: rand_element()
{
	int randElement;
	srand(time(NULL));
	randElement=rand() % 3+1;
	return randElement;
}         
void Player:: print_info()
{
	cout<<"Player Name:"<<get_name()<<endl;
    cout<<"Player Age:"<<get_info()<<endl;
}
// void Player::attack()
// {	//variables

// 		cout << "Choose your action (1: Dodge, 2: Elemental Skill, 3: Ultimate Attack): "<<endl;
//     	cin>>this->player_attack_option;
        
// if (this->player_attack_option>1 && this->player_attack_option<4)
// 	{
// 		switch (this->GStage->getLevel())
// 		{
// 			case 1:
// 				switch (this->player_attack_option)
// 				{
// 				case 1:
// 					if(this->GStage->getLevel()==1)
// 						{
// 							cout << "dodge is not permitted in level 1 "<<endl;	
// 						}
// 					else
// 						{
// 							//write the dodge attacck code here
// 							cout<<"dodge attack needs to be updated"<<endl;
// 						}
// 					break;

				
// 				case 2:
// 					if (this->rand_element() == 1)
// 						{
// 							std::cout <<  " current element is fire. " << std::endl;
// 							this->set_skill_point(this->get_SkillPoint()-(10*this->damage_result)); 		//reducing skill point cz of using element
// 							enemy->set_health_point(enemy->get_Health()-10 );    //fire to fire 10 point
// 					} 
// 					else if (player->rand_element() == 2) 
// 						{
// 							std::cout << "current element is water. " << std::endl;
// 							player->set_skill_point(player->get_SkillPoint()-10);  //reducing skill point cz of using element
// 							enemy->set_health_point(enemy->get_Health()-5 );    //water to fire 20 point
// 						}
// 					else if (player->rand_element()  == 3)
// 						{
// 							std::cout <<  " current element is earth. " << std::endl;
// 							player->set_skill_point(player->get_SkillPoint()-10);   //reducing skill point cz of using element
// 							enemy->set_health_point(enemy->get_Health()-15 );	//earth to fire 5 point	
// 						}
// 					else 
// 						{
// 							std::cout <<  " have no element in current state. " << std::endl;	
// 						}
// 						break;

// 					case 3:
// 						{ 
// 							std::cout <<  " ultimate attacke from player launched! " << std::endl;        
// 							player->set_health_point(player->get_Health()-20); 	//reducing hp by 20 cz of uding ultimate
// 							enemy->set_health_point(enemy->get_Health()-30 );	//ultimate attack take 30 damage 
// 						}
// 						break;
				
// 				default:
// 					std::cout<<"error"<<std::endl;
// 					break;
// 				}
			
// 		this->pr
// 			break;
// 		}
														
// 											printStatus();
// 	}
