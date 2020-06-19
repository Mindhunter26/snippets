#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("04B_30__.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2 - 50, height - 550));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Play online");
	menu[1].setPosition(sf::Vector2f(width / 2 - 110, height - 450));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Guide");
	menu[2].setPosition(sf::Vector2f(width / 2 - 50, height - 350));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 2 - 50, height - 250));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 4)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::menuWindowFunc(sf::RenderWindow &menuWindow, Menu *menu) {
	sf::Event event;
	while (menuWindow.pollEvent(event))
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
			case sf::Keyboard::Up:
				menu->MoveUp();
				break;

			case sf::Keyboard::Down:
				menu->MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (menu->GetPressedItem())
				{
				case 0:
					std::cout << "Play button has been pressed" << std::endl;
					menu->pressedButton = PLAY;
					menu->isVisible = false;
					menuWindow.setVisible(false);
					break;
				case 1:
					std::cout << "Play online button has been pressed" << std::endl;
					menu->pressedButton = PLAY_ONLINE;
					menuWindow.close();
					break;
				case 2:
					std::cout << "Guide button has been pressed" << std::endl;
					menu->pressedButton = GUIDE;
					menu->isVisible = false;
					menuWindow.setVisible(false);
					break;
				case 3:
					std::cout << "Exit button has been pressed" << std::endl;
					menu->pressedButton = EXIT;
					menuWindow.close();
					break;
				}
				break;
			}

			break;
		case sf::Event::Closed:
			menuWindow.close();
			break;
		}
	}
	menuWindow.clear();
	menu->draw(menuWindow);
	menuWindow.display();
}