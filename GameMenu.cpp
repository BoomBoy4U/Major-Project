#include "GameMenu.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Boss.h"

GameMenu::GameMenu(Player* player)
    : Gameplay(*new std::vector<Entity*>(), player), startOrExit(1), pass_stage1(0), pass_stage2(0), pass_stage3(0) {}

void GameMenu::start() {
    // Enter your name
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << std::endl;

    // Open file to write player name and game result
    std::ofstream outfile("game_result.txt");
    if (!outfile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    outfile << "Player Name: " << name << std::endl;

    // Start the game
    while (startOrExit != 0) {
        // User select stage
        int stage;
        std::cout << "Choose the stage: ";
        std::cin >> stage;
        std::cout << std::endl;

        while (stage < 1 || stage > 3) {
            std::cout << "Invalid Option! Choose the stage 1, 2, or 3: ";
            std::cin >> stage;
            std::cout << std::endl;
        }

        // Play the selected stage
        playStage(stage);

        // Ask user if they want to continue the game
        std::cout << "Do you want to continue the game? 1(yes) or 0(no)?: ";
        std::cin >> startOrExit;

        while (startOrExit < 0 || startOrExit > 1) {
            std::cout << "Please click 1 or 0! 1(yes) or 0(no)?: ";
            std::cin >> startOrExit;
        }

        // Save file to unlock all stages once all stages are cleared
        if (pass_stage1 == 1 && pass_stage2 == 1 && pass_stage3 == 1) {
            pass_stage1 = 1;
            pass_stage2 = 1;
            pass_stage3 = 1;
        }
    }

    // Record the game results
    recordResults();

    // Show the results
    showResults();
}

void GameMenu::playStage(int stage) {
    // Player state in different stages
    Player* player = new Player(name, "elementalless", 0, 0, 0, 0); // initialise default state

    if (stage == 1) {
        player->set_health_point(200);
        player->set_skill_point(40);
        player->set_attack(10);
    } else if (stage == 2) {
        player->set_health_point(800);
        player->set_skill_point(80);
        player->set_attack(20);
    } else if (stage == 3) {
        player->set_health_point(200);
        player->set_skill_point(140);
        player->set_attack(30);
    }

    // Enemy vector
    Enemy* zodiak = new Enemy("zodiak", "fire", 1, 80, 10);
    Boss* Sage = new Boss("Sage", "Water", 2, 200, 10);
    Enemy* golem = new Enemy("Golem", "earth", 3, 200, 10);
    Boss* dragon = new Boss("dragon", "fire", 1, 300, 20);

    std::vector<Entity*> Enemies1;
    std::vector<Entity*> Enemies2;
    std::vector<Entity*> Enemies3;

    Gameplay stage1(Enemies1, player);
    Gameplay stage2(Enemies2, player);
    Gameplay stage3(Enemies3, player);

    Enemies1.push_back(zodiak);
    Enemies2.push_back(zodiak);
    Enemies2.push_back(Sage);
    Enemies2.push_back(golem);
    Enemies3.push_back(zodiak);
    Enemies3.push_back(Sage);
    Enemies3.push_back(golem);
    Enemies3.push_back(dragon);

    // Gameplay of selected stage or can't access the stage lock
    if (stage == 1) {
        pass_stage1 = stage1.play(Enemies1, player);
    } else if (stage == 2 && pass_stage1 == 1) {
        pass_stage2 = stage2.play(Enemies2, player);
    } else if (stage == 3 && pass_stage2 == 1) {
        pass_stage3 = stage3.play(Enemies3, player);
    } else {
        std::cout << "Can't access the locked stage yet!" << std::endl;
    }

    delete player;
    delete zodiak;
    delete Sage;
    delete golem;
    delete dragon;
}

void GameMenu::recordResults() {
    std::ofstream outfile("game_result.txt", std::ios_base::app);
    if (!outfile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    outfile << "Passed Stages: ";
    if (pass_stage1 == 1) outfile << "1 ";
    if (pass_stage2 == 1) outfile << "2 ";
    if (pass_stage3 == 1) outfile << "3 ";
    outfile << std::endl;
    outfile.close();
}

void GameMenu::showResults() {
    std::ifstream infile("game_result.txt");
    if (!infile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }
    infile.close();
}
