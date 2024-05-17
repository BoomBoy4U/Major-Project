#ifndef GAMEMENU_H
#define GAMEMENU_H
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

class GameMenu
{
protected:
    bool start_Exit;
    int _Level;
    int enemies_Number;
    Player* player;
    Enemy* enemies;  //arrays of enemy
public:
    GameMenu();
    GameMenu(bool start_Exit,int start_Level);
 
    // Getter methods
    bool getStartExit() const { return start_Exit; }
    int getStartLevel() const { return _Level; }
    int getEnemiesNumber() const { return enemies_Number; }
    Player* getPlayer() const { return player; }
    Enemy* getEnemies()  { return enemies; }

    // Setter methods
    void setStartExit(bool newStartExit) { start_Exit = newStartExit; }
    void setStartLevel(int newStartLevel) { _Level = newStartLevel; }
    void setEnemiesNumber(int newEnemiesNumber) { enemies_Number = newEnemiesNumber; }
    void setPlayer(Player* newPlayer) { player = newPlayer; }
    void setEnemies(Enemy* newEnemies) { enemies = newEnemies; }

    //functions
    void init_Player_Info();
       ~GameMenu();
};

#endif