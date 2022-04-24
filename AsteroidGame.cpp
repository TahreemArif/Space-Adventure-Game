#include "AsteroidGame.h"

AsteroidGame::AsteroidGame(sf::RenderWindow & win)
	: window(&win), asteroids(*window), ship(*window) {

	t1.loadFromFile("images/background.jpg");
	t2.loadFromFile("images/explosion.png");

	background.setTexture(t1);
	explosion.setTexture(t2);

	buffer.loadFromFile("sounds/Bomb-Sound.wav");
	explosion_sound.setBuffer(buffer);
}

bool AsteroidGame::Play() {

	music.play();
	music.setLoop(true);
	
	while (window->isOpen()) {

		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		window->draw(background);

		asteroids.Draw();
		ship.Draw();
		ship.SetBoundry();

		if (asteroids.CheckCollide(ship)) {
			explosion.setPosition(ship.Getx() - 65, ship.Gety() - 10);
			explosion_sound.play();
			window->draw(explosion);
			status = false;
			end = true;
		}

		else if (ship.Gety() == 0) {
			status = true;
			end = true;
		}

		else {
			asteroids.Update();
			ship.Update();
		}
		
		window->display();
		
		if (end) {
			music.stop();
			return status;
		}
	}
}

void AsteroidGame::ShowInstructions(){
	sf::RenderWindow window1(sf::VideoMode(600, 600), "SFML window", sf::Style::None);
	sf::Clock clock;
	/*sf::Texture background;
	if (!background.loadFromFile("backgroundGame.png"))
		EXIT_FAILURE;
	sf::Sprite Background(background);*/
	while (!(clock.getElapsedTime().asSeconds() > 10)) {
		window1.clear();

		//sf::Text text("How To Play", font, 34);
		sf::Text instructions0("Can you pass the ASTEROID BELT", font1, 26);
		sf::Text instructions1("       without Collision? ", font1, 26);
		sf::Text instructions3("Use arrow keys to navigate", font1, 28);
		sf::Text instructions4("        BE CAREFUL!", font2, 34);

		instructions0.setPosition(15, 150);
		instructions1.setPosition(15, 220);
		//instructions2.setPosition(15, 290);
		instructions3.setPosition(15, 360);
		instructions4.setPosition(15, 430);


		//window1.draw(Background);
		window1.draw(instructions0);
		window1.draw(instructions1);
		//window1.draw(instructions2);
		window1.draw(instructions3);
		window1.draw(instructions4);
		window1.display();
	}
	window1.close();
}

