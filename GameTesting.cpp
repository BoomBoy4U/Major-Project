#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "normalEnemy.h"
#include "Boss.h"
#include <iostream>
#include <string>


int main() {

   
    std::cout << "Player name enter" << std::endl;
    std::cout << "Input name: ";
    std::string name;
    std::getline(std::cin, name);
    
    ////////////////// ask for character name/////////////////

    

    ///////////////// Character info/////////////////////
    std::cout << "Character detail below: " << std::endl;
    Player p2(name, "wizard", 0, 1000, 40, 10);
    std::cout << "Name: " << p2.get_name() << std::endl;
    std::cout << "info: " << p2.get_info() << std::endl;
    std::cout << "attack: " << p2.get_Attack() << std::endl;
    

    if (p2.get_Element() == 1) {
        std::cout << p2.get_name() << " current element is fire. " << std::endl;
    }
    else if (p2.get_Element() == 2) {
        std::cout << p2.get_name() << " current element is water. " << std::endl;
    }
    else if (p2.get_Element() == 3) {
        std::cout << p2.get_name() << " current element is earth. " << std::endl;
    }
    else {
        std::cout << p2.get_name() << " have no element in current state. " << std::endl;
    }
   

    std::cout << std::endl;

    std::cout << "Enemy detail below: " << std::endl;
    Boss e2("YoYo", "dragon", 1, 1000, 10);
    std::cout << "Name: " << e2.get_name() << std::endl;
    std::cout << "info: " << e2.get_info() << std::endl;
    std::cout << "attack: " << e2.get_Attack() << std::endl;

    if (p2.get_Element() == 1) {
        std::cout << e2.get_name() << " current element is fire. " << std::endl;
    }
    else if (p2.get_Element() == 2) {
        std::cout << e2.get_name() << " current element is water. " << std::endl;
    }
    else if (p2.get_Element() == 3) {
        std::cout << e2.get_name() << " current element is earth. " << std::endl;
    }
    else {
        std::cout << e2.get_name() << " have no element in current state. " << std::endl;
    }
    std::cout << std::endl;


    while (p2.get_Health(0) > 0 && e2.get_Health(0) > 0) {
        
        std::cout << p2.get_name() << " info" << std::endl;
        std::cout << "health: " << p2.get_Health(0) << std::endl;
        std::cout << "skill point: " << p2.get_SkillPoint() << std::endl;
        
        std::cout << std::endl;


       
        std::cout << e2.get_name() << " info" << std::endl;
        std::cout << "health: " << e2.get_Health(0) << std::endl;
       
        std::cout << std::endl;



        // Player choice test /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        int option;
        std::cout << "please press number from 1 to 3: ";
        std::cin >> option;
        std::cout << std::endl;

        p2.set_playerActionOption(option);
        

       
        p2.ActionResult(p2.get_playerOption());
        std::cout << e2.get_name() << " get hit by : " << p2.get_result() << " damage." << std::endl;
        std::cout << std::endl;

        e2.get_Health(p2.get_result());
        std::cout << std::endl;


        int BossAct;
        srand(time(NULL));
        BossAct = rand() % 2 + 1;
        e2.ActionResult(BossAct);

        if (p2.get_hitMiss() == true) {
            p2.get_Health(e2.get_result());
            std::cout << p2.get_name() << " get hit by: " << e2.get_result() << " damage." << std::endl;
            std::cout << std::endl;
        } 

        else if (p2.get_hitMiss() == false) {
            p2.get_Health(0);
            std::cout << p2.get_name() << " dodge the attack." << std::endl;
            std::cout << std::endl;
        }









    }

    return 0;
}