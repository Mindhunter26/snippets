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
	resultText[0].setPosition(sf::Vector2f(width / 2, height / 5));

	resultText[1].setFont(font);
	resultText[1].setFillColor(sf::Color::White);
	resultText[1].setString("Try again?");
	resultText[1].setPosition(sf::Vector2f(width / 2, height / 4));

	resultText[2].setFont(font);
	resultText[2].setFillColor(sf::Color::Red);
	resultText[2].setString("Yes");
	resultText[2].setPosition(sf::Vector2f(width / 2, height / 3));

	resultText[3].setFont(font);
	resultText[3].setFillColor(sf::Color::White);
	resultText[3].setString("No");
	resultText[3].setPosition(sf::Vector2f(width / 2, height / 2));

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