#include"Character.h"
Character::Character()
{
	Height = 34;
	Width = 34;
	if (!CharacterP.loadFromFile("images/character_sprite1.png"))
		EXIT_FAILURE;
	character.setTexture(CharacterP);
	character.setPosition(247, 501);
}
void Character::setPosition(float x, float y)
{
	character.setPosition(x, y);
}
void Character::setTextureRect(sf::IntRect a)
{
	character.setTextureRect(a);
}
void Character::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		character.setTextureRect({ 0,102,34,34 });
		character.move(0, -22);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		character.setTextureRect({ 0,0,34,34 });
		character.move(0, 22);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		character.setTextureRect({ 0,68,34,34 });
		character.move(22, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		character.setTextureRect({ 0,34,34,34 });
		character.move(-22, 0);
	}
}
sf::Vector2f Character::getPosition()
{
	return character.getPosition();
}