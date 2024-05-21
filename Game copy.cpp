#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->endGame = false;
	this->maxEnemies = 5;
	this->mouseHeld = false;
	this->mouseHeld2 = false;
	int playerHP = 0;
	int playerSP = 0;
	int enemyHP = 0;
	this->currentLevel = 1; // Start at level 1
	

	this->maxButtons = 3;
	this->gameState = MAIN_MENU;
	this->gameStarted = false;
	this->playerName = ""; //initializing player name 

	this->enemyDefeated = false; // Initialize the enemyDefeated flag
    this->playerDefeated = false; // Initialize the playerDefeated flag
	
}

void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1000;

	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(36);
	this->uiText.setFillColor(sf::Color::Red);
	this->uiText.setString("game has not started!");

	this->uiText2.setFont(this->font);
	this->uiText2.setCharacterSize(36);
	this->uiText2.setFillColor(sf::Color::Red);
	this->uiText2.setString("game has not started!");

	this->namePromptText.setFont(this->font);
    this->namePromptText.setCharacterSize(24);
    this->namePromptText.setFillColor(sf::Color::White);
    this->namePromptText.setString("Enter your name:");
    this->namePromptText.setPosition(this->videoMode.width / 2.f - 100.f, this->videoMode.height / 2.f - 50.f);

    this->playerNameText.setFont(this->font);
    this->playerNameText.setCharacterSize(24);
    this->playerNameText.setFillColor(sf::Color::White);
    this->playerNameText.setPosition(this->videoMode.width / 2.f - 100.f, this->videoMode.height / 2.f);

	this->playerNameDisplayText.setFont(this->font);
    this->playerNameDisplayText.setCharacterSize(24);
    this->playerNameDisplayText.setFillColor(sf::Color::White);
}

void Game::initImages() {
    if (!textureP.loadFromFile("PNGS/player.png")) {
        std::cout << "error loading first image!" << std::endl;
    }

    spriteP.setTexture(textureP);
    spriteP.setPosition(100.f, 200.f);

    std::cout << "loading images done right!" << std::endl;
}

void Game::loadTextures() {
    sf::Texture texture;
    
    // Load textures for enemies
    if (!texture.loadFromFile("PNGS/enemy1.png")) {
        std::cout << "Error loading enemy1.png" << std::endl;
    }
    enemyTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/enemy2.png")) {
        std::cout << "Error loading enemy2.png" << std::endl;
    }
    enemyTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/enemy3.png")) {
        std::cout << "Error loading enemy3.png" << std::endl;
    }
    enemyTextures.push_back(texture);

    // Load textures for bosses
    if (!texture.loadFromFile("PNGS/boss1.png")) {
        std::cout << "Error loading boss1.png" << std::endl;
    }
    bossTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/boss2.png")) {
        std::cout << "Error loading boss2.png" << std::endl;
    }
    bossTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/boss3.png")) {
        std::cout << "Error loading boss3.png" << std::endl;
    }
    bossTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/boss4.png")) {
        std::cout << "Error loading boss4.png" << std::endl;
    }
    bossTextures.push_back(texture);
}


void Game::initButton()
{	
	this->button.setPosition(150.f, 150.f);
	this->button.setRadius(8.f);
	this->button.setFillColor(sf::Color::Red);
	this->button.setOutlineColor(sf::Color::Green);
	this->button.setOutlineThickness(1.f);
}
void Game::initStartButton() {
    this->startButton.setSize(sf::Vector2f(200.f, 50.f));
    this->startButton.setFillColor(sf::Color::Green);
    this->startButton.setPosition(this->videoMode.width / 2.f - this->startButton.getSize().x / 2.f, this->videoMode.height / 2.f);

    this->startButtonText.setFont(this->font);
    this->startButtonText.setCharacterSize(36);
    this->startButtonText.setFillColor(sf::Color::Black);
    this->startButtonText.setString("Start Game");
    this->startButtonText.setPosition(this->startButton.getPosition().x + 20.f, this->startButton.getPosition().y + 10.f);
}

void Game::initEnemies() {
    // If there's any common initialization logic for enemies across levels, place it here.
    // Currently, it can be left empty if we don't have any common initialization logic.

    // Example: Pre-load textures if not already done in loadTextures
    if (enemyTextures.empty() && bossTextures.empty()) {
        this->loadTextures();
    }

    // Further initialization logic if needed...
}

//Constructors / Destructors
Game::Game(Player* player , Enemy* enemy2)

{
	this->player = player;
	this->enemy2=enemy2;
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initEnemies();
	this->initButton();
	this->initImages();
	this->initStartButton();
	std::cout << "Current Enemy: " << enemy2->get_name() << std::endl;
        std::cout << std::endl;

            std::cout << player->get_name() << ":" << std::endl;
            std::cout << player->get_Health() << " || " << player->get_SkillPoint() << std::endl;
            std::cout << std::endl;
            std::cout << enemy2->get_name() << ":" << std::endl;
            std::cout << enemy2->get_Health() << " || " << enemy2->get_SkillPoint() << std::endl;
            std::cout << std::endl;
}



//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

//Functions

void Game::spawnButtons()
{

	for (int i = 0; i < maxButtons; i++)
	{
		this->button.setRadius(70.f);
		this->button.setFillColor(sf::Color::Green);
		this->button.setPosition(sf::Vector2f(static_cast < float>(200*i+100), static_cast < float>(700)));
		this->buttons.push_back(this->button);
		switch (i)
		{
		case 0:
			this->uiText.setString("DODGE");
			this->uiText.setPosition(static_cast <float>(200 * i +120), static_cast <float>(850));
			this->uiTexts.push_back(uiText);
			break;

		case 1:
			this->uiText.setString("ELEMENT");
			this->uiText.setPosition(static_cast <float>(200 * i + 120), static_cast <float>(850));
			this->uiTexts.push_back(uiText);
			break;
		case 2: 
			this->uiText.setString("ULTIMATE");
			this->uiText.setPosition(static_cast <float>(200 * i + 120), static_cast <float>(850));
			this->uiTexts.push_back(uiText);
			break;
		default:
			std::cout << "error in spawn button naming" << std::endl;
			break;
		}
			
	}

}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (this->ev.mouseButton.button == sf::Mouse::Left) {
                    if (this->gameState == MAIN_MENU) {
                        if (this->startButton.getGlobalBounds().contains(this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))) {
                            this->handleStartButtonClick();
                        }
                    }
                }
                break;
            case sf::Event::TextEntered:
                if (this->gameState == NAME_INPUT) {
                    this->handleTextInput(this->ev);
                }
                break;
        }
    }
}

void Game::handleStartButtonClick() {
    this->gameState = NAME_INPUT;
   // this->uiText.setString("Enter your name:");
}

void Game::handleTextInput(sf::Event event) {
    if (event.text.unicode == '\b') {
        // Handle backspace
        if (!this->playerName.empty()) {
            this->playerName.pop_back();
        }
    } else if (event.text.unicode == '\r') {
        // Handle enter key
        this->gameState = GAMEPLAY;
        this->player->set_Name(this->playerName); // Set the player name
        this->playerNameDisplayText.setString("PLAYER: " + this->playerName); // Set the display text
        // Center the player name at the top of the screen
        sf::FloatRect textRect = this->playerNameDisplayText.getLocalBounds();
        this->playerNameDisplayText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        this->playerNameDisplayText.setPosition(sf::Vector2f(this->videoMode.width / 2.0f, textRect.height));
    } else {
        // Handle regular text input
        this->playerName += static_cast<char>(event.text.unicode);
    }
    this->playerNameText.setString(this->playerName);
}


void Game::updateMousePositions()
{
	/**
		@ return void
		Updates the mouse positions:
		- Mouse position relative to window (Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies() {
    // Remove defeated enemies from the list
    for (size_t i = 0; i < enemies.size();) {
        if (enemies[i]->get_Health() <= 0) {
            delete enemies[i];
            std::cout<<"error234"<<std::endl;
            enemies.erase(enemies.begin() + i);
        } else {
            ++i;
        }
    }

    // Check for level completion
    if (currentLevel == 1 && enemies.empty()) {
        std::stringstream ss;
        ss << "Congratulations! You have passed the stage" << "\n"
           << "and defeated all enemies including the boss." << "\n";

        this->uiText2.setString(ss.str());
        this->uiText2.setPosition(10.f, 350.f);
        this->uiText2.setCharacterSize(50);

        this->currentLevel = 2; // Move to the next level
        this->loadLevel2();
    } else if (currentLevel == 2 && enemies.empty()) {
        std::stringstream ss;
        ss << "Congratulations! You have passed the stage" << "\n"
           << "and defeated all enemies including the boss." << "\n";

        this->uiText2.setString(ss.str());
        this->uiText2.setPosition(10.f, 350.f);
        this->uiText2.setCharacterSize(50);

        this->currentLevel = 3; // Move to the next level
        this->loadLevel3();
    }
}
void Game::updateButtons()
{
	//Updating the timer for enemy spawning
	if (this->buttons.size() < this->maxButtons)
	{
		//Spawn the enemy and reset the timer
		this->spawnButtons();

	}


	//Check if clicked upon
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{ 
		if (this->mouseHeld2 == false)
		{	
			mouseHeld2 = true;
			for (size_t i = 0; i < this->buttons.size(); i++)
			{ 
				
            														
				if (this->buttons[i].getGlobalBounds().contains(this->mousePosView))
				
				{
					if (enemy2->get_Health()>0 && player->get_Health() > 0)
				{			std::cout<<"checker 111"<<std::endl;
					 
                
					//Gain points
					if (i == 0)
						std::cout<<"dodge not permitted in level 1"<<std::endl;
					else if (i == 1)
					{	if (player->get_SkillPoint() <= 0 ){break;}
						else{if (player->get_Element() == 1 && enemy2->get_Element() == 3) {
							player->damageDealt(player->get_Attack(), 2);
							//std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
							enemy2->set_health_point(enemy2->get_Health() - 2 * player->get_damage());
							std::cout << player->get_name() << " use fire" << " and deal " << player->get_damage() << std::endl;

							std::stringstream ss;

							ss << "playerHP: " << player->get_Health() << "\n"
								<< "PlayerSP " << player->get_SkillPoint() << "\n"
								<< "EnemyHp " << enemy2->get_Health() << "\n";

							this->uiText2.setString(ss.str());
						}

						else if (player->get_Element() == 2 && enemy2->get_Element() == 1) {
							player->damageDealt(player->get_Attack(), 2);
							//std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
							enemy2->set_health_point(enemy2->get_Health() - 2 * player->get_damage());
							std::cout << player->get_name() << " use water" << " and deal " << 2 * player->get_damage() << std::endl;

							std::stringstream ss;

							ss << "playerHP: " << player->get_Health() << "\n"
								<< "PlayerSP " << player->get_SkillPoint() << "\n"
								<< "EnemyHp " << enemy2->get_Health() << "\n";

							this->uiText2.setString(ss.str());
						}

						else if (player->get_Element() == 3 && enemy2->get_Element() == 2) {
							player->damageDealt(player->get_Attack(), 2);
							//std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
							enemy2->set_health_point(enemy2->get_Health() - 2 * player->get_damage());
							std::cout << player->get_name() << " use earth" << " and deal " << 2 * player->get_damage() << std::endl;

							std::stringstream ss;

							ss << "playerHP: " << player->get_Health() << "\n"
								<< "PlayerSP " << player->get_SkillPoint() << "\n"
								<< "EnemyHp " << enemy2->get_Health() << "\n";

							this->uiText2.setString(ss.str());
						}
						else {
							player->damageDealt(player->get_Attack(), 2);
							//std::cout << "Elment number: " << player->get_Element() << " and" << currentEnemy->get_Element() << std::endl;
							enemy2->set_health_point(enemy2->get_Health() - player->get_damage());
							std::cout << player->get_name() << " use wrong element against enemy" << " and deal " << player->get_damage() << std::endl;

							std::stringstream ss;

							ss << "playerHP: " << player->get_Health() << "\n"
								<< "PlayerSP " << player->get_SkillPoint() << "\n"
								<< "EnemyHp " << enemy2->get_Health() << "\n";

							this->uiText2.setString(ss.str());
						}
					}
					}
					else if (i == 2)
					{this->points += 0;

					player->damageDealt(player->get_Attack(), 3);
                	enemy2->set_health_point(enemy2->get_Health() - player->get_damage());
               		 std::cout << player->get_name() << " deal " << player->get_damage() << std::endl;
					
							std::stringstream ss;

							ss << "playerHP: " << player->get_Health() << "\n"
								<< "PlayerSP " << player->get_SkillPoint() << "\n"
								<< "EnemyHp " << enemy2->get_Health() << "\n";

							this->uiText2.setString(ss.str());

					}
						if (enemy2->get_Health() <= 0) {
							std::cout << enemy2->get_name() << " defeated!" << std::endl;
							std::cout << std::endl;

							std::stringstream ss;
							ss << "ENEMY IS DEAD WELL DONE!" << "\n";

							this->uiText2.setString(ss.str());
							this->uiText2.setPosition(10.f, 350.f);
							this->uiText2.setCharacterSize(50);

							this->enemyDefeated = true; // Set the enemyDefeated flag
						}
				
				if (player->get_Health() <= 0) {
					    std::cout << "Game Over! You have been defeated." << std::endl;
						std::stringstream ss;
						ss << "Game Over! You have been defeated." << "\n";

						this->uiText2.setString(ss.str());
						this->uiText2.setPosition(10.f, 350.f);
						this->uiText2.setCharacterSize(50);

						this->playerDefeated = true; // Set the playerDefeated flag
									
				}

				
					
					  }
				}
			}
		}
	}
	
		
		else
		{
			this->mouseHeld2 = false;
		}
	
			


}


void Game::update() {
    this->pollEvents();
    
        this->updateMousePositions();
        this->updateEnemies();
        this->updateButtons();
    }
   




void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
	for (auto& e : this->uiTexts)
	{
		target.draw(e);
	}
}

void Game::drawImages(sf::RenderTarget& target) {
    if (!playerDefeated) { // Draw player only if not defeated
        target.draw(spriteP);
    }
    for (auto& enemy : this->enemies) {
        target.draw(enemy->getSprite());
    }
}

void Game::renderEnemies(sf::RenderTarget& target) {
    for (auto& e : this->enemies) {
        target.draw(e->getSprite());
    }
}

void Game::renderButtons(sf::RenderTarget& target)
{
	for (auto& e : this->buttons) 
	{
		target.draw(e);
	}
	target.draw(uiText2);
}


void Game::render() {
    this->window->clear();
    if (this->gameState == MAIN_MENU) {
        this->window->draw(this->startButton);
        this->window->draw(this->startButtonText);
    } else if (this->gameState == NAME_INPUT) {
        this->window->draw(this->namePromptText);
        this->window->draw(this->playerNameText);
    } else if (this->gameState == GAMEPLAY) {
        this->window->draw(this->playerNameDisplayText); // Render the player's name at the top center
        this->drawImages(*this->window);
        this->renderText(*this->window);
        this->renderButtons(*this->window);
    }
    this->window->display();
}

void Game::loadLevel1() {
    // Clear existing enemies
    for (auto& enemy : this->enemies) {
        delete enemy;
    }
    this->enemies.clear();

    // Add enemies for level 1
    Enemy* enemy = new Enemy("enemy1", "element", 3, 100, 10);
    enemy->setTexture(enemyTextures[0]);
    Boss* boss = new Boss("boss1", "fire", 5, 200, 20);
    boss->setTexture(bossTextures[0]);
    this->enemies.push_back(enemy);
    this->enemies.push_back(boss);
}

void Game::loadLevel2() {
    // Clear existing enemies
    for (auto& enemy : this->enemies) {
        delete enemy;
    }
    this->enemies.clear();

    // Add enemies for level 2
    Enemy* enemy = new Enemy("enemy2", "element", 4, 150, 15);
    enemy->setTexture(enemyTextures[1]);
    Boss* boss = new Boss("boss2", "ice", 6, 300, 30);
    boss->setTexture(bossTextures[1]);
    this->enemies.push_back(enemy);
    this->enemies.push_back(boss);
}

void Game::loadLevel3() {
    // Clear existing enemies
    for (auto& enemy : this->enemies) {
        delete enemy;
    }
    this->enemies.clear();

    // Add enemies for level 3
    Enemy* enemy = new Enemy("enemy3", "element", 5, 200, 20);
    enemy->setTexture(enemyTextures[2]);
    Boss* boss1 = new Boss("boss3", "earth", 7, 400, 40);
    boss1->setTexture(bossTextures[2]);
    Boss* boss2 = new Boss("boss4", "lightning", 8, 500, 50);
    boss2->setTexture(bossTextures[3]);
    this->enemies.push_back(enemy);
    this->enemies.push_back(boss1);
    this->enemies.push_back(boss2);
}

Game::~Game()
{
	delete this->window;
	 for (auto& enemy : this->enemies) {
        delete enemy;
    }
	
}

   