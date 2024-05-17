
#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include"Entity.h"
#include "Enemy.h"
#include "Boss.h"
#include "vector"


int main() {

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << std::endl;

    Player* player = new Player(name, "elementalless", 0, 120, 100, 10);

    int stage;
    std::cout << "Choose the stage: ";
    std::cin >> stage;
    std::cout << std::endl;

    if (stage == 1) {
        std::vector<Entity*> Enemies;
        Enemies.push_back(new Enemy("zodiak", "fire", 1, 80, 10));
        Gameplay stage1(Enemies, player);
        stage1.play(Enemies, player);
        //std::cout <<"Congratulation you pass stage 1. " << std::endl;
    }

    if (stage == 2) {
        std::vector<Entity*> Enemies;
        Enemies.push_back(new Enemy("zodiak", "fire", 1, 80, 10));
        Enemies.push_back(new Boss("Sage", "Water", 2, 200, 10));
        Gameplay stage1(Enemies, player);
        stage1.play(Enemies, player);
        //std::cout << "Congratulation you pass stage 2. " << std::endl;
    }

   
    if (stage == 3) {
        std::vector<Entity*> Enemies;
        Enemies.push_back(new Enemy("zodiak", "fire", 1, 80, 10));
        Enemies.push_back(new Boss("Sage", "Water", 2, 200, 10));
        Enemies.push_back(new Enemy("Golem", "earth", 3, 200, 10));
        Gameplay stage1(Enemies, player);
        stage1.play(Enemies, player);
        //std::cout << "Congratulation you pass stage 3. " << std::endl;
    }


    




    
    






 //   Player Sophana("Sophana", "Wizard", 150, 240, 20, 10);
 //   //Entity** enemies = new Entity*[3];
 //   //Enemy* Zodiak2 = new Enemy ("zodiak", "fire", 1, 100, 10);
 //   //Enemy* Golem = new Enemy ("Golem", "earth", 3, 120, 15);
 //   //Boss* Sage = new Boss ("Sage", "water", 2, 240, 20);

 //   //Entity* enemies = new Entity[3];
 //   //Enemy Zodiak2("zodiak", "fire", 1, 100, 10);
 //   //Enemy Golem("Golem", "earth", 3, 120, 15);
 //   //Enemy Sage("Sage", "water", 2, 240, 20);

 ///*   enemies[0] = Zodiak2;
 //   enemies[1] = Golem;
 //   enemies[2] = Sage;*/


 //   std::vector <Entity*> enemies2;



 //   enemies2.push_back(new Enemy("zodiak", "fire", 1, 100, 10));
 //   enemies2.push_back(new Enemy("Golem", "earth", 3, 120, 15));
 //   enemies2.push_back(new Boss("Sage", "water", 2, 240, 20));
 //   GameStage testLevel3(1, &Sophana, enemies2);
 //   testLevel3.gameplay();


    return 0;
}