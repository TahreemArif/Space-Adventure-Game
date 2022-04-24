#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "menu.h"
#include "AsteroidGame.h"
#include "AreYouEvenHuman.h"
#include "FindTheWay.h"
#include "Game.h"
using namespace std;

void popup(string s);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Adventure Game");

	MainMenu mainmenu(window);
	LevelMenu levelmenu(window);
	PlayerMenu playermenu(window);
	Game *g;

	int lives;
	bool menu = true;
	bool menu2 = true;
	bool menu3 = true;
	bool win[3];

	sf::SoundBuffer b1, b2, b3, b4;
	b1.loadFromFile("sounds/Level Failed.wav");
	b2.loadFromFile("sounds/game-over-evil.wav");
	b3.loadFromFile("sounds/Level Passed.ogg");
	b4.loadFromFile("sounds/victory sound effect.ogg");

	sf::Sound level_failed, game_over, level_passed, game_won;
	level_failed.setBuffer(b1);
	game_over.setBuffer(b2);
	level_passed.setBuffer(b3);
	game_won.setBuffer(b4);

	sf::Music music;
	music.openFromFile("sounds/Space Theme.ogg");
	music.setVolume(10);
	music.setLoop(1);
	music.play();

	sf::Texture t;
	t.loadFromFile("images/confetti.jpg");
	sf::Sprite game_won_bg(t);

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		if (menu) {
			mainmenu.draw();
			if (mainmenu.update() == 1)
				menu = false;
			menu2 = true;
			menu3 = true;
		}

		else if (menu2) {
			playermenu.draw();
			switch (playermenu.update()) {

			case 1:
				popup("Story");
				lives = 5;
				for (int i = 0; i < 3; i++)
					win[i] = false;
				{   std::ofstream writedata("playerdata.txt");
				writedata << lives << std::endl
					<< win[0] << std::endl
					<< win[1] << std::endl
					<< win[2];
				writedata.close();
				}
				menu2 = false;
				break;

			case 2:
			{	std::ifstream readdata("playerdata.txt");
			readdata >> lives >> win[0] >> win[1] >> win[2];
			readdata.close();
			}
			menu2 = false;
			break;

			case 3:
				menu = true;
				break;
			}
		}

		else if (menu3 && lives) {
			levelmenu.draw();
			levelmenu.draw_lives(lives);
			
			switch (levelmenu.update()) {
			
			case 1: {
				music.stop();
				g = new AsteroidGame(window);
				std::cout << "asteroid Game" << std::endl;
				//g->ShowInstructions();
				int temp = win[0];

				if (g->Play()) {
					level_passed.play();
					win[0] = true;
					popup("LEVEL PASSED");
				}
				else {
					level_failed.play();
					if (temp == false)
						--lives;
					popup("LEVEL FAILED");
				}

				std::ofstream writedata("playerdata.txt");
				writedata << lives << std::endl
					<< win[0] << std::endl
					<< win[1] << std::endl
					<< win[2];
				writedata.close();
			}
					delete g;
					music.play();
				break;

			case 2:
				music.stop();
				if (win[0]){
					g = new AreYouEvenHuman(window);
					std::cout << "Quiz Game" << std::endl;
					//g->ShowInstructions();
					int temp = win[1];

					if (g->Play()) {
						level_passed.play();
						win[1] = true;
						popup("LEVEL PASSED");

					}
					else {
						level_failed.play();
						if (temp == false)
							--lives;
						popup("LEVEL FAILED");
					}

					std::ofstream writedata("playerdata.txt");
					writedata << lives << std::endl
						<< win[0] << std::endl
						<< win[1] << std::endl
						<< win[2];
					writedata.close();

					delete g;
				}
				else
					popup("Level locked");


				music.play();
				break;

			case 3:
				music.stop();
				if (win[0] && win[1]) {
					g = new FindTheWay(window);
					std::cout << "Maze Game" << std::endl;
					int temp = win[2];
					
			//		g->ShowInstructions();
				
					if (g->Play()) {
						level_passed.play();
						win[2] = true;
						popup("LEVEL PASSED");
					}
					else {
						level_failed.play();
						if (temp == false)
							--lives;
						popup("LEVEL FAILED");
					}

					if (temp == false && win[2] == true) {
						lives = 1000000000;
						game_won.play();
						popup("    YOU WON");
						/*sf::Clock clock;
						while (1) {
							if (!(clock.getElapsedTime().asSeconds() > 7)) {
								window.clear();
								window.draw(game_won_bg);
							}

							else if (clock.getElapsedTime().asSeconds() > 7)
								break;
						}*/
					}

					std::ofstream writedata("playerdata.txt");
					writedata << lives << std::endl
						<< win[0] << std::endl
						<< win[1] << std::endl
						<< win[2];
					writedata.close();

					delete g;
				}
				else
					popup("Level locked");
				music.play();
				break;

			//back button
			case 5:
				menu = true;
				break;
			}

		}
		else {
			music.pause();
			game_over.play();
			popup("GAME OVER");
			menu = true;
			music.play();
		}

		window.display();
	}

	return EXIT_SUCCESS;
}

void popup(string s) {
	sf::Font font;
	font.loadFromFile("fonts/kenvector_future_thin.ttf");
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(300, 50), "pop-up", sf::Style::None);
	while (!(clock.getElapsedTime().asSeconds() > 2)) {
		window.clear();
		sf::Text text(s, font, 28);
		text.setPosition(((window.getSize().x) / s.size()) - (s.size() / 2), 0);
		window.draw(text);
		window.display();
	}
	window.close();
}