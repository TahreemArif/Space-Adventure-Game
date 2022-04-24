#include "AreYouEvenHuman.h"

AreYouEvenHuman::AreYouEvenHuman(sf::RenderWindow & win)
	:window(&win)
{
}

bool AreYouEvenHuman::Play()
{
	bool f = false, f2 = false, f3 = false, f4 = false, f5 = false, f6 = false;

	sf::Texture texture1;
	if (!texture1.loadFromFile("images/my_galaxy.JPG"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture1);
	sf::Text ans1(" RIDDLE UNLOCK ", font2, 50);
	sf::Text ans2(" RIDDLE UNLOCK ", font2, 50);
	sf::Text ans3(" RIDDLE UNLOCK ", font2, 50);
	sf::Text ans4(" RIDDLE UNLOCK ", font2, 50);

	// question 1
	sf::Text riddle1(" UNLOCK RIDDLE 1 ", font2, 60);
	riddle1.setPosition(200, 40);
	riddle1.move(200, 50);
	riddle1.setFillColor(sf::Color::Cyan);
	sf::Vector2f r1 = riddle1.getPosition();
	sf::Text q1("What is the hottest planet in our solar system??", font2, 60);
	q1.setPosition(110, 100);
	q1.move(110, 100);
	sf::Vector2f positiona = q1.getPosition();
	sf::Text op1("(A) uranus        (B) venus       (C) mercury ", font2, 60);
	op1.setPosition(110, 150);
	op1.move(110, 150);
	sf::Vector2f position1 = op1.getPosition();

	//question 2
	sf::Texture texture2;
	if (!texture2.loadFromFile("images/galaxy-f.JPG"))
		return EXIT_FAILURE;
	sf::Sprite sprite1(texture2);
	sf::Text riddle2(" UNLOCK RIDDLE 2 ", font2, 60);
	riddle2.setPosition(200, 40);
	riddle2.move(200, 50);
	riddle2.setFillColor(sf::Color::Cyan);
	sf::Vector2f r2 = riddle2.getPosition();
	sf::Text q2("Our solar system is located in what galaxy??", font2, 50);
	q2.setPosition(5, 100);
	q2.move(90, 100);
	sf::Vector2f positionb = q2.getPosition();
	sf::Text op2("(D) whirpool galaxy  (E) BlackEye galaxy ", font2, 50);
	op2.setPosition(5, 150);
	op2.move(90, 150);
	sf::Vector2f ques2 = op2.getPosition();
	sf::Text op3("(F) Milkyway galaxy ", font2, 50);
	op3.setPosition(5, 200);
	op3.move(90, 200);
	sf::Vector2f position2 = op3.getPosition();

	//question 3
	sf::Texture texture3;
	if (!texture3.loadFromFile("images/galaxy-c.JPG"))
		return EXIT_FAILURE;
	sf::Sprite sprite2(texture3);
	sf::Text riddle3(" UNLOCK RIDDLE 3 ", font2, 60);
	riddle3.setPosition(200, 40);
	riddle3.move(200, 50);
	riddle3.setFillColor(sf::Color::Cyan);
	sf::Vector2f r3 = riddle3.getPosition();
	sf::Text q3("I am bigger then Venus but smaller than Uranus??", font2, 60);
	q3.setPosition(130, 100);
	q3.move(90, 100);
	sf::Vector2f positionc = q3.getPosition();
	sf::Text op4("(G) Earth       (H) Jupiter        (I) Pluto", font2, 60);
	op4.setPosition(120, 150);
	op4.move(90, 150);
	sf::Vector2f position3 = op4.getPosition();

	// question 4
	sf::Texture texture4;
	if (!texture4.loadFromFile("images/galaxy-c.JPG"))
		return EXIT_FAILURE;
	sf::Sprite sprite3(texture4);
	sf::Text riddle4(" UNLOCK RIDDLE 4 ", font2, 60);
	riddle4.setPosition(200, 40);
	riddle4.move(200, 50);
	riddle4.setFillColor(sf::Color::Cyan);
	sf::Vector2f r4 = riddle4.getPosition();
	sf::Text q4("Which planet spins fastest in galaxy??", font2, 60);
	q4.setPosition(130, 100);
	q4.move(90, 100);
	sf::Vector2f positiond = q4.getPosition();
	sf::Text op5("(J) Earth       (K) Jupiter         (L) Pluto", font2, 60);
	op5.setPosition(120, 150);
	op5.move(90, 150);
	sf::Vector2f position4 = op5.getPosition();

	// question 5
	sf::Texture texture5;
	if (!texture5.loadFromFile("images/galaxy-K.JPG"))
		return EXIT_FAILURE;
	sf::Sprite sprite4(texture5);
	sf::Text riddle5(" UNLOCK RIDDLE 5 ", font2, 60);
	riddle5.setPosition(200, 40);
	riddle5.move(200, 50);
	riddle5.setFillColor(sf::Color::Cyan);
	sf::Vector2f r5 = riddle5.getPosition();
	sf::Text q5("Which planet is known as Morning stars??", font2, 60);
	q5.setPosition(130, 100);
	q5.move(90, 100);
	sf::Vector2f positione = q5.getPosition();
	sf::Text op6("(M) Earth       (N) Jupiter        (O) Venus", font2, 60);
	op6.setPosition(120, 150);
	op6.move(90, 150);
	sf::Vector2f position5 = op6.getPosition();

	ans[0] = 'B', ans[1] = 'F', ans[2] = 'G', ans[3] = 'K', ans[4] = 'O';
	char userAnswer[5];

	music.play();
	music.setLoop(true);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)

				window->close();
		}

		// ans1
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::B) || sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			ans1.setPosition(100, 250);
			ans1.move(100, 150);
			window->draw(ans1);
			ans1.setFillColor(sf::Color::Cyan);
			sf::Vector2f a1 = ans1.getPosition();
			f = true;
			userAnswer[0] = event.text.unicode;
		}

		// ans2
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			ans2.setPosition(100, 250);
			ans2.move(100, 150);
			window->draw(ans2);
			ans2.setFillColor(sf::Color::Cyan);
			sf::Vector2f a2 = ans2.getPosition();
			f2 = true;
			userAnswer[1] = event.text.unicode;
		}//if2

		 //ans3
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) || sf::Keyboard::isKeyPressed(sf::Keyboard::H) || sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			ans3.setPosition(100, 250);
			ans3.move(100, 150);
			window->draw(ans3);
			ans3.setFillColor(sf::Color::Cyan);
			sf::Vector2f a3 = ans3.getPosition();
			f3 = true;
			userAnswer[2] = event.text.unicode;
		}//if3

		 //ans4
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) || sf::Keyboard::isKeyPressed(sf::Keyboard::K) || sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			ans4.setPosition(100, 250);
			ans4.move(100, 150);
			window->draw(ans4);
			ans4.setFillColor(sf::Color::Cyan);
			sf::Vector2f a4 = ans4.getPosition();
			f4 = true;
			userAnswer[3] = event.text.unicode;
		}

		//ans5
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) || sf::Keyboard::isKeyPressed(sf::Keyboard::N) || sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			f5 = true;
			userAnswer[4] = event.text.unicode;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			sf::Texture texture6;
			if (!texture6.loadFromFile("images/galaxy-K.JPG"))
				return EXIT_FAILURE;
			sf::Sprite sprite5(texture6);
			window->draw(sprite5);
			sf::Text ans6("NEXT LEVEL", font2, 50);
			ans6.setPosition(150, 250);
			ans6.move(150, 250);
			window->draw(ans6);
			ans6.setFillColor(sf::Color::Cyan);
			sf::Vector2f a6 = ans6.getPosition();
			window->draw(ans6);

			f6 = true;
		}

		window->clear();
		window->draw(sprite);

		window->draw(q1);
		window->draw(riddle1);
		window->draw(op1);
		if (f == true)
		{
			{ window->draw(ans1);
			}

			window->draw(sprite1);
			window->draw(q2);
			window->draw(riddle2);
			window->draw(op2);
			window->draw(op3);

			if (f2 == true)
			{
				window->draw(ans2);
				window->draw(sprite2);
				window->draw(q3);
				window->draw(riddle3);
				window->draw(op4);
				if (f3 == true)
				{
					window->draw(sprite3);
					window->draw(q4);
					window->draw(riddle4);
					window->draw(op5);
					if (f4 == true)
					{
						window->draw(sprite4);
						window->draw(q5);
						window->draw(riddle5);
						window->draw(op6);
						if (f5 == true)
						{
							count = 0;
							for (int i = 0; i < 5; i++)
							{
								if (ans[i] == userAnswer[i])
								{
									count++;
								}

								if (i == 4)
								{
									sf::Text ans5(std::to_string(count) + " OUT OF 5 CORRECT ANSWERS  ", font2, 50);
									ans5.setPosition(150, 250);
									ans5.move(150, 250);
									window->draw(ans5);
									sf::Text ans6("PRESS Z TO CONTINUE", font2, 50);
									ans6.setPosition(150, 300);
									ans6.move(150, 300);
									window->draw(ans6);

									ans5.setFillColor(sf::Color::Cyan);
									sf::Vector2f a5 = ans5.getPosition();
									window->draw(ans5);

									if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
									{
										if (count == 5) {
											music.stop();
											return true;
										}
										else {
											music.stop();
											return false;
										}
									}

									if (f6 == true)
									{
										f6 = false;
									}
								}
							}
						}
					}//q4
				}//q3
			}// q2
		} //if q1

		window->display();

	}//while
	return EXIT_SUCCESS;
}

