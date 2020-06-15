#include "Guide.h"

Guide::Guide(float width, float height) 
{
	if (!image.loadFromFile("img/GuideScreen.png"))
	{
		//error
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
		//if (e.type == Event::Resized)
		//{
		//	// update the view to the new size of the window
		//	FloatRect visibleArea(0, 0, e.size.width, e.size.height);
		//	gameWindow.setView(View(visibleArea));
		//}
		if (event.type == sf::Event::Closed)
			window.close();
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
