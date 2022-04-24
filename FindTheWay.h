#pragma once
# include<iostream>
#include"Character.h"
#include"Game.h"
# include<string>
using namespace std;

class FindTheWay : public Game
{
private:
	float OneStep;
	sf::Text show_time;
	Character Player;
	sf::Vector2f FinishPoint;
	sf::Texture MazeP, DoorP, BackgroundP;
	sf::Sprite Maze, Door, Background;
	sf::Clock clock;
	sf::RenderWindow *window;
private:
	void Door_Setting();
	void DrawLevel();
	bool CheckCollision();
	bool Check_BoundaryCollision()const;
	bool check_Window_BoundaryCollision()const;
	void KeptInWindow();
	void Show_Elapsed_time();
public:
	FindTheWay(sf::RenderWindow & window);
	void ShowInstructions();
	bool Play();
};