#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include "Boss.h"

#include <vector>

//using namespace sf;

int main()
{
	Player* player = new Player("user", "1st_player", 3, 150, 50, 5);
	Enemy* enemy = new Enemy();
	
	
	
	
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//Init Game engine
	Game game(player,enemy);

	//Game loop
	while (game.running() && !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
	}	

	//End of application
	delete player;
    delete enemy;
	return 0;



}