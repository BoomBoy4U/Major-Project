#include "GameStage.h"

GameStage::GameStage(int level, Player* player, Enemy* enemy)
    : level_of_game(level), player(player), enemy(enemy) {}

void GameStage::addPlayer(Player* player) {
    this->player = player;
}
GameStage::GameStage(): level_of_game(1){player=new Player; enemy=new Enemy; }

// void GameStage::addEnemy(Enemy* enemy) {
//     enemies.push_back(enemy);
// }

Player* GameStage::getPlayer()  {
    return player;
}

Enemy* GameStage::getEnemies() const {
    return enemy;
}

int GameStage::getLevel() const {
    return level_of_game;
}
void GameStage::printStatus(){     
                std::cout<<"                                        current status:"<<std::endl;       
                std::cout<<"                                        Player HP:"<<player->get_Health();
                std::cout<<" | Player SP:"<<player->get_SkillPoint()<<std::endl;
                std::cout<<"                                        Enemy HP:"<<enemy->get_Health();
                std::cout<<" | Enemy SP:"<<enemy->get_SkillPoint()<<std::endl;
            }

void GameStage::gameplay() {   ///actionresult happening here , this is the main game logic and scores 


                int player_action;
                int enemy_attack_option;
                std::cout<<"The level 1 game started"<<std::endl;
                printStatus();
                while (player->get_Health()>0 && enemy->get_Health()>0)
                {
                    
               
                
    //player attack
    std::cout << "Choose your action (1: Dodge, 2: Elemental Skill, 3: Ultimate Attack): "<<std::endl;
                                                    std::cin>>player_action;
                    if (player_action>1 && player_action<4){

                                                switch (this->level_of_game)
                                                {
                                                case 1:
                                                    
                                                    if (player_action == 1)
                                                                           { std::cout << "dodge is not permitted in level 1 "<<std::endl;
                                                                            
                                                                           }
                                                    
                                                     if (player_action==2)
                                                    {
                                                       
                                                         if (player->rand_element() == 1) {
                                                            std::cout <<  " current element is fire. " << std::endl;
                                                            player->set_skill_point(player->get_SkillPoint()-10); 
                                                            //reducing skill point cz of using element
                                                            enemy->set_health_point(enemy->get_Health()-10 );
                                                            //fire to fire 10 point
                                                            

                                                        }
                                                        else if (player->rand_element() == 2) {
                                                            std::cout << "current element is water. " << std::endl;
                                                            player->set_skill_point(player->get_SkillPoint()-10); 
                                                            //reducing skill point cz of using element
                                                            enemy->set_health_point(enemy->get_Health()-5 );
                                                            //water to fire 20 point
                                                            
                                                        }
                                                        else if (player->rand_element()  == 3) {
                                                            std::cout <<  " current element is earth. " << std::endl;
                                                            player->set_skill_point(player->get_SkillPoint()-10); 
                                                            //reducing skill point cz of using element
                                                            enemy->set_health_point(enemy->get_Health()-15 );
                                                            //earth to fire 5 point
                                                            
                                                        }
                                                        else {
                                                            std::cout <<  " have no element in current state. " << std::endl;
                                                            
                                                        }
                                                  
                                                    }
                                                    
                                                    else if (player_action==3){ 
                                                            std::cout <<  " ultimate attacke from player launched! " << std::endl;        
                                                            player->set_health_point(player->get_Health()-20); 
                                                            //reducing hp by 20 cz of uding ultimate
                                                            enemy->set_health_point(enemy->get_Health()-30 );
                                                            //ultimate attack take 30 damage 
                                                            

                                                                             }
                                                    break;
                                                    
                                                    default:
                                                    std::cout<<"error"<<std::endl;
                                                    printStatus();
                                                    break;
                                                }
                                                
                                    

        //normal enemy attack
            
            

                                                switch (this->level_of_game)
                                                {
                                                case 1:
                                                    std::cout << "normal enemy is attacking: "<<std::endl;
                                                    
                                                    	srand(time(NULL));
                                                    enemy_attack_option=rand() % 3+1;
                                                    if (enemy_attack_option == 1||enemy_attack_option==2)   //increased the chance of using this type of attack
                                                                           { std::cout << "basic attack from enemy done!  "<<std::endl;
                                                                           player->set_health_point(player->get_Health()-enemy->get_Attack());
                                                                           printStatus();
                                                                           }
                                                    
                                                    else if (enemy_attack_option==3)
                                                                            {
                                                                            std::cout << "fire element attack from enemy done!  "<<std::endl;
                                                                            player->set_health_point(player->get_Health()-(2*(enemy->get_Attack())));//make it more fun twice damage
                                                                            printStatus(); 

                                                                            }
                                                    
                                                    break;
                                                    
                                                    default:
                                                    std::cout<<"error"<<std::endl;
                                                    printStatus();
                                                    break;
                                                }
                                                
                                    
                }
                
                else if (player_action==1) {std::cout << "dodge is not permitted in level 1 "<<std::endl;
                                                                            }
                    else {std::cout << "Wrong input:PICK ANY FROM 1 2 OR 3. "<<std::endl;}
                }
           



                if (enemy->get_Health()<=0){std::cout<<"enemy lost!"<<std::endl;}
                else if(player->get_Health()<=0){std::cout<<"player lost!"<<std::endl;}
}