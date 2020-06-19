#include "onlineMode.h"


modeScreen::modeScreen(float width, float height)
{
	if (!font.loadFromFile("04B_30__.ttf"))
	{
		// handle error
	}

	modeText[0].setFont(font);
	modeText[0].setFillColor(sf::Color::White);
	modeText[0].setString("Choose mode");
	modeText[0].setPosition(sf::Vector2f(width / 2 - 150, height - 550));

	modeText[1].setFont(font);
	modeText[1].setFillColor(sf::Color::Red);
	modeText[1].setString("Server");
	modeText[1].setPosition(sf::Vector2f(width / 4, height - 450));

	modeText[2].setFont(font);
	modeText[2].setFillColor(sf::Color::Yellow);
	modeText[2].setFillColor(sf::Color::White);
	modeText[2].setString("Client");
	modeText[2].setPosition(sf::Vector2f(width / 1.65, height - 450));

	selectedItemIndex = 1;
}


modeScreen::~modeScreen()
{
}

void modeScreen::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(modeText[i]);
	}
}

void modeScreen::MoveRight()
{
	
		if (selectedItemIndex - 1 >= 1)
		{
			modeText[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			modeText[selectedItemIndex].setFillColor(sf::Color::Red);
		}
	
}

void modeScreen::MoveLeft()
{
	
		if (selectedItemIndex + 1 < 3)
		{
			modeText[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			modeText[selectedItemIndex].setFillColor(sf::Color::Red);
		}
	
}

void modeScreen::onlineModeWindowFunc(sf::RenderWindow &window, modeScreen *modeScreen, char *type)
{
	
	sf::Event event;
	
	while (window.pollEvent(event))
	{
		//if (event.type == Event::Resized)
		//	{
		//		// update the view to the new size of the window
		//		FloatRect visibleArea(0, 0, event.size.width, event.size.height);
		//		menuWindow.setView(View(visibleArea));
		//	}

		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
					modeScreen->MoveRight();
				break;

			case sf::Keyboard::Right:
					modeScreen->MoveLeft();
				break;

			case sf::Keyboard::Return:
				switch (modeScreen->GetPressedItem())
				{
				case 1:
					std::cout << "Server running" << std::endl;
					modeScreen->choosed = SERVER;
					*type = 's';
					status = SERVER_RUNNING;
					window.close();
					break;
				case 2:
					std::cout << "Client connected" << std::endl;
					modeScreen->choosed = CLIENT;
					*type = 'c';
					status = CLIENT_RUNNING;
					window.close();				
					break;
				}
				modeText[0].setFillColor(sf::Color::Transparent);
				modeText[1].setFillColor(sf::Color::Transparent);
				modeText[2].setFillColor(sf::Color::Transparent);
				if (status == SERVER_RUNNING)
				{
					modeText[3].setFillColor(sf::Color::White);
				}
				else if (status == CLIENT_RUNNING)
				{
					modeText[4].setFillColor(sf::Color::White);
				}
				break;
			}

			break;
		case sf::Event::Closed:
			isClosed = true;
			window.close();
			break;
		}
	}
	window.clear();
	modeScreen->draw(window);
	window.display();
}