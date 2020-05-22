#include "GameOverWindow.h"

void gameOverFunc(RenderWindow &resultWindow, GameOver *gameOver, bool *isReplay, int score)
{
	Event event;
	while (resultWindow.pollEvent(event))
	{
		//if (e.type == Event::Resized)
		//{
		//	// update the view to the new size of the window
		//	FloatRect visibleArea(0, 0, e.size.width, e.size.height);
		//	gameWindow.setView(View(visibleArea));
		//}
		if (event.type == Event::Closed)
			resultWindow.close();
		switch (event.type)
		{
		case Event::KeyReleased:
			switch (event.key.code)
			{
			case Keyboard::Up:
				gameOver->MoveUp();
				break;

			case Keyboard::Down:
				gameOver->MoveDown();
				break;

			case Keyboard::Return:
				switch (gameOver->GetPressedItem())
				{
				case 2:
					gameOver->choice = YES;
					*isReplay = true;
					//std::cout << "yea";
					//resultWindow.close();
					break;
				case 3:
					gameOver->choice = NO;
					*isReplay = false;
					resultWindow.close();
					break;
				}
				break;
			}
			break;
		}
	}
	resultWindow.clear();
	gameOver->scoreText.setString("YOUR SCORE: " + std::to_string(score));
	gameOver->scoreText.setPosition(375, 100);
	resultWindow.draw(gameOver->scoreText);
	gameOver->draw(resultWindow);
	resultWindow.display();
}