#include <iostream>
#include "GameMenu.h"
#include "Player.h"

using namespace std;

void testConstructor() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    cout << "testConstructor PASSED" << endl;
     cout << "                   next test is coming up!!  " << endl;
}

void testStart() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    cout << "Running testStart. Follow the instructions for input." << endl;
    menu.start();
    cout << "                   testStart PASSED  " << endl;
     cout << "                   next test is coming up!!  " << endl;
}

void testPlayStage() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    menu.playStage(1);  // Test stage 1
    menu.playStage(2);  // Test stage 2
    menu.playStage(3);  // Test stage 3
    cout << "testPlayStage PASSED" << endl;
     cout << "                   next test is coming up!!  " << endl;
}

void testRecordResults() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    menu.recordResults();
    cout << "testRecordResults PASSED" << endl;
     cout << "                   next test is coming up!!  " << endl;
}

void testShowResults() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    menu.showResults();
    cout << "testShowResults PASSED" << endl;
     cout << "                   next test is coming up!!  " << endl;
}

int main() {

    cout<<endl<<"this test is containing 5 small tests, it is time consuming but follow the steps!"<<endl<<endl;
    testConstructor();
    testStart();
    testPlayStage();
    testRecordResults();
    testShowResults();

    cout << "All tests completed." << endl;
    return 0;
}
