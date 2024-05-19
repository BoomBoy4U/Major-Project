#include <iostream>
#include "Boss.h"

using namespace std;

void testDefaultConstructor() {
    Boss boss;
    if (boss.get_name() == "NA" &&
        boss.get_info() == "NA" &&
        boss.get_Element() == 0 &&
        boss.get_Health() == 0 &&
        boss.get_Attack() == 0) {
        cout << "testDefaultConstructor PASSED" << endl;
    } else {
        cout << "testDefaultConstructor FAILED" << endl;
    }
}

void testParameterizedConstructor() {
    Boss boss("Dragon", "Strong boss", 3, 200, 50);
    if (boss.get_name() == "Dragon" &&
        boss.get_info() == "Strong boss" &&
        boss.get_Element() == 3 &&
        boss.get_Health() == 200 &&
        boss.get_Attack() == 50) {
        cout << "testParameterizedConstructor PASSED" << endl;
    } else {
        cout << "testParameterizedConstructor FAILED" << endl;
    }
}

void testDamageDealt() {
    Boss boss("Dragon", "Strong boss", 3, 200, 50);
    int damage = boss.damageDealt(50);
    if (damage == 50 || damage == 150) { // Boss can deal normal or ultimate attack
        cout << "testDamageDealt PASSED" << endl;
    } else {
        cout << "testDamageDealt FAILED" << endl;
    }
}

int main() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testDamageDealt();

    cout << "All tests completed." << endl;
    return 0;
}
