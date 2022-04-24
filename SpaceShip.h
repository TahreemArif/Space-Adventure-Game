#pragma once
#include <SFML/Graphics.hpp>

class SpaceShip {
private:
	sf::RenderWindow *window;
	sf::Texture t;
	sf::Sprite ship;
	static constexpr int width = 30;
	static constexpr int height = 40;

public:
	SpaceShip(sf::RenderWindow& win);
	void Draw() const;
	void Update();
	void SetBoundry();
	float Getx() const;
	float Gety() const;
	int GetWidth() const;
	int GetHeight() const;
};