void AreYouEvenHuman::ShowInstructions()
{
	sf::RenderWindow window1(sf::VideoMode(1280, 728), "SFML window");
	// Load a sprite to display
	/*sf::Texture texture3;
	if (!texture3.loadFromFile("outer-space-hd-wallpaper.jpg"))
	return EXIT_FAILURE;
	sf::Sprite sprite(texture3);*/

	// Create a graphical text to display
	sf::Text help("INSTRUCTIONS", font1, 60);
	help.setPosition(200, 15);
	help.move(200, 50);
	help.setFillColor(sf::Color::Yellow);
	sf::Vector2f h1 = help.getPosition();

	sf::Text p1("* You have been captured by people on an unknown planet.", font1, 30);
	p1.setPosition(20, 100);
	p1.move(20, 100);
	p1.setFillColor(sf::Color::Cyan);
	sf::Vector2f a = p1.getPosition();

	sf::Text p2("* But! they greatly respect humans b/c of their scientificknowledge.", font1, 30);
	p2.setPosition(20, 130);
	p2.move(20, 130);
	p2.setFillColor(sf::Color::Cyan);
	sf::Vector2f b = p2.getPosition();

	sf::Text p3("* Prove to them you're human by answering thier questions.", font1, 30);
	p3.setPosition(20, 160);
	p3.move(20, 160);
	p3.setFillColor(sf::Color::Cyan);
	sf::Vector2f c = p3.getPosition();

	sf::Text p4("* There are total five riddles, you need to solve all the riddles .", font1, 30);
	p4.setPosition(20, 190);
	p4.move(20, 190);
	p4.setFillColor(sf::Color::Cyan);
	sf::Vector2f d = p4.getPosition();

	sf::Text p5("* Make sure all the anwers must be enter in (CAPITAL FORM) .", font1, 30);
	p5.setPosition(20, 220);
	p5.move(20, 220);
	p5.setFillColor(sf::Color::Cyan);
	sf::Vector2f e = p5.getPosition();
	sf::Clock clock;
	while (!(clock.getElapsedTime().asSeconds() > 15))
	{
		window1.clear();
		//window1.draw(sprite);
		window1.draw(help);
		window1.draw(p1);
		window1.draw(p2);
		window1.draw(p3);
		window1.draw(p4);
		window1.draw(p5);
		window1.display();
	}
	window1.close();
}

int AreYouEvenHuman::count = 0;