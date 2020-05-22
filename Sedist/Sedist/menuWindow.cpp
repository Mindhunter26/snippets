#include "MenuWindow.h"

void menuWindowFunc(RenderWindow &menuWindow, Menu *menu) {
	Event event;
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
		case Event::KeyReleased:
			switch (event.key.code)
			{
			case Keyboard::Up:
				menu->MoveUp();
				break;

			case Keyboard::Down:
				menu->MoveDown();
				break;

			case Keyboard::Return:
				switch (menu->GetPressedItem())
				{
				case 0:
					std::cout << "Play button has been pressed" << std::endl;
					menu->pressedButton = PLAY;
					menuWindow.close();
					break;
				case 1:
					std::cout << "Option button has been pressed" << std::endl;
					menu->pressedButton = OPTIONS;
					menuWindow.close();
					break;
				case 2:
					menu->pressedButton = EXIT;
					menuWindow.close();
					break;
				}

				break;
			}

			break;
		case Event::Closed:
			menuWindow.close();
			break;
		}
	}
	menuWindow.clear();
	menu->draw(menuWindow);
	menuWindow.display();
}