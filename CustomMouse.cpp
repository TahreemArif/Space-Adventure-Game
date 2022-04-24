#include "CustomMouse.h"

bool isClicked(sf::Sprite & s, sf::RenderWindow & window, int breadth, int length){
	return
		sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
		sf::Mouse::getPosition(window).x >= s.getPosition().x &&
		sf::Mouse::getPosition(window).y >= s.getPosition().y &&
		sf::Mouse::getPosition(window).x <= s.getPosition().x + breadth &&
		sf::Mouse::getPosition(window).y <= s.getPosition().y + length;
}

bool isHovering(sf::Sprite & s, sf::RenderWindow & window, int breadth, int length){
	return
		sf::Mouse::getPosition(window).x >= s.getPosition().x &&
		sf::Mouse::getPosition(window).y >= s.getPosition().y &&
		sf::Mouse::getPosition(window).x <= s.getPosition().x + breadth &&
		sf::Mouse::getPosition(window).y <= s.getPosition().y + length;
}

