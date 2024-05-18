
#include <iostream>
#include "Gameplay.h"
#include "Player.h"
#include"Entity.h"
#include "Enemy.h"
#include "Boss.h"
#include <vector>


int main() {
//xxxxxxxxxxxxxxEnter ur name
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << std::endl;

// initialise user start or exit the game  // initialise user stage clear pass or no
    int startOrExit = 1;
    int pass_stage1 = 0;
    int pass_stage2= 0;

    //Start the game. note: we might be able to create a class for it.
    while (startOrExit != 0) {

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx user select stage.
        //player select stage
        int stage;
        std::cout << "Choose the stage: ";
        std::cin >> stage;
        std::cout << std::endl;       

        while (stage < 1 || stage > 3) {
            std::cout << "invalid Option!. Choose the stage 1 or 2 or 3: ";
            std::cin >> stage;
            std::cout << std::endl;
        }
        

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx player state in different stage
        //player initialise. player state varied depend on stage level
        Player* player = new Player(name, "elementalless", 0, 0, 0, 0); //initialise default state

        if (stage == 1) {
            player->set_health_point(200);
            player->set_skill_point(40);
            player->set_attack(10);
        }
        else if (stage == 2) {
            player->set_health_point(800);
            player->set_skill_point(80);
            player->set_attack(20);
        }
        else if (stage == 3) {
            player->set_health_point(200);
            player->set_skill_point(140);
            player->set_attack(30);
        }

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx enemy vector

        //define the enemy type
        Enemy* zodiak = new Enemy("zodiak", "fire", 1, 80, 10);
        Boss* Sage = new Boss("Sage", "Water", 2, 200, 10);
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


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

        //gameplay of selected stage or cant access the stage lock
        if (stage == 1) {
            pass_stage1 = stage1.play(Enemies1, player);
            //std::cout << "Congratulation you pass stage 1. now stage 2 is unlock" << std::endl;
        }

        else if (stage == 2 && pass_stage1 == 1) {
            pass_stage2 = stage2.play(Enemies2, player);
            //std::cout << "Congratulation you pass stage 2. now stage 3 is unlock" << std::endl;  
        }

        else if (stage == 3 && pass_stage2 == 1) {
            stage3.play(Enemies3, player);
            //std::cout << "Congratulation you pass all stage! Now you can choose any stage" << std::endl;
        }
        else {
            std::cout << "Cant access the lock stage yet!";
        }


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx user input to continue or exit main function
        //ask user if the want to continue the game
            std::cout << "Do you want to continue the game? 1(yes) or 0(no)?: ";
            std::cin >> startOrExit;

            while (startOrExit < 0 || startOrExit > 1) {
                std::cout << "Please click 1 or 0! 1(yes) or 0(no)?: ";
                std::cin >> startOrExit;
            }


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx save file to unlock all stage once all stage clear

        //all stage will be unlock to user once all stage clear so user can replay other stage again.
        //problem is if the main function exit, the value will revert back we might need a sabe file that can save this one
        if (pass_stage1 == 1 && pass_stage2 == 1) {
        pass_stage1 = 1;
        pass_stage2 = 1;
        }
    }
//xxxxxxxxxxxxxxxexit while loop



    return 0;
}
