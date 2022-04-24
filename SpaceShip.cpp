#include "spaceship.h"

SpaceShip::SpaceShip(sf::RenderWindow& win) : window(&win) {

	t.loadFromFile("images/spaceship(30x40).png");
	ship.setTexture(t);
	ship.setPosition(750, 794);
}

void SpaceShip::Draw() const {

	window->draw(ship);
}

void SpaceShip::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		ship.move(0.09, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		ship.move(-0.09, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		ship.move(0, 0.10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		ship.move(0, -0.10);
	}
}

void SpaceShip::SetBoundry() {
	sf::Vector2u win = window->getSize();
	sf::Vector2f temp = ship.getPosition();
	int right = temp.x + width;
	int bottom = temp.y + height;

	if (temp.x < 0)
		ship.setPosition(0, temp.y);

	if (temp.y < 0)
		ship.setPosition(temp.x, 0);

	if (right >= win.x)
		ship.setPosition((win.x - 1) - width, temp.y);

	if (bottom >= win.y)
		ship.setPosition(temp.x, (win.y - 1) - height);
}

float SpaceShip::Getx() const {
	return ship.getPosition().x;
}

float SpaceShip::Gety() const {
	return ship.getPosition().y;
}

int SpaceShip::GetWidth() const {
	return width;
}

int SpaceShip::GetHeight() const {
	return height;
}
