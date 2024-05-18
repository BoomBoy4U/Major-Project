
#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include"Entity.h"
#include "Enemy.h"
#include "Boss.h"
#include <vector>


int main() {

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << std::endl;

    Player* player = new Player(name, "elementalless", 0, 12000, 10, 10);

    int stage;
    std::cout << "Choose the stage: ";
    std::cin >> stage;
    std::cout << std::endl;

    //just for fun (random generated stage)
    if (stage == 999) {
        std::vector<Entity*> Enemies;
        srand(time(NULL));

            std::string name;
            int bossOrEnemy = 0;
            int element = 0;
            std::string elementType;

        for (int i = 0; i < rand() % 20 + 1; i++) {
            int type = rand() % 3 + 1;

            switch (type) {
            case 1:
                name = "zodiak";
                bossOrEnemy = 1;
                elementType = "FIRE";
                element = 1;
                break;

            case 2:
                name = "Sage";
                bossOrEnemy = 2;
                elementType = "WATER";
                element = 1;
                break;

            case 3:
                name = "Golem";
                bossOrEnemy = 1;
                elementType = "EARTH";
                element = 1;
                break;

            default:
                break;
            }
            
            if (bossOrEnemy == 1) {
                int health = rand() % 300 + 100;
                int attack = rand() % 50 + 10;
                Enemies.push_back(new Enemy(name, elementType, element, health, attack));
            }
            else if (bossOrEnemy == 2) {
                int health = rand() % 1000 + 500;
                int attack = rand() % 50 + 10;
                Enemies.push_back(new Boss(name, elementType, element, health, attack));
            }
        }


        Gameplay stage999(Enemies, player);
        stage999.play(Enemies, player);
    }


    //define the enemy type
    Enemy* zodiak = new Enemy("zodiak", "fire", 1, 80, 10);
    Boss* Sage = new Boss ("Sage", "Water", 2, 200, 10);
    Enemy* golem = new Enemy("Golem", "earth", 3, 200, 10);
    Boss* dragon = new Boss("dragon", "fure", 1, 300, 20);
    

    //initialise enemies array vector
    std::vector<Entity*> Enemies1;
    std::vector<Entity*> Enemies2;
    std::vector<Entity*> Enemies3;


    //initialise stage 1
    Gameplay stage1(Enemies1, player);

    //initialise stage 2
    Gameplay stage2(Enemies2, player);

    //initialise stage 3
    Gameplay stage3(Enemies3, player);

    //add enemies in stage 1
    Enemies1.push_back(zodiak);

    //add enemies in stage 2
    Enemies2.push_back(zodiak);
    Enemies2.push_back(Sage);
    Enemies2.push_back(golem);

    //add enemies in stage 3
    Enemies3.push_back(zodiak);
    Enemies3.push_back(Sage);
    Enemies3.push_back(golem);
    Enemies3.push_back(dragon);

        
    if (stage == 1) {
        stage1.play(Enemies1, player);
        std::cout <<"Congratulation you pass stage 1. " << std::endl;
    }   

    if (stage == 2 && stage1.get_stage() == 1) {
        stage2.play(Enemies2, player);
        std::cout << "you completed stage 2. " << std::endl;
    }

    if (stage == 3 && stage2.get_stage() == 1) {
        stage3.play(Enemies3, player);
        std::cout << "Congratulation you pass stage 3. " << std::endl;
    }


    return 0;
}
