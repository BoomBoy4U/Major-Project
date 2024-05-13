#include "Entity.h"
#include "Enemy.h"
#include "normalEnemy.h"
#include <iostream>
#include <string>


int main() {
    normalEnemy p2("YoYo", "dragon", 1, 20, 5);



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

     std::cout << "Enemy health: " << p2.get_Health() << std::endl;
     std::cout << "Enemy action deal: " << p2.ActionResult() << std::endl;

    

    return 0;
}