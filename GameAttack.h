#ifndef GAMEATTACK_H
#define GAMEATTACK_H
#include"Enemy.h"
#include "Player.h"
#include "Entity.h"
#include "GameMenu.h"
using namespace std;


class GameAttack : public GameMenu
{
private:
    GameMenu* game_Menu;
public:
    GameAttack(GameMenu* game_Menu){this->game_Menu=game_Menu;};
	GameAttack(){game_Menu=new GameMenu;}
    ~GameAttack(){};
void player_Battle()
{
				
		if (game_Menu->getPlayer()->get_player_option()>0 && game_Menu->getPlayer()->get_player_option()<4)
			{ cout<<"switch 1"<<endl;
				switch (game_Menu->getStartLevel())
				{
					case 1:
						
						int attack_Option;
						cout << "Choose your action (1: Dodge, 2: Elemental Skill, 3: Ultimate Attack): "<<endl;
						cin>>attack_Option;
						game_Menu->getPlayer()->set_playerActionOption(attack_Option);
						
							
						switch (game_Menu->getPlayer()->get_player_option())
						{
						case 1:
							if(game_Menu->getStartLevel()==1)
								{
									cout << "dodge is not permitted in level 1 "<<endl;	
									
								}
							else
								{
									//write the dodge attacck code here
									cout<<"dodge attack needs to be updated"<<endl;
								}
							break;

						
						case 2:
							if (game_Menu->getPlayer()->rand_element() == 1)
								{
									std::cout <<  " current attack element is fire. " << std::endl;
									this->getPlayer()-> set_skill_point(this->getPlayer()->get_SkillPoint()-(10*this->getPlayer()->get_Attack())); 		//reducing skill point cz of using element
									this->getEnemies()->set_health_point(this->getEnemies()->get_Health()-(3*this->getPlayer()->get_Attack()));    //fire to fire 10 point
							} 
							else if (this->game_Menu->getPlayer()->rand_element() == 2)
								{
									std::cout << "current attack  element is water. " << std::endl;
									this->game_Menu->getPlayer()-> set_skill_point(this->game_Menu->getPlayer()->get_SkillPoint()-(10*this->game_Menu->getPlayer()->get_Attack()));   //reducing skill point cz of using element
									this->game_Menu->getEnemies()->set_health_point(this->game_Menu->getEnemies()->get_Health()-(2*this->game_Menu->getPlayer()->get_Attack()) );    //water to fire 20 point
								}
							else if (this->getPlayer()->rand_element() == 3)
								{
									std::cout <<  " current attack element is earth. " << std::endl;
									this->game_Menu->getPlayer()-> set_skill_point(this->game_Menu->getPlayer()->get_SkillPoint()-(10*this->game_Menu->getPlayer()->get_Attack()));   //reducing skill point cz of using element
									this->game_Menu->getEnemies()->set_health_point(this->game_Menu->getEnemies()->get_Health()-(1*this->game_Menu->getPlayer()->get_Attack()) );	//earth to fire 5 point	
								}
							else 
								{
									std::cout <<  " have no element in current state. " << std::endl;	
								}
								break;

							case 3:
								{ 
									std::cout <<  " ultimate attacke from player launched! " << std::endl;        
									this->game_Menu->getPlayer()-> set_health_point(this->game_Menu->getPlayer()->get_Health()-(10*this->game_Menu->getPlayer()->get_Attack())); 	//reducing hp by 20 cz of uding ultimate
									this->game_Menu->getEnemies()->set_health_point(this->game_Menu->getEnemies()->get_Health()-(30*this->game_Menu->getPlayer()->get_Attack()) ); 
								}
								break;
						
						default:
							std::cout<<"error"<<std::endl;
							break;
						}
		//print status    
						std::cout<<"                                        current status:"<<std::endl;       
						std::cout<<"                                        Player HP:"<<this->game_Menu->getPlayer()->get_Health();
						std::cout<<" | Player SP:"<<this->game_Menu->getPlayer()->get_SkillPoint()<<std::endl;
						std::cout<<"                                        Enemy HP:"<<this->game_Menu->getEnemies()->get_Health();
						std::cout<<" | Enemy SP:"<<this->game_Menu->getEnemies()->get_SkillPoint()<<std::endl;
						
				break;
				}
		
	 //endof level 1       
			}//end of all the 3 level player battel

}

void normal_enemy_battel()
{
    switch (this->game_Menu->getStartLevel())
		{
			case 1:
                std::cout << "normal enemy is attacking: "<<std::endl;                                                    
                srand(time(NULL));
                this->game_Menu->getEnemies()->set_enemyAction(rand() % 3+1);

            if (this->game_Menu->getEnemies()->get_enemyAction() == 1||this->game_Menu->getEnemies()->get_enemyAction()==2)   //increased the chance of using this type of attack
                { 
                    std::cout << "basic attack from enemy done!  "<<std::endl;
                    this->game_Menu->getPlayer()->set_health_point(this->game_Menu->getPlayer()->get_Health()-this->game_Menu->getEnemies()->get_Attack());
                

                }
                
            else if (this->game_Menu->getEnemies()->get_enemyAction()==3)
                {
                    std::cout << "fire element attack from enemy done!  "<<std::endl;
                    this->game_Menu->getPlayer()->set_health_point(this->game_Menu->getPlayer()->get_Health()-(2*(this->game_Menu->getEnemies()->get_Attack())));//make it more fun twice damage
                }
                
                break;
                
                default:
                std::cout<<"error"<<std::endl;
                
                break;
}
//print status    
                std::cout<<"                                        current status:"<<std::endl;       
                std::cout<<"                                        Player HP:"<<this->game_Menu->getPlayer()->get_Health();
                std::cout<<" | Player SP:"<<this->game_Menu->getPlayer()->get_SkillPoint()<<std::endl;
                std::cout<<"                                        Enemy HP:"<<this->game_Menu->getEnemies()->get_Health();
                std::cout<<" | Enemy SP:"<<this->game_Menu->getEnemies()->get_SkillPoint()<<std::endl;
}
void full_Attacl_battel(){

	int hpToSp;
		while(this->game_Menu->getPlayer()->get_Health()>0&&this->game_Menu->getEnemies()->get_Health()>>00)

			{   if(this->game_Menu->getPlayer()->get_SkillPoint()>0)
					{							
						this->player_Battle();
						if(this->game_Menu->getPlayer()->get_Health()<=0)
							{
								cout<<"player lost!"<<endl;
								break;
							}
						else 
							{
								if(this->game_Menu->getPlayer()->get_player_option()!=1)
									{
										this->normal_enemy_battel();
								if(this->game_Menu->getEnemies()->get_Health()<=0)
								{
									cout<<"player won! hooooooorrrrrraayyyyy"<<endl;
									break;
								}
									}

							}
					}
			else
				{
				
				std::cout<<"would you like to buy some sp with your hp"
				<<" press Y to go ahead or N to continue the game? "<<std::endl;
				std::cin>>hpToSp;
						switch (hpToSp)
						{
						case 'Y':
								player->set_skill_point(player->get_Health());
								player->set_health_point(player->get_Health()-0.4*player->get_Health());
							break;
						case 'N':
								std::cout<<"you can not continue without sp "<<std::endl;
							break;
						
						default:
							std::cout<<"wrong input!"<<std::endl;
							break;
						}
				}
			}
// if(this->game_Menu->getPlayer()->get_Health()<=0)
// 	{
// 		cout<<"player lost!"<<endl;
// 	}

// else if(this->game_Menu->getEnemies()->get_Health()<=0)
// 		{
// 			cout<<"player won! hooooooorrrrrraayyyyy"<<endl;
// 		}
// 	else {cout<<"an arror happened "<<endl;}
 	}
};
#endif