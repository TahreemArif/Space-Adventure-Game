#include"FindTheWay.h"
# include<string>
using namespace std;
FindTheWay::FindTheWay(sf::RenderWindow & win) : window(&win)
{
	OneStep = 22.0f;
	FinishPoint.x = 907;
	FinishPoint.y = 237;
	if (!BackgroundP.loadFromFile("images/mars.png"))
		EXIT_FAILURE;
	if (!MazeP.loadFromFile("images/large12.png"))
		EXIT_FAILURE;
	if (!DoorP.loadFromFile("images/door1.png"))
		EXIT_FAILURE;

	show_time.setFont(font1);
	Background.setTexture(BackgroundP);
	Maze.setTexture(MazeP);
	Maze.setPosition(190.0f, 52.5);
	Door.setTexture(DoorP);
	Door.setPosition(1050, 100);
}
void FindTheWay::DrawLevel()
{
	window->clear();
	window->draw(Background);
	window->draw(Maze);
	window->draw(Player.character);
	window->draw(Door);
	window->draw(show_time);
	window->display();


}
void FindTheWay::Door_Setting()
{
	int Door_Width = 91;
	int Door_Height = 100;
	if (clock.getElapsedTime().asSeconds() >= 60)
	{
		Door.setTextureRect({ 0,0,Door_Width,Door_Height });
		window->draw(Door);
	}
	else if (clock.getElapsedTime().asSeconds() >= 45)
	{
		Door.setTextureRect({ 0,100,Door_Width,Door_Height });
		window->draw(Door);
	}
	else if (clock.getElapsedTime().asSeconds() >= 30)
	{
		Door.setTextureRect({ 0,200,Door_Width,Door_Height });
		window->draw(Door);
	}

}
bool FindTheWay::Play()
{
	music.play();
	music.setLoop(true);
	Player.setTextureRect({ 0,102,34,34 });
	Door.setTextureRect({ 0,300,91,100 });
	Player.setPosition(247, 501);
	clock.restart();
	while (window->isOpen())
	{
		Show_Elapsed_time();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				break;
			}

			Door_Setting();
			Player.Move();
			if (CheckCollision())
				KeptInWindow();


			if (clock.getElapsedTime().asSeconds() <= 10)
			{
				if (Player.getPosition() == FinishPoint)
				{
					status = true;
					music.stop();
					return true;
				}
			}
			else
			{
				music.stop();
				return false;
			}
		}
		DrawLevel();
	}
	return status;
}
bool FindTheWay::CheckCollision()
{
	if (check_Window_BoundaryCollision())
		return true;

	else if (Check_BoundaryCollision())
		return true;

	// conditions for block A
	if (Player.getPosition().x >= 247.0f && Player.getPosition().x <= 401.0f
		&& Player.getPosition().y >= 105.0f && Player.getPosition().y <= 611.0f)
	{
		sf::Vector2f * BlockA = new sf::Vector2f[76];
		for (int i = 0; i < 67; i++)
		{
			if (i >= 0 && i < 14)
				BlockA[i].x = 401.0f, BlockA[i].y = 105.0f + i * OneStep;
			if (i >= 14 && i < 27)
				BlockA[i].x = 269.0f, BlockA[i].y = 127.0f + (i - 14) * OneStep;
			if (i >= 27 && i < 34)
				BlockA[i].x = 313.0f, BlockA[i].y = 347.0f + (i - 27) * OneStep;
			if (i >= 34 && i < 39)
				BlockA[i].x = 313.0f, BlockA[i].y = 171.0f + (i - 34) * OneStep;
			if (i >= 39 && i < 44)
				BlockA[i].x = 357.0f, BlockA[i].y = 127.0f + (i - 39) * OneStep;
			if (i >= 44 && i < 47)
				BlockA[i].x = 357.0f, BlockA[i].y = 391.0f + (i - 44) * OneStep;
			if (i >= 47 && i < 50)
				BlockA[i].x = 269.0f, BlockA[i].y = 435.0f + (i - 47) * OneStep;
			if (i >= 50 && i < 53)
				BlockA[i].x = 357.0f, BlockA[i].y = 303.0f + (i - 50) * OneStep;
			if (i >= 53 && i < 55)
				BlockA[i].x = 401.0f, BlockA[i].y = 435.0f + (i - 53) * OneStep;

			//when y is constant
			if (i >= 55 && i < 58)
				BlockA[i].x = 291.0f + (i - 55) * OneStep, BlockA[i].y = 127.0f;
			if (i >= 58 && i < 61)
				BlockA[i].x = 335.0f + (i - 58) * OneStep, BlockA[i].y = 259.0f;
			if (i >= 61 && i < 64)
				BlockA[i].x = 291.0f + (i - 61) * OneStep, BlockA[i].y = 303.0f;
			if (i >= 64 && i < 67)
				BlockA[i].x = 357.0f + (i - 64) * OneStep, BlockA[i].y = 479.0f;
			BlockA[67].x = 247.0f, BlockA[67].y = 523.0f;
			BlockA[68].x = 291.0f, BlockA[68].y = 391.0f;
			BlockA[69].x = 335.0f, BlockA[69].y = 435.0f;
			BlockA[70].x = 247.0f, BlockA[70].y = 479.0f;
			BlockA[71].x = 379.0f, BlockA[71].y = 391.0f;
			BlockA[72].x = 379.0f, BlockA[72].y = 611.0f;
			BlockA[73].x = 379.0f, BlockA[73].y = 479.0f;
			BlockA[74].x = 357.0f, BlockA[74].y = 501.0f;

		}
		for (int j = 0; j < 76; j++)
			if (BlockA[j] == Player.getPosition())
			{
				return true;
			}
		//delete[]BlockA;
	}
	// conditions for block B
	else if (Player.getPosition().x >= 423.0f && Player.getPosition().x <= 797
		&& Player.getPosition().y >= 127 && Player.getPosition().y <= 347)
	{
		sf::Vector2f * BlockB = new sf::Vector2f[105];
		for (int i = 0; i < 97; i++)
		{
			if (i >= 0 && i < 17)
				BlockB[i].x = 445.0f + (OneStep * i), BlockB[i].y = 127.0f;
			if (i >= 17 && i < 27)
				BlockB[i].x = 577.0f + (i - 17)*OneStep, BlockB[i].y = 347.0f;
			if (i >= 27 && i < 32)
				BlockB[i].x = 621.0f + (i - 27) * OneStep, BlockB[i].y = 171.0f;
			if (i >= 32 && i < 36)
				BlockB[i].x = 599.0f + (i - 32) * OneStep, BlockB[i].y = 215.0f;
			if (i >= 36 && i < 40)
				BlockB[i].x = 621.0f + (i - 36) * OneStep, BlockB[i].y = 259.0f;
			if (i >= 40 && i < 44)
				BlockB[i].x = 599.0f + (i - 40) * OneStep, BlockB[i].y = 303.0f;
			if (i >= 44 && i < 48)
				BlockB[i].x = 467.0f + (i - 44) * OneStep, BlockB[i].y = 215.0f;
			if (i >= 48 && i < 51)
				BlockB[i].x = 423.0f + (i - 48) * OneStep, BlockB[i].y = 347.0f;
			if (i >= 51 && i < 54)
				BlockB[i].x = 489.0f + (i - 51) * OneStep, BlockB[i].y = 171.0f;
			// when x is constant
			if (i >= 54 && i < 61)
				BlockB[i].x = 533.0f, BlockB[i].y = 215.0f + (i - 54) * OneStep;
			if (i >= 61 && i < 70)
				BlockB[i].x = 577.0f, BlockB[i].y = 171.0f + (i - 61) * OneStep;
			if (i >= 70 && i < 77)
				BlockB[i].x = 709.0f, BlockB[i].y = 171.0f + (i - 70) * OneStep;
			if (i >= 77 && i < 83)
				BlockB[i].x = 445.0f, BlockB[i].y = 149.0f + (i - 77) * OneStep;
			if (i >= 83 && i < 88)
				BlockB[i].x = 489.0f, BlockB[i].y = 259.0f + (i - 83) * OneStep;
			if (i >= 88 && i < 92)
				BlockB[i].x = 797.0f, BlockB[i].y = 259.0f + (i - 88) * OneStep;
			if (i >= 92 && i < 97)
				BlockB[i].x = 753.0f, BlockB[i].y = 171.0f + (i - 54) * OneStep;
			BlockB[97].x = 423.0f, BlockB[97].y = 303.0f;
			BlockB[98].x = 445.0f, BlockB[98].y = 303.0f;
			BlockB[99].x = 621.0f, BlockB[99].y = 149.0f;
			BlockB[100].x = 775.0f, BlockB[100].y = 171.0f;
			BlockB[101].x = 775.0f, BlockB[101].y = 259.0f;
			BlockB[102].x = 533.0f, BlockB[102].y = 149.0f;
			BlockB[103].x = 731.0f, BlockB[103].y = 303.0f;
			BlockB[104].x = 753.0f, BlockB[104].y = 303.0f;
		}
		for (int j = 0; j < 105; j++)
			if (BlockB[j] == Player.getPosition())
			{
				return true;
			}
		//delete[]BlockB;
	}
	// conditions for block C
	else if (Player.getPosition().x >= 401.0f && Player.getPosition().x <= 775.0f
		&& Player.getPosition().y >= 369.0f && Player.getPosition().y <= 633.0f)
	{
		sf::Vector2f * BlockC = new sf::Vector2f[99];
		for (int i = 0; i < 95; i++)
		{
			// when x is constant
			if (i >= 0 && i < 7)
				BlockC[i].x = 533.0f, BlockC[i].y = 479.0f + i * OneStep;
			if (i >= 7 && i < 13)
				BlockC[i].x = 577.0f, BlockC[i].y = 523.0f + (i - 7) * OneStep;
			if (i >= 13 && i < 20)
				BlockC[i].x = 753.0f, BlockC[i].y = 391.0f + (i - 13) * OneStep;
			if (i >= 20 && i < 24)
				BlockC[i].x = 577.0f, BlockC[i].y = 391.0f + (i - 20) * OneStep;
			if (i >= 24 && i < 28)
				BlockC[i].x = 489.0f, BlockC[i].y = 435.0f + (i - 24) * OneStep;
			if (i >= 28 && i < 33)
				BlockC[i].x = 709.0f, BlockC[i].y = 523.0f + (i - 28) * OneStep;
			if (i >= 33 && i < 37)
				BlockC[i].x = 489.0f, BlockC[i].y = 567.0f + (i - 33) * OneStep;
			if (i >= 37 && i < 41)
				BlockC[i].x = 533.0f, BlockC[i].y = 369.0f + (i - 37) * OneStep;
			if (i >= 41 && i < 44)
				BlockC[i].x = 621.0f, BlockC[i].y = 391.0f + (i - 41) * OneStep;
			if (i >= 44 && i < 48)
				BlockC[i].x = 665.0f, BlockC[i].y = 501.0f + (i - 44) * OneStep;
			if (i >= 48 && i < 53)
				BlockC[i].x = 445.0f, BlockC[i].y = 391.0f + (i - 48) * OneStep;
			if (i >= 53 && i < 55)
				BlockC[i].x = 489.0f, BlockC[i].y = 369.0f + (i - 53) * OneStep;
			if (i >= 55 && i < 58)
				BlockC[i].x = 621.0f, BlockC[i].y = 567.0f + (i - 55) * OneStep;
			if (i >= 58 && i < 60)
				BlockC[i].x = 753.0f, BlockC[i].y = 611.0f + (i - 58) * OneStep;
			if (i >= 60 && i < 62)
				BlockC[i].x = 445.0f, BlockC[i].y = 589.0f + (i - 60) * OneStep;

			//when y is constant
			if (i >= 62 && i < 66)
				BlockC[i].x = 643.0f + (i - 62)* OneStep, BlockC[i].y = 435.0f;
			if (i >= 66 && i < 75)
				BlockC[i].x = 555.0f + (i - 66)* OneStep, BlockC[i].y = 479.0f;
			if (i >= 75 && i < 79)
				BlockC[i].x = 665.0f + (i - 75)* OneStep, BlockC[i].y = 391.0f;
			if (i >= 79 && i < 82)
				BlockC[i].x = 643.0f + (i - 79)* OneStep, BlockC[i].y = 611.0f;
			if (i >= 82 && i < 86)
				BlockC[i].x = 445.0f + (i - 82)* OneStep, BlockC[i].y = 523.0f;
			if (i >= 86 && i < 90)
				BlockC[i].x = 401.0f + (i - 86)* OneStep, BlockC[i].y = 567.0f;
			if (i >= 90 && i < 92)
				BlockC[i].x = 599.0f + (i - 90)* OneStep, BlockC[i].y = 523.0f;
			if (i >= 92 && i < 95)
				BlockC[i].x = 731.0f + (i - 92)* OneStep, BlockC[i].y = 567.0f;
			BlockC[95].x = 511.0f, BlockC[95].y = 391.0f;
			BlockC[96].x = 599.0f, BlockC[96].y = 391.0f;
			BlockC[97].x = 467.0f, BlockC[97].y = 435.0f;
			BlockC[98].x = 643.0f, BlockC[98].y = 567.0f;
		}
		for (int j = 0; j < 99; j++)
			if (BlockC[j] == Player.getPosition())
			{
				return true;
			}
		//delete[]BlockC;
	}
	// conditions for block D
	else if (Player.getPosition().x >= 797.0f && Player.getPosition().x <= 995.0f
		&& Player.getPosition().y >= 259.0f && Player.getPosition().y <= 633.0f)
	{
		sf::Vector2f * BlockD = new sf::Vector2f[77];
		for (int i = 0; i < 72; i++)
		{ // when x is constant
			if (i >= 0 && i < 8)
				BlockD[i].x = 797.0f, BlockD[i].y = 369.0f + i * OneStep;
			if (i >= 8 && i < 19)
				BlockD[i].x = 885.0f, BlockD[i].y = 391.0f + (i - 8) * OneStep;
			if (i >= 19 && i < 27)
				BlockD[i].x = 929.0f, BlockD[i].y = 479.0f + (i - 19) * OneStep;
			if (i >= 27 && i < 34)
				BlockD[i].x = 973.0f, BlockD[i].y = 479.0f + (i - 27) * OneStep;
			if (i >= 34 && i < 39)
				BlockD[i].x = 841.0f, BlockD[i].y = 303.0f + (i - 34) * OneStep;
			if (i >= 39 && i < 44)
				BlockD[i].x = 885.0f, BlockD[i].y = 259.0f + (i - 39) * OneStep;
			if (i >= 44 && i < 47)
				BlockD[i].x = 841.0f, BlockD[i].y = 435.0f + (i - 44) * OneStep;
			if (i >= 47 && i < 50)
				BlockD[i].x = 973.0f, BlockD[i].y = 303.0f + (i - 47) * OneStep;
			if (i >= 50 && i < 53)
				BlockD[i].x = 797.0f, BlockD[i].y = 567.0f + (i - 50) * OneStep;

			//when y is constant
			if (i >= 53 && i < 55)
				BlockD[i].x = 929.0f + (i - 53)* OneStep, BlockD[i].y = 303.0f;
			if (i >= 55 && i < 58)
				BlockD[i].x = 907.0f + (i - 55)* OneStep, BlockD[i].y = 347.0f;
			if (i >= 58 && i < 62)
				BlockD[i].x = 929.0f + (i - 58)* OneStep, BlockD[i].y = 391.0f;
			if (i >= 62 && i < 66)
				BlockD[i].x = 907.0f + (i - 62)* OneStep, BlockD[i].y = 435.0f;
			if (i >= 66 && i < 68)
				BlockD[i].x = 819.0f + (i - 66)* OneStep, BlockD[i].y = 523.0f;
			if (i >= 68 && i < 70)
				BlockD[i].x = 819.0f + (i - 68)* OneStep, BlockD[i].y = 567.0f;
			if (i >= 70 && i < 72)
				BlockD[i].x = 841.0f + (i - 70)* OneStep, BlockD[i].y = 611.0f;
			BlockD[72].x = 863.0f, BlockD[72].y = 259.0f;
			BlockD[73].x = 863.0f, BlockD[73].y = 479.0f;
			BlockD[74].x = 863.0f, BlockD[74].y = 391.0f;
			BlockD[75].x = 819.0f, BlockD[75].y = 391.0f;
			BlockD[76].x = 951.0f, BlockD[76].y = 479.0f;

		}
		for (int j = 0; j < 77; j++)
			if (BlockD[j] == Player.getPosition())
			{
				return true;
			}
		//delete[]BlockD;
	}


	return false;
}
bool FindTheWay::check_Window_BoundaryCollision()const
{
	if (Player.character.getPosition().x >= 0 &&
		Player.character.getPosition().x <= window->getSize().x
		&& Player.character.getPosition().y >= 0 && Player.character.getPosition().y <= OneStep)
		return true;

	else if (Player.character.getPosition().x >= 0 &&
		Player.character.getPosition().x <= window->getSize().x
		&& Player.character.getPosition().y >= window->getSize().y - OneStep
		&& Player.character.getPosition().y <= window->getSize().y)
		return true;

	else if (Player.character.getPosition().x >= 0
		&& Player.character.getPosition().x <= OneStep
		&& Player.character.getPosition().y >= 0
		&& Player.character.getPosition().y <= window->getSize().y)
		return true;

	else if (Player.character.getPosition().x >= (window->getSize().x - OneStep)
		&& Player.character.getPosition().x <= window->getSize().x
		&& Player.character.getPosition().y >= 0
		&& Player.character.getPosition().y <= window->getSize().y)
		return true;

	return false;
}
void FindTheWay::KeptInWindow()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		Player.character.move(0, OneStep);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		Player.character.move(0, -OneStep);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		Player.character.move(-OneStep, 0);
	else
		Player.character.move(OneStep, 0);

}
void FindTheWay::ShowInstructions()
{
	sf::RenderWindow window1(sf::VideoMode(600, 600), "SFML window", sf::Style::None);
	sf::Clock clock;
	sf::Texture background;
	if (!background.loadFromFile("images/backgroundGame.png"))
		EXIT_FAILURE;
	sf::Sprite Background(background);
	while (!(clock.getElapsedTime().asSeconds() > 10)) {
		window1.clear();

		sf::Text text("How To Play", font1, 34);
		sf::Text instructions0("You Have to find your way through ", font1, 26);
		sf::Text instructions1("MAZE so as to find the clue your ", font1, 26);
		sf::Text instructions2("grandfather left", font1, 26);
		sf::Text instructions3("Use arrow keys to navigate", font1, 28);
		sf::Text instructions4("  REMEMBER YOU HAVE LIMITED TIME!", font2, 34);

		instructions0.setPosition(15, 100);
		instructions1.setPosition(15, 170);
		instructions2.setPosition(15, 230);
		instructions3.setPosition(15, 300);
		instructions4.setPosition(15, 370);

		text.setPosition(180, 20);
		window1.draw(Background);
		window1.draw(text);
		window1.draw(instructions0);
		window1.draw(instructions1);
		window1.draw(instructions2);
		window1.draw(instructions3);
		window1.draw(instructions4);
		window1.display();
	}
	window1.close();
}
bool FindTheWay::Check_BoundaryCollision()const
{
	if (Player.character.getPosition().x >= 225.0f
		&& Player.character.getPosition().x <= 841.0f
		&& Player.character.getPosition().y == 83.0f)
		return true;

	else if (Player.character.getPosition().x == 225.0f
		&& Player.character.getPosition().y >= 105.0f
		&& Player.character.getPosition().y <= 523.0f)
		return true;

	else if (Player.character.getPosition().x == 841.0f
		&& Player.character.getPosition().y >= 105.0f
		&& Player.character.getPosition().y <= 259.0f)
		return true;

	else if (Player.character.getPosition().x >= 357.0f
		&& Player.character.getPosition().x <= 1017.0f
		&& Player.character.getPosition().y == 655.0f)
		return true;

	else if (Player.character.getPosition().x == 357.0f
		&& Player.character.getPosition().y >= 523.0f
		&& Player.character.getPosition().y <= 633.0f)
		return true;

	else if (Player.character.getPosition().x >= 929.0f
		&& Player.character.getPosition().x <= 995.0f
		&& Player.character.getPosition().y == 259.0f)
		return true;

	else if (Player.character.getPosition().x >= 269.0f
		&& Player.character.getPosition().x <= 335.0f
		&& Player.character.getPosition().y == 523.0f)
		return true;

	else if (Player.character.getPosition().x == 1017.0f
		&& Player.character.getPosition().y >= 259.0f
		&& Player.character.getPosition().y <= 633.0f)
		return true;


	return false;
}
void FindTheWay::Show_Elapsed_time()
{
	show_time.setString("TIME ELAPSED : " + to_string(clock.getElapsedTime().asSeconds()).substr(0, 4) + " seconds ");
	show_time.setCharacterSize(24);
	show_time.setFillColor(sf::Color::Black);
	show_time.setPosition(480, 30);

}