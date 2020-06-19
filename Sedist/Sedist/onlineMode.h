#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

enum ServerClient {
	NOT_PRESSED,
	SERVER,
	CLIENT
};

enum Status
{
	NOT_RUNNING,
	SERVER_RUNNING,
	CLIENT_RUNNING,
};

class modeScreen
{
	int selectedItemIndex;
	sf::Font font;
	sf::Text modeText[3];
public:
	modeScreen(float width, float height);
	~modeScreen();
	void draw(sf::RenderWindow & window);
	void MoveRight();
	bool isClosed = false;
	Status status = NOT_RUNNING;
	void MoveLeft();
	int GetPressedItem() { return selectedItemIndex; }
	ServerClient choosed = NOT_PRESSED;
	void onlineModeWindowFunc(sf::RenderWindow &window, modeScreen *modeScreen, char *type);
};