#include "Asteroids.h"
#include <SFML/Graphics.hpp>

Asteroids::Asteroids(sf::RenderWindow& win) : window(&win) {
	t1.loadFromFile("images/aestroid_dark(30x30).png");
	t2.loadFromFile("images/aestroid_gay_2(30x30).png");
	t3.loadFromFile("images/aestroid_grey(30x30).png");

	srand(time(0));

	for (int i = 0; i < 5; i++)
		asteroids[i].setTexture(t1);

	for (int i = 5; i < 10; i++)
		asteroids[i].setTexture(t2);

	for (int i = 10; i < 15; i++)
		asteroids[i].setTexture(t3);

	for (int i = 0; i < n; i++)
		asteroids[i].setPosition(rand() % 1500, rand() % 750);
}

void Asteroids::Draw() {

	for (int i = 0; i < n; i++)
		window->draw(asteroids[i]);
}

void Asteroids::Update() {

	srand((time(0)));
	for (int i = 0; i < n; i++)
		asteroids[i].move(0.24f, 0.03f);

	sf::Vector2u winsize = window->getSize();

	for (int i = 0; i < n; i++) {
		sf::Vector2f position = asteroids[i].getPosition();
		float asteroid_right = position.x + width;
		float asteroid_bottom = position.y + height;

		if (position.x >= winsize.x)
			asteroids[i].setPosition(0, position.y);
		if (position.y >= winsize.y)
			asteroids[i].setPosition(position.x, 0);
	}
}

bool Asteroids::CheckCollide(SpaceShip& s) {

	float s_left = s.Getx();
	float s_right = s.Getx() + s.GetWidth();
	float s_bottom = s.Gety() + s.GetHeight();
	float s_top = s.Gety();

	for (int i = 0; i < n; i++) {

		float left = asteroids[i].getPosition().x;
		float right = asteroids[i].getPosition().x + width;
		float top = asteroids[i].getPosition().y;
		float bottom = asteroids[i].getPosition().y + height;

		if (!(right < s_left || left > s_right ||
			top > s_bottom || bottom < s_top))
			isCollide = true;
	}

	return isCollide;
}
