//ј “”јЋ№Ќџ≈ ¬ќѕ–ќ—џ: изменить текстурку змейки, font, добавить разные фрукты и меню
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include "menu.h"
#include "gameOver.h"
#include "helper.h"

using namespace sf;

int N = 45;
int M = 30;
int size = 24;
int w = size * N;
int h = size * M;
int dir;
int num = 2;
int score = 0;
float timer = 0;
float delay = 0.1;
bool isTailHit = false;
bool isReplay = false;

Snake s[300];
Fruct f;
Fruits fruitType;

void logic()
{
	for (int i = num; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;

	}

	if (dir == 0)
		s[0].y += 1;
	if (dir == 1)
		s[0].x -= 1;
	if (dir == 2)
		s[0].x += 1;
	if (dir == 3)
		s[0].y -= 1;

	if (((s[0].x == f.x) && (s[0].y == f.y)) || ((s[1].x == f.x) && (s[1].y == f.y)))
	{
		if (fruitType == SPEED)
		{
			delay = 0.05;
			score++;
		}
		if (fruitType == STANDART)
		{
			delay = 0.1;
		}
		num++;
		score++;
		fruitType = static_cast<Fruits>(rand() % 2);
		f.x = 2 + rand() % (N - 2);
		f.y = 2 + rand() % (M - 2);
		for (int i = 0; i < num; i++) {
			if (f.x == s[i].x & f.y == s[i].y) {
				f.x = 2 + rand() % (N - 2);
				f.y = 2 + rand() % (M - 2);
			}
		}
	}
	//выход за пределы
	if (s[0].x > N - 1)
		s[0].x = 0;
	if (s[0].x < 0)
		s[0].x = N - 1;

	if (s[0].y > M - 1)
		s[0].y = 2;
	if (s[0].y < 2)
		s[0].y = M - 1;

	//поедание хвоста
	for (int i = 1; i < num; i++)
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y) {
			isTailHit = true;
		}
	}	
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	
	Texture bgLight, snakeBody, apple, snakeHead, bgDark, speedApple;
	bgLight.loadFromFile("img/greenBack.png");
	snakeBody.loadFromFile("img/snakeAlt.png");
	apple.loadFromFile("img/newApple.png");
	snakeHead.loadFromFile("img/snakeAltHead.png");
	bgDark.loadFromFile("img/grinBack.png");
	speedApple.loadFromFile("img/speedApple.png");
	Sprite bgLightSprite(bgLight);
	Sprite snakeBodySprite(snakeBody);
	Sprite appleSprite(apple);
	Sprite snakeHeadSprite(snakeHead);
	Sprite bgDarkSprite(bgDark);
	Sprite speedAppleSprite(speedApple);
	Clock clock;
	//////////////////////////////////////////////////    MENU    ///////////////////////////////////////////////////////////////////////////////
	RenderWindow menuWindow(VideoMode(w, h), "Snake++");
	Menu menu(menuWindow.getSize().x, menuWindow.getSize().y);
	while (menuWindow.isOpen())
	{
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
					menu.MoveUp();
					break;

				case Keyboard::Down:
					menu.MoveDown();
					break;

				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						menu.pressedButton = PLAY;
						menuWindow.close();
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						menu.pressedButton = OPTIONS;
						menuWindow.close();
						break;
					case 2:
						menu.pressedButton = EXIT;
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
		menu.draw(menuWindow);
		menuWindow.display();
	}
	////////////////////////////////////////////   PLAY   ////////////////////////////////////////////////////////////////////////////
	while (1) {
		
		if (menu.pressedButton == PLAY) {
			RenderWindow gameWindow(VideoMode(menuWindow.getSize().x, menuWindow.getSize().y), "Snake++");
			isTailHit = false;
			isReplay = false;
			score = 0;
			num = 2;
			f.x = 2 + rand() % (N - 2);
			f.y = 2 + rand() % (M - 2);
			
			Font font;
			font.loadFromFile("04B_30__.ttf");
			Text text("", font, 14);
			//text.setColor(Color::Red);
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
					if (e.type == Event::Closed)
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
				if (dir != 0 && !Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::S)) {
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
					logic();
				}

				////// draw //////
				gameWindow.clear();

				for (int i = 0; i < N; i++) {
					for (int j = 2; j < M; j++)
					{
						if (i % 2 != 0 || j % 2 != 0) {
							if (i % 2 != 0 && j % 2 != 0) {
								bgDarkSprite.setPosition(i*size, j*size);
								gameWindow.draw(bgDarkSprite);
							}
							else {
								bgLightSprite.setPosition(i*size, j*size);
								gameWindow.draw(bgLightSprite);
							}
						}
						else {
							bgDarkSprite.setPosition(i*size, j*size);
							gameWindow.draw(bgDarkSprite);
						}
					}
				}
				for (int i = 0; i < num; i++)
				{
					if (i < 1) {
						snakeHeadSprite.setPosition(s[i].x*size, s[i].y*size);
						gameWindow.draw(snakeHeadSprite);
					}
					else {
						snakeBodySprite.setPosition(s[i].x*size, s[i].y*size);
						gameWindow.draw(snakeBodySprite);
					}
				}

				if (fruitType == STANDART)
				{
					appleSprite.setPosition(f.x*size, f.y*size);
					gameWindow.draw(appleSprite);

				}
				else
				{
					speedAppleSprite.setPosition(f.x*size, f.y*size);
					gameWindow.draw(speedAppleSprite);

				}
				std::ostringstream scoreString;
				scoreString << score;
				text.setString("Score:" + scoreString.str());
				text.setPosition(1, 1);
				gameWindow.draw(text);
				gameWindow.display();
				if (isTailHit) gameWindow.close();
			}

			/////////////////////////////////     GAME OVER      ////////////////////////////////////////////////////////////
			if (isTailHit) {
				RenderWindow resultWindow(VideoMode(w, h), "Snake++");
				GameOver gameOver(gameWindow.getSize().x, gameWindow.getSize().y);
				
				while (resultWindow.isOpen()) {
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
								gameOver.MoveUp();
								break;

							case Keyboard::Down:
								gameOver.MoveDown();
								break;

							case Keyboard::Return:
								switch (gameOver.GetPressedItem())
								{
								case 2:
									gameOver.choice = YES;
									isReplay = true;
									//std::cout << "yea";
									//resultWindow.close();
									break;
								case 3:
									gameOver.choice = NO;
									isReplay = false;
									resultWindow.close();
									break;
								}
								break;
							}
							break;
						}
					}
					resultWindow.clear();
					std::ostringstream scorString;
					scorString << score;
					gameOver.scoreText.setString("YOUR SCORE: " + scorString.str());
					gameOver.scoreText.setPosition(375, 100);
					resultWindow.draw(gameOver.scoreText);
					gameOver.draw(resultWindow);
					resultWindow.display();
					if (isReplay == true) break;
				}
			}
		}
		if (isReplay == false)
			break;
	}
	return 0;
}