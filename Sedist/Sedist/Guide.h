#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
class Guide
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Guide(float width, float height);
	~Guide();
	bool isEnterPressed = false;
	bool isClosed = false;
	void draw(sf::RenderWindow &window);
	void guideWindowFunc(sf::RenderWindow &window, Guide *guide);
};