#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CustomMouse.h"

class Menu {
protected:
	sf::RenderWindow *window;
	sf::Texture t, t1, t3;
	sf::Sprite background, back_button, title_image;
	sf::Music music;
	sf::Sound button_click;
	sf::Font font, font1;
	sf::Text title;
	sf::SoundBuffer buffer;
	sf::Sound ButtonClick;

public:
	Menu(sf::RenderWindow& win);
	virtual void draw() = 0;
	virtual int update() = 0;
};


class MainMenu : public Menu {
private:
	sf::Texture t1, t2, t3;
	sf::Sprite start_button, credits_button, exit_button;
	int button_width, button_height;
	sf::Clock clock;
	sf::RenderWindow window1;
	void draw_credits();

public:
	MainMenu(sf::RenderWindow& win);
	void draw();
	int update();
};

class PlayerMenu : public Menu {
private:
	sf::Texture t1, t2;
	sf::Sprite new_game, saved_game;
public:
	PlayerMenu(sf::RenderWindow& win);
	void draw();
	int update();
};

class LevelMenu : public Menu {
private:
	sf::Texture t1, t2, t3, t5;
	sf::Sprite level1, level2, level3, line1, line2;
	//sf::SoundBuffer _1, _2, _3, _4;
	//sf::Sound s_level1, s_level2, s_level3, s_level4;

public:
	LevelMenu(sf::RenderWindow& win);
	void draw();
	int update();
	void draw_lives(int lives);
};

