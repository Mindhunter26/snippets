#pragma once
#include "SFML/Graphics.hpp"

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
	
public:
	GameOver(float width, float height);
	~GameOver();
	sf::Text scoreText;
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	TryAgain choice = NOT;
};