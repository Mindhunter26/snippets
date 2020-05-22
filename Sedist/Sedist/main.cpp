//ј “”јЋ№Ќџ≈ ¬ќѕ–ќ—џ: изменить текстурку змейки, font, добавить разные фрукты и меню
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <sstream>
#include "menu.h"
#include "gameOver.h"
#include "helper.h"
#include "MenuWindow.h"
#include "PlayWindow.h"
#include "GameOverWindow.h"

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

	//sf::IpAddress ip = sf::IpAddress::getLocalAddress(); //192.168.0.103 - local
	//sf::TcpSocket socket;
	//char connectionType;

	//std::cout << "(s) for server, (c) for client: ";
	//std::cin >> connectionType;

	//if (connectionType == 's')
	//{
	//	sf::TcpListener listener;
	//	listener.listen(2000);
	//	listener.accept(socket);
	//}
	//else
	//	socket.connect(ip, 2000);

	//Vector2f prevPos, p2Pos;

	//socket.setBlocking(false);	
	//
	//bool update = false;
	//////////////////////////////////////////////////    MENU    ///////////////////////////////////////////////////////////////////////////////
	RenderWindow menuWindow(VideoMode(w, h), "Snake++");
	Menu menu(menuWindow.getSize().x, menuWindow.getSize().y);
	
	while (menuWindow.isOpen()) menuWindowFunc(menuWindow, &menu);
		
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
					/*else if (e.type == Event::GainedFocus)
						update = true;
					else if (e.type == Event::LostFocus)
						update = false;*/
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
					logic(&num, dir, s, &f, &fruitType, &delay, &score, N, M, &isTailHit);
				}

				////// draw //////
				gameWindow.clear();
				playWindowFunc(gameWindow, isTailHit, N, M, score, size, num, &text, f, fruitType, s, &appleSprite, &speedAppleSprite, &bgDarkSprite, &bgLightSprite, &snakeHeadSprite, &snakeBodySprite);
			}

			/////////////////////////////////     GAME OVER      ////////////////////////////////////////////////////////////
			if (isTailHit) {
				RenderWindow resultWindow(VideoMode(w, h), "Snake++");
				GameOver gameOver(gameWindow.getSize().x, gameWindow.getSize().y);
				
				while (resultWindow.isOpen()) {
					gameOverFunc(resultWindow, &gameOver, &isReplay, score);
					if (isReplay == true) break;
				}
			}
		}
		if (isReplay == false)
			break;
	}
	return 0;
}