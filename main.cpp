
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

    Player* player = new Player(name, "elementalless", 0, 12000, 100, 10);

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


        Gameplay stage1(Enemies, player);
        stage1.play(Enemies, player);
    }

        



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


    return 0;
}
