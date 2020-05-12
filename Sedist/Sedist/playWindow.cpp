//#include "playWindow.h"
//
//using namespace sf;
//
//RenderWindow gameWindow(VideoMode(menuWindow.getSize().x, menuWindow.getSize().y), "Snake++");
//isTailHit = false;
//isReplay = false;
//score = 0;
//num = 2;
//f.x = 2 + rand() % (N - 2);
//f.y = 2 + rand() % (M - 2);
//
//Font font;
//font.loadFromFile("04B_30__.ttf");
//Text text("", font, 14);
////text.setColor(Color::Red);
//text.setStyle(Text::Regular);
//f.x = 10;
//f.y = 10;
//fruitType = static_cast<Fruits>(rand() % 2);
//std::cout << fruitType;
//
//while (gameWindow.isOpen())
//{
//	float time = clock.getElapsedTime().asSeconds();
//	clock.restart();
//	timer += time;
//
//	Event e;
//	while (gameWindow.pollEvent(e))
//	{
//		//if (e.type == Event::Resized)
//		//{
//		//	// update the view to the new size of the window
//		//	FloatRect visibleArea(0, 0, e.size.width, e.size.height);
//		//	gameWindow.setView(View(visibleArea));
//		//}
//		if (e.type == Event::Closed)
//			gameWindow.close();
//	}
//
//	if (dir != 2)
//	{
//		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
//			dir = 1;
//	}
//	if (dir != 1)
//	{
//		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
//			dir = 2;
//	}
//	if (dir != 0) {
//		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
//			dir = 3;
//	}
//	if (dir != 3)
//	{
//		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
//			dir = 0;
//	}
//
//	if (timer > delay)
//	{
//		timer = 0;
//		logic();
//	}
//
//	////// draw //////
//	gameWindow.clear();
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 2; j < M; j++)
//		{
//			if (i % 2 != 0 || j % 2 != 0) {
//				if (i % 2 != 0 && j % 2 != 0) {
//					bgDarkSprite.setPosition(i*size, j*size);
//					gameWindow.draw(bgDarkSprite);
//				}
//				else {
//					bgLightSprite.setPosition(i*size, j*size);
//					gameWindow.draw(bgLightSprite);
//				}
//			}
//			else {
//				bgDarkSprite.setPosition(i*size, j*size);
//				gameWindow.draw(bgDarkSprite);
//			}
//		}
//	}
//	for (int i = 0; i < num; i++)
//	{
//		if (i < 1) {
//			snakeHeadSprite.setPosition(s[i].x*size, s[i].y*size);
//			gameWindow.draw(snakeHeadSprite);
//		}
//		else {
//			snakeBodySprite.setPosition(s[i].x*size, s[i].y*size);
//			gameWindow.draw(snakeBodySprite);
//		}
//	}
//
//	if (fruitType == STANDART)
//	{
//		appleSprite.setPosition(f.x*size, f.y*size);
//		gameWindow.draw(appleSprite);
//
//	}
//	else
//	{
//		speedAppleSprite.setPosition(f.x*size, f.y*size);
//		gameWindow.draw(speedAppleSprite);
//
//	}
//	std::ostringstream scoreString;
//	scoreString << score;
//	text.setString("Score:" + scoreString.str());
//	text.setPosition(1, 1);
//	gameWindow.draw(text);
//	gameWindow.display();
//	if (isTailHit) gameWindow.close();
//}