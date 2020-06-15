#include "gameOver.h"

GameOver::GameOver(float width, float height)
{
	if (!font.loadFromFile("04B_30__.ttf"))
	{
		// handle error
	}

	resultText[0].setFont(font);
	resultText[0].setFillColor(sf::Color::White);
	resultText[0].setString("GAME OVER!");
	resultText[0].setPosition(sf::Vector2f(width / 2 - 120, height / 4));

	resultText[1].setFont(font);
	resultText[1].setFillColor(sf::Color::White);
	resultText[1].setString("Try again?");
	resultText[1].setPosition(sf::Vector2f(width / 2 - 110, height / 3));

	resultText[2].setFont(font);
	resultText[2].setFillColor(sf::Color::Red);
	resultText[2].setString("Yes");
	resultText[2].setPosition(sf::Vector2f(width / 2.15, height / 2));

	resultText[3].setFont(font);
	resultText[3].setFillColor(sf::Color::White);
	resultText[3].setString("No");
	resultText[3].setPosition(sf::Vector2f(width / 2.1, height / 2 + 50));

	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);

	selectedItemIndex = 2;
}


GameOver::~GameOver()
{
}

void GameOver::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(resultText[i]);
	}
}

void GameOver::MoveUp()
{
	if (selectedItemIndex - 1 >= 2)
	{
		resultText[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		resultText[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void GameOver::MoveDown()
{
	if (selectedItemIndex + 1 < 4)
	{
		resultText[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		resultText[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void GameOver::gameOverFunc(sf::RenderWindow &resultWindow, GameOver *gameOver, bool *isReplay, int score)
{
	sf::Event event;
	bestScore = score;
	while (resultWindow.pollEvent(event))
	{
		//if (e.type == Event::Resized)
		//{
		//	// update the view to the new size of the window
		//	FloatRect visibleArea(0, 0, e.size.width, e.size.height);
		//	gameWindow.setView(View(visibleArea));
		//}
		if (event.type == sf::Event::Closed)
			resultWindow.close();
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				gameOver->MoveUp();
				break;

			case sf::Keyboard::Down:
				gameOver->MoveDown();
				break;

			case sf::Keyboard::Return:
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