#include "menu.h"
#include <string>

Menu::Menu(sf::RenderWindow & win) : window(&win) {

	t.loadFromFile("images/bg2.jpg");
	t1.loadFromFile("images/arrowLeft.png");
	t3.loadFromFile("images/title6.png");
	background.setTexture(t);
	back_button.setTexture(t1);
	title_image.setTexture(t3);
	title_image.setPosition(80, 200);

	font.loadFromFile("fonts/kenvector_future_thin.ttf");
	font1.loadFromFile("fonts/Starjout.ttf");

	title.setFont(font1);
	title.setString("SPACE \nADVENTURE \nGAME");
	title.setStyle(sf::Text::Bold);
	title.setCharacterSize(72);
	title.setPosition(150, 160);

	buffer.loadFromFile("sounds/menu-selection-click.wav");
	ButtonClick.setBuffer(buffer);
	ButtonClick.setVolume(50);
}


MainMenu::MainMenu(sf::RenderWindow& win) : Menu(win) {
	t1.loadFromFile("images/play_button_blue.png");
	t2.loadFromFile("images/credits_button_blue.png");
	t3.loadFromFile("images/exit_button_blue.png");

	start_button.setTexture(t1);
	credits_button.setTexture(t2);
	exit_button.setTexture(t3);

	start_button.setPosition(920, 200);
	credits_button.setPosition(920, 320);
	exit_button.setPosition(920, 440);

	button_width = 137;
	button_height = 88;
}

void MainMenu::draw() {
	
	window->clear();
	window->draw(background);
	window->draw(title_image);
	window->draw(start_button);
	window->draw(credits_button);
	window->draw(exit_button);
}

int MainMenu::update()
{
	//music.play();
	if (isClicked(start_button, *window, button_width, button_height)) {
		ButtonClick.play();
		return 1;
	}
	if (isClicked(credits_button, *window, button_width, button_height)) {
		ButtonClick.play();
		draw_credits();
	}
	if (isClicked(exit_button, *window, button_width, button_height)) {
		ButtonClick.play();
		window->close();
	}
}

void MainMenu::draw_credits()
{
	sf::Clock clock;
	window1.create(sf::VideoMode(500, 500), "SFML window", sf::Style::None);
	while (!(clock.getElapsedTime().asSeconds() > 5)) {
		window1.clear();
		sf::Text text("Credits", font, 28);
		text.setPosition(195, 0);
		window1.draw(text);
		window1.display();
	}
	window1.close();
}

PlayerMenu::PlayerMenu(sf::RenderWindow& win) : Menu(win) {
	t1.loadFromFile("images/new_game.png");
	t2.loadFromFile("images/saved_game.png");

	new_game.setTexture(t1);
	saved_game.setTexture(t2);

	new_game.setPosition(910, 290);
	saved_game.setPosition(910, 360);
}

void PlayerMenu::draw() {
	window->clear();
	window->draw(background);
	//window->draw(title);
	window->draw(title_image);
	window->draw(new_game);
	window->draw(saved_game);
	window->draw(back_button);
}

int PlayerMenu::update() {
	if (isClicked(new_game, *window, 200, 50)) {
		ButtonClick.play();
		return 1;
	}
	if (isClicked(saved_game, *window, 200, 50)) {
		ButtonClick.play();
		return 2;
	}
	if (isClicked(back_button, *window, 50, 50) || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		ButtonClick.play();
		return 3;
	}
}


LevelMenu::LevelMenu(sf::RenderWindow & win) : Menu(win) {
	title.setString("SPACE ADVENTURE GAME");

	t1.loadFromFile("images/level1.png");
	t2.loadFromFile("images/level2.png");
	t3.loadFromFile("images/level3.png");
	t5.loadFromFile("images/line.png");

	level1.setTexture(t1);
	level2.setTexture(t2);
	level3.setTexture(t3);
	line1.setTexture(t5);
	line2.setTexture(t5);

	level1.setPosition(400, 350);
	level2.setPosition(600, 350);
	level3.setPosition(800, 350);

	line1.setPosition(500, 400);
	line2.setPosition(700, 400);
}

void LevelMenu::draw() {
	window->clear();
	window->draw(background);
	window->draw(title);
	window->draw(level1);
	window->draw(level2);
	window->draw(level3);
	window->draw(back_button);
	window->draw(line1);
	window->draw(line2);

}

int LevelMenu::update()
{
	if (isClicked(level1, *window, 100, 100) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		ButtonClick.play();
		return 1;
	}
	if (isClicked(level2, *window, 100, 100) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		ButtonClick.play();
		return 2;
	}
	if (isClicked(level3, *window, 100, 100) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		ButtonClick.play();
		return 3;
	}
	
	if (isClicked(back_button, *window, 50, 50) || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		ButtonClick.play();
		return 5;
	}

	/*while (isHovering(level1, *window, 100, 100))
		s_level1.play();
	while (isHovering(level2, *window, 100, 100))
		s_level2.play();
	while (isHovering(level3, *window, 100, 100))
		s_level3.play();
	while (isHovering(level4, *window, 100, 100))
		s_level4.play();*/
}

void LevelMenu::draw_lives(int lives){

	if (lives < 1000000000) {
		std::string l = std::to_string(lives);

		sf::Text text1("lives left: ", font, 28);
		text1.setPosition(1000, 10);
		sf::Text text2(l, font, 28);
		text2.setPosition(1200, 10);

		window->draw(text1);
		window->draw(text2);
	}
}