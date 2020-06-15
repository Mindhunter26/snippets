#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


enum buttonPressed {
	NOTPRESSED,
	PLAY,
	PLAY_ONLINE,
	GUIDE,
	EXIT
};

class Menu
{
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[4];
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow & window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	buttonPressed pressedButton = NOTPRESSED;
	void menuWindowFunc(sf::RenderWindow &window, Menu *menu);
};