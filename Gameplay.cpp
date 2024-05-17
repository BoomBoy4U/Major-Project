#include "Gameplay.h"
Gameplay::Gameplay(std::vector<Entity*>& _enemies, Player* player) :enemies(_enemies) {
    player = new Player[1];
    player = player;
}

void Gameplay::addPlayer(Player* player) {
	this->player = player;
}
void Gameplay::addenemy(Enemy* enemy) {
	enemies.push_back(enemy);
}

void Gameplay::addBoss(Boss* boss) {
	enemies.push_back(boss);
}

void Gameplay::play(std::vector<Entity*>& enemies, Player* player) {

    while (!enemies.empty() && player->get_Health() > 0) {
        if (!enemies.empty()) {
        Entity* currentEnemy = enemies.back();
        std::cout << "Current Enemy: " << currentEnemy->get_name() << std::endl;
        std::cout << std::endl;

            std::cout << player->get_name() << ":" << std::endl;
            std::cout << player->get_Health() << " || " << player->get_SkillPoint() << std::endl;
            std::cout << std::endl;
            std::cout << currentEnemy->get_name() << ":" << std::endl;
            std::cout << currentEnemy->get_Health() << " || " << currentEnemy->get_SkillPoint() << std::endl;
            std::cout << std::endl;
            // Player actions

            int choice;
            std::cout << "1. dodge\n2. Use Skill\n3. utimate\n" << std::endl;
            std::cout << "Choose your action: ";
            std::cin >> choice;
            std::cout << std::endl;

            while (choice < 1 || choice > 3) {
                std::cout << "invalid Option! Choose your action again:" << std::endl;
                std::cout << "1. dodge\n2. Use Skill\n3. utimate\n" << std::endl;
                std::cin >> choice;

            }

            while (player->get_SkillPoint() <= 0 && choice == 2) {
                std::cout << "No SP! Choose your action again either 1 or 3:" << std::endl;
                std::cout << "1. dodge\n2. Use Skill\n3. utimate\n" << std::endl;
                std::cin >> choice;
            }



            
            if (choice == 2) {
                if (player->get_Element() == 1 && currentEnemy->get_Element() == 3) {
                    player->damageDealt(player->get_Attack(), choice);
                    //std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
                    currentEnemy->set_health_point(currentEnemy->get_Health() - 2*player->get_damage());
                    std::cout << player->get_name() << " use fire" << " and deal " << player->get_damage() << std::endl;
                }

                else if (player->get_Element() == 2 && currentEnemy->get_Element() == 1) {
                    player->damageDealt(player->get_Attack(), choice);
                    //std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
                    currentEnemy->set_health_point(currentEnemy->get_Health() - 2*player->get_damage());
                    std::cout << player->get_name() << " use water" << " and deal " << 2*player->get_damage() << std::endl;
                }

                else if (player->get_Element() == 3 && currentEnemy->get_Element() == 2) {
                    player->damageDealt(player->get_Attack(), choice);
                    //std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
                    currentEnemy->set_health_point(currentEnemy->get_Health() - 2*player->get_damage());
                    std::cout << player->get_name() << " use earth" << " and deal " << 2*player->get_damage() << std::endl;
                } 
                else {
                    player->damageDealt(player->get_Attack(), choice);
                    //std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
                    currentEnemy->set_health_point(currentEnemy->get_Health() - player->get_damage());
                    std::cout << player->get_name() << " use wrong element against enemy" << " and deal " << player->get_damage() << std::endl;
                }
            }

            else if (choice == 1) {
                player->damageDealt(player->get_Attack(), choice);
                std::cout << player->get_name() << " use dodge." << std::endl;
            }

            else if (choice == 3) {
                player->damageDealt(player->get_Attack(), choice);
                currentEnemy->set_health_point(currentEnemy->get_Health() - player->get_damage());
                std::cout << player->get_name() << " deal " << player->get_damage() << std::endl;
            }

            // Check if enemy defeated
            if (currentEnemy->get_Health() <= 0) {
                std::cout << currentEnemy->get_name() << " defeated!" << std::endl;
                std::cout << std::endl;
                enemies.pop_back(); // Remove defeated enemy from vector
            } 

            else if (currentEnemy->get_Health() >= 0 && player->get_dodge() == false) {
                player->set_health_point(player->get_Health() - currentEnemy->damageDealt(currentEnemy->get_Attack()));
                std::cout << currentEnemy->get_name() << " deal " << currentEnemy->get_damage() << std::endl;
            }   

            else if (currentEnemy->get_Health() >= 0 && player->get_dodge() == true) {
                currentEnemy->damageDealt(currentEnemy->get_Attack());
                std::cout << currentEnemy->get_name() << " deal " << currentEnemy->get_damage() << " However, " << player->get_name() << " dodge the attack." << std::endl;
                bool dodgeRevert = false;
                player->set_dodge(dodgeRevert);
                //std::cout << player->get_name() << "dodge the attack!" << std::endl;
            }
        }
    }

    //std::cout << "Game end " << std::endl;

    if (player->get_Health() <= 0) {
        std::cout << "Game Over! You have been defeated." << std::endl;
    }

    if (player->get_Health() >= 0 && enemies.empty()) {
        std::cout << "Congratulations! You have pass the stage and defeated all enemies including the boss." << std::endl;
    }
    

    // Clean up memory
    for (auto Entity : enemies) {
        delete Entity;
    }
  
}