//ј “”јЋ№Ќџ≈ ¬ќѕ–ќ—џ: изменить текстурку змейки, font, добавить разные фрукты и меню
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include "menu.h"

using namespace sf;

int N = 30;
int M = 20;
int size = 16;
int w = size * N;
int h = size * M;
int dir;
int num = 2;
int score = 0;
float timer = 0;
float delay = 0.1;

struct Snake
{
	int x,y;
} s[100];
struct Fruct
{
	int x, y;
}f;
enum Fruits
{
	STANDART,
	SPEED
} fruitType;

void Tick()
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
			num++;
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
	if (s[0].x > N-1)
		s[0].x = 0;
	if (s[0].x < 0)
		s[0].x = N-1;
	
	if (s[0].y > M-1)
		s[0].y = 2;
	if (s[0].y < 2)
		s[0].y = M-1;

	//поедание хвоста
	for (int i = 1; i < num; i++)
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y) {
			score -= num - i;
			num = i;
		}
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	
	RenderWindow menuWindow(VideoMode(w, h), "Snake++");
	Menu menu(menuWindow.getSize().x, menuWindow.getSize().y);

	Texture t1, t2, t3, t4, t5, t6;
	t1.loadFromFile("img/greenBack.png");
	t2.loadFromFile("img/snakeAlt.png");
	t3.loadFromFile("img/newApple.png");
	t4.loadFromFile("img/snakeAltHead.png");
	t5.loadFromFile("img/grinBack.png");
	t6.loadFromFile("img/speedApple.png");
	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	Sprite sprite4(t4);
	Sprite sprite5(t5);
	Sprite sprite6(t6);
	Clock clock;
	
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

	if (menu.pressedButton == PLAY) {
		RenderWindow gameWindow(VideoMode(menuWindow.getSize().x, menuWindow.getSize().y), "Snake++");
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

			if (dir != 2)
			{
				if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
					dir = 1;
			}
			if (dir != 1)
			{
				if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
					dir = 2;
			}
			if (dir != 0) {
				if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
					dir = 3;
			}
			if (dir != 3)
			{
				if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
					dir = 0;
			}

			if (timer > delay)
			{
				timer = 0;
				Tick();
			}

			////// draw //////
			gameWindow.clear();

			for (int i = 0; i < N; i++) {
				for (int j = 2; j < M; j++)
				{
					if (i % 2 != 0 || j % 2 != 0) {
						if (i % 2 != 0 && j % 2 != 0) {
							sprite5.setPosition(i*size, j*size);
							gameWindow.draw(sprite5);
						}
						else {
							sprite1.setPosition(i*size, j*size);
							gameWindow.draw(sprite1);
						}
					}
					else {
						sprite5.setPosition(i*size, j*size);
						gameWindow.draw(sprite5);
					}
				}
			}
			for (int i = 0; i < num; i++)
			{
				if (i < 1) {
					sprite4.setPosition(s[i].x*size, s[i].y*size);
					gameWindow.draw(sprite4);
				}
				else {
					sprite2.setPosition(s[i].x*size, s[i].y*size);
					gameWindow.draw(sprite2);
				}
			}

			if (fruitType == STANDART)
			{
				sprite3.setPosition(f.x*size, f.y*size);
				gameWindow.draw(sprite3);

			}
			else
			{
				sprite6.setPosition(f.x*size, f.y*size);
				gameWindow.draw(sprite6);

			}
			std::ostringstream scoreString;
			scoreString << score;
			text.setString("Score:" + scoreString.str());
			text.setPosition(1, 1);
			gameWindow.draw(text);
			gameWindow.display();
		}
	}
	return 0;
}