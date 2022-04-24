#pragma once
#include<SFML\Graphics.hpp>

class Character
{
private:
	sf::Texture CharacterP;
	float Height, Width;
public:
	sf::Sprite character;
public:
	Character();
	void Move();
	void setTextureRect(sf::IntRect a);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
};