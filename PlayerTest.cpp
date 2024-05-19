#include <iostream>
#include "Player.h"

using namespace std;

void testDefaultConstructor() {
    Player player;
    if (player.get_name() == "NA" &&
        player.get_info() == "NA" &&
        player.get_Element() == 0 &&
        player.get_Health() == 0 &&
        player.get_SkillPoint() == 0 &&
        player.get_Attack() == 0 &&
        player.get_dodge() == false) {
        cout << "testDefaultConstructor PASSED" << endl;
    } else {
        cout << "testDefaultConstructor FAILED" << endl;
    }
}

void testParameterizedConstructor() {
    Player player("Hero", "Main player", 1, 100, 50, 20);
    if (player.get_name() == "Hero" &&
        player.get_info() == "Main player" &&
        player.get_Element() == 1 &&
        player.get_Health() == 100 &&
        player.get_SkillPoint() == 50 &&
        player.get_Attack() == 20 &&
        player.get_dodge() == false) {
        cout << "testParameterizedConstructor PASSED" << endl;
    } else {
        cout << "testParameterizedConstructor FAILED" << endl;
    }
}

void testSetGetDodge() {
    Player player;
    player.set_dodge(true);
    if (player.get_dodge() == true) {
        cout << "testSetGetDodge PASSED (true)" << endl;
    } else {
        cout << "testSetGetDodge FAILED (true)" << endl;
    }
    player.set_dodge(false);
    if (player.get_dodge() == false) {
        cout << "testSetGetDodge PASSED (false)" << endl;
    } else {
        cout << "testSetGetDodge FAILED (false)" << endl;
    }
}

void testDamageDealtDodge() {
    Player player;
    int damage = player.damageDealt(20, 1);
    if (damage == 0) {
        cout << "testDamageDealtDodge PASSED" << endl;
    } else {
        cout << "testDamageDealtDodge FAILED" << endl;
    }
}

void testDamageDealtElementalAttack() {
    Player player("Hero", "Main player", 1, 100, 50, 20);
    int damage = player.damageDealt(20, 2);
    if (player.get_SkillPoint() == 40 && damage == 20) {
        cout << "testDamageDealtElementalAttack PASSED" << endl;
    } else {
        cout << "testDamageDealtElementalAttack FAILED" << endl;
    }
}

void testDamageDealtUltimateAttack() {
    Player player("Hero", "Main player", 1, 100, 50, 20);
    int damage = player.damageDealt(20, 3);
    if (player.get_Health() == 80 && damage == 100) {
        cout << "testDamageDealtUltimateAttack PASSED" << endl;
    } else {
        cout << "testDamageDealtUltimateAttack FAILED" << endl;
    }
}

int main() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testSetGetDodge();
    testDamageDealtDodge();
    testDamageDealtElementalAttack();
    testDamageDealtUltimateAttack();

    cout << "All tests completed." << endl;
    return 0;
}
