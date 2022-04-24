#pragma once
#include <SFML/Graphics.hpp>
#include"spaceship.h"

class Asteroids {
private:
	sf::RenderWindow *window;
	static constexpr int n = 15;
	sf::Texture t1, t2, t3;
	sf::Sprite asteroids[n];
	static constexpr int width = 30;
	static constexpr int height = 30;
	bool isCollide = false;

public:
	Asteroids(sf::RenderWindow& win);
	void Draw();
	void Update();
	bool CheckCollide(SpaceShip& s);
};