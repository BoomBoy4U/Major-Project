#include "Entity.h"
#include <iostream>
#include <string>


int main() {

    Entity p1;
    Entity p2("Sophana", "wizard", 1,  100, 40, 10);

    std::cout << "Name: " << p2.get_name() << std::endl;
    std::cout << "info: " << p2.get_info() << std::endl;
    
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

    std::cout << "health: " << p2.get_Health() << std::endl;
    std::cout << "skill point: " << p2.get_SkillPoint() << std::endl;
    std::cout << "attack: " << p2.get_Attack() << std::endl;


    return 0;
}