#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include<string>
#include<iostream>
using namespace std;

class AreYouEvenHuman : public Game
{
private:

	sf::Keyboard keyPressed;
	sf::Text answer1;
	sf::Texture display;
	static int count;
	char ans[5];
	int mycount = 0;
	sf::RenderWindow *window;


public:
	AreYouEvenHuman(sf::RenderWindow &);
	bool Play();
	void ShowInstructions();

};