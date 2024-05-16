
#include <iostream>
#include "GameStage.h"
#include "Player.h"
#include"Entity.h"
#include "Enemy.h"

int main(){
    Player Arian ("arian","20yo",150,120,10,5);
    Enemy Zodiak ("zodiak", "fire",1,80,10);
    GameStage testLevel1(1,&Arian,&Zodiak);
    testLevel1.gameplay();




    return 0;
}
