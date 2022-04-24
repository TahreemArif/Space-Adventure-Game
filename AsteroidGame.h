#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Asteroids.h"
#include "SpaceShip.h"
#include <iostream>

class AsteroidGame : public Game {

private:
	sf::RenderWindow *window, window1;
	sf::Texture t1, t2;
	sf::Sprite background, explosion;
	Asteroids asteroids;
	SpaceShip ship;
	sf::SoundBuffer buffer;
	sf::Sound explosion_sound;
	bool end;

public:
	AsteroidGame(sf::RenderWindow& win);
	bool Play();
	void ShowInstructions();
};
