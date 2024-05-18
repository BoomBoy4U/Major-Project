
#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include"Entity.h"
#include "Enemy.h"
#include "Boss.h"
#include <vector>


int main() {


    //player initialise
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << std::endl;
    Player* player = new Player(name, "elementalless", 0, 12000, 10, 10);

    //player select stage
    int stage;
    std::cout << "Choose the stage: ";
    std::cin >> stage;
    std::cout << std::endl;

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

    
    //play the game
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
