#include "Game.h"

Game::Game(){
	status = false;

	music.openFromFile("sounds/Epic Modern Futuristic Space Music.ogg");

	if (!font1.loadFromFile("fonts/kenvector_future_thin.ttf"))
		EXIT_FAILURE;
	if (!font2.loadFromFile("fonts/HARRYP.ttf"))
		EXIT_FAILURE;
}

//bool Game::getStatus()const
//{
//	return status;
//}