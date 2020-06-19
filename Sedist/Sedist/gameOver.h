#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

enum TryAgain {
	NOT,
	YES,
	NO,
	OK
};

class GameOver
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text resultText[4];
	int bestScore;
public:
	GameOver(float width, float height);
	~GameOver();
	sf::Text scoreText;
	sf::Text enemyScoreText;
	sf::Text statusText;
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void gameOverFunc(sf::RenderWindow &resultWindow, GameOver *gameOver, bool *isReplay, bool isTailHit, int score, int clientScore, Menu *menu);
	TryAgain choice = NOT;
};