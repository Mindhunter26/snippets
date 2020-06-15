#pragma once
#include <SFML/Graphics.hpp>

enum TryAgain {
	NOT,
	YES,
	NO
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
	sf::Text bestScoreText;
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void gameOverFunc(sf::RenderWindow &resultWindow, GameOver *gameOver, bool *isReplay, int score);
	TryAgain choice = NOT;
};