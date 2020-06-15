#pragma once
#include <SFML/Graphics.hpp>

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
	void draw(sf::RenderWindow &window);
	void guideWindowFunc(sf::RenderWindow &window, Guide *guide);
};