#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <string>


int main() {
    std::string name;
    std::cout << "Input name: ";
    std::getline(std::cin, name);

 Player p2(name, "wizard", 0, 100, 40, 10);


        std::cout << "Name: " << p2.get_name() << std::endl;
        std::cout << "info: " << p2.get_info() << std::endl;
        std::cout << "attack: " << p2.get_Attack() << std::endl;

        if (p2.get_Element() == 1) {
            std::cout << "element is: " << p2.get_Element() << ". So it is fire" << std::endl;
        }
        else if (p2.get_Element() == 2) {
            std::cout << "element is: " << p2.get_Element() << ". So it is water" << std::endl;
        }
        else if (p2.get_Element() == 3) {
            std::cout << "element is: " << p2.get_Element() << ". So it is earth" << std::endl;
        }
        else {
            std::cout << "element is: " << p2.get_Element() << ". no element determined" << std::endl;
        }


    while (p2.get_Health() != 0) {
        std::cout << "health: " << p2.get_Health() << std::endl;
        std::cout << "skill point: " << p2.get_SkillPoint() << std::endl;
        

        // Player choice test /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int option;
        std::cout << "please press number from 1 to 3: ";
        std::cin >> option;
        
        p2.set_playerActionOption(option);
        std::cout << "Player Option: " << p2.get_playerOption() << std::endl;
        std::cout << p2.get_name() << " action deal: " << p2.ActionResult(p2.get_playerOption()) << std::endl;
        std::cout << "player hit or miss: " << p2.get_hitMiss() << std::endl;



        if (p2.get_Element() == 1) {
            std::cout << "element is: " << p2.get_Element() << ". So it is fire" << std::endl;
        }
        else if (p2.get_Element() == 2) {
            std::cout << "element is: " << p2.get_Element() << ". So it is water" << std::endl;
        }
        else if (p2.get_Element() == 3) {
            std::cout << "element is: " << p2.get_Element() << ". So it is earth" << std::endl;
        }
        else {
            std::cout << "element is: " << p2.get_Element() << ". no element determined" << std::endl;
        }





    }

    return 0;
}