output: main.o GameInit.o GameAttack.o GameMenu.o Entity.o Player.o Enemy.o 
	g++  main.o GameInit.o GameAttack.o GameMenu.o Entity.o Player.o Enemy.o -o output

main.o: main.cpp
	g++ -c main.cpp
GameInit.o: GameInit.cpp GameInit.h
	g++ -c GameInit.cpp

GameMenu.o: GameMenu.cpp GameMenu.h
	g++ -c GameMenu.cpp

Player.o: Player.cpp Player.h 
	g++ -c Player.cpp 

Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp

Entity.o: Entity.cpp Enemy.h
	g++ -c Entity.cpp

GameAttack.o: GameAttack.cpp GameAttack.h
	g++ -c GameAttack.cpp



clean:
	rm *.o output
	