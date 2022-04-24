#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game {
protected:
	sf::Music music;
	sf::Font font1, font2;
	bool status;

public:
	Game();
	virtual bool Play() = 0;
	virtual void ShowInstructions() = 0;
	//bool getStatus() const;
};