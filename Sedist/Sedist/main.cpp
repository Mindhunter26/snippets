//ј “”јЋ№Ќџ≈ ¬ќѕ–ќ—џ: изменить текстурку змейки, font, добавить разные фрукты и меню
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <sstream>
#include "menu.h"
#include "gameOver.h"
#include "helper.h"
#include "PlayWindow.h"
#include "Guide.h"

using namespace sf;

int main()
{	
	srand(time(0));
	setlocale(LC_ALL, "ru");

	int N = 45;
	int M = 30;
	int size = 24;
	int w = size * N;
	int h = size * M;
	int dir = 0;
	int num = 2;
	int score = 0;
	float timer = 0;
	float delay = 0.1;
	bool isTailHit = false;
	bool isReplay = false;
	
	Snake s[300];
	Fruct f;
	Fruits fruitType;

	Texture bgLight, snakeBody, apple, snakeHead, bgDark, speedApple, rotApple;
	bgLight.loadFromFile("img/greenBack.png");
	snakeBody.loadFromFile("img/snakeAlt.png");
	apple.loadFromFile("img/newApple.png");
	snakeHead.loadFromFile("img/snakeAltHead.png");
	bgDark.loadFromFile("img/grinBack.png");
	speedApple.loadFromFile("img/speedApple.png");
	rotApple.loadFromFile("img/rotApple.png"); 
	
	Sprite bgLightSprite(bgLight);
	Sprite snakeBodySprite(snakeBody);
	Sprite appleSprite(apple);
	Sprite snakeHeadSprite(snakeHead);
	Sprite bgDarkSprite(bgDark);
	Sprite speedAppleSprite(speedApple);
	Sprite rotAppleSprite(rotApple);

	Clock clock;

	bool update = false;

	//////////////////////////////////////////////////    MENU    ///////////////////////////////////////////////////////////////////////////////
	RenderWindow menuWindow(VideoMode(w, h), "Snake++", Style::Close);
	Menu menu(menuWindow.getSize().x, menuWindow.getSize().y);
	
	while (menuWindow.isOpen()) menu.menuWindowFunc(menuWindow, &menu);

		
	if (menu.pressedButton == GUIDE)
	{
		RenderWindow guideWindow(VideoMode(menuWindow.getSize().x, menuWindow.getSize().y), "Snake++", Style::Close);
		Guide guide(menuWindow.getSize().x, menuWindow.getSize().y);
		while (guideWindow.isOpen()) guide.guideWindowFunc(guideWindow, &guide);
		if (guide.isEnterPressed) menu.pressedButton = PLAY;
	}
	////////////////////////////////////////////   PLAY   ////////////////////////////////////////////////////////////////////////////

	while (1) 
	{
		if (menu.pressedButton == PLAY_ONLINE)
		{
			RenderWindow gameWindow(VideoMode(menuWindow.getSize().x, menuWindow.getSize().y), "Snake++", Style::Close);
			
		}

		if (menu.pressedButton == PLAY) 
		{
			RenderWindow gameWindow(VideoMode(menuWindow.getSize().x, menuWindow.getSize().y), "Snake++", Style::Close);
			isTailHit = false;
			isReplay = false;
			score = 0;
			num = 2;
			delay = 0.1;
			f.x = 2 + rand() % (N - 2);
			f.y = 2 + rand() % (M - 2);
			
			Font font;
			font.loadFromFile("04B_30__.ttf");
			Text text("", font, 20);
			text.setStyle(Text::Regular);
			f.x = 10;
			f.y = 10;
			fruitType = static_cast<Fruits>(rand() % 2);
			std::cout << fruitType;
			
			while (gameWindow.isOpen())
			{
				float time = clock.getElapsedTime().asSeconds();
				clock.restart();
				timer += time;
				Event e;

				while (gameWindow.pollEvent(e))
				{
					//if (e.type == Event::Resized)
					//{
					//	// update the view to the new size of the window
					//	FloatRect visibleArea(0, 0, e.size.width, e.size.height);
					//	gameWindow.setView(View(visibleArea));
					//}
					if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
						gameWindow.close();
				}

				if (dir != 2 && !Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::S))
				{
					if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
						dir = 1;
				}
				if (dir != 1 && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::S))
				{
					if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
						dir = 2;
				}
				if (dir != 0 && !Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::S)) 
				{
					if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
						dir = 3;
				}
				if (dir != 3 && !Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::A))
				{
					if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
						dir = 0;
				}

				if (timer > delay)
				{
					timer = 0;
					logic(&num, dir, s, &f, &fruitType, &delay, &score, N, M, &isTailHit);
					if (num < 1) 
					{ 
						isTailHit = true;
						gameWindow.close(); 
					}
				}

				////// draw //////
				gameWindow.clear();
				playWindowFunc(gameWindow, isTailHit, N, M, score, size, num, &text, f, fruitType, s, &appleSprite, &speedAppleSprite, &bgDarkSprite, &bgLightSprite, &snakeHeadSprite, &snakeBodySprite, &rotAppleSprite);
			}

			/////////////////////////////////     GAME OVER      ////////////////////////////////////////////////////////////
			if (isTailHit) {
				RenderWindow resultWindow(VideoMode(w, h), "Snake++", Style::Close);
				GameOver gameOver(gameWindow.getSize().x, gameWindow.getSize().y);
				
				while (resultWindow.isOpen()) {
					gameOver.gameOverFunc(resultWindow, &gameOver, &isReplay, score);
					if (isReplay == true) break;
				}
			}
		}
		if (isReplay == false)
			break;
	}
	return 0;
}