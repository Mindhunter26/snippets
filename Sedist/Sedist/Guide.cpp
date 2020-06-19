#include "Guide.h"

Guide::Guide(float width, float height) 
{
	if (!image.loadFromFile("img/GuideScreen.png"))
	{
	}
	
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

Guide::~Guide()
{
}

void Guide::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Guide::guideWindowFunc(sf::RenderWindow &window, Guide *guide) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			isClosed = true;
			window.close();
		}
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Enter:
				isEnterPressed = true;
				
				window.close();
				break;
			}
			break;
		}
	}
	window.clear();

	guide->draw(window);
	window.display();
}
