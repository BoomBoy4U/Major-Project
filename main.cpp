#include"Enemy.h"
#include "Player.h"
#include "Entity.h"
#include "GameMenu.h"
#include "GameInit.h"
#include "GameAttack.h"
using namespace std;

int main ()
{   
    GameMenu newgame(true,1);
    Player arian("aian","12",3,100,120,10);
    newgame.setPlayer(&arian);
    GameAttack GA(&newgame);
    GA.full_Attacl_battel();

    

    
    
   
    


    








    return 0;
}