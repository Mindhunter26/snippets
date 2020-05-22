#include "PlayWindow.h"

void playWindowFunc(RenderWindow &gameWindow, bool isTailHit, int N, int M, int score, int size, int num, Text *text, Fruct f, Fruits fruitType, Snake s[], Sprite *appleSprite, Sprite *speedAppleSprite, Sprite *bgDarkSprite, Sprite *bgLightSprite, Sprite *snakeHeadSprite, Sprite *snakeBodySprite)
{
	for (int i = 0; i < N; i++) {
		for (int j = 2; j < M; j++)
		{
			if (i % 2 != 0 || j % 2 != 0) {
				if (i % 2 != 0 && j % 2 != 0) {
					bgDarkSprite->setPosition(i*size, j*size);
					gameWindow.draw(*bgDarkSprite);
				}
				else {
					bgLightSprite->setPosition(i*size, j*size);
					gameWindow.draw(*bgLightSprite);
				}
			}
			else {
				bgDarkSprite->setPosition(i*size, j*size);
				gameWindow.draw(*bgDarkSprite);
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (i < 1) {
			snakeHeadSprite->setPosition(s[i].x*size, s[i].y*size);
			gameWindow.draw(*snakeHeadSprite);
		}
		else {
			snakeBodySprite->setPosition(s[i].x*size, s[i].y*size);
			gameWindow.draw(*snakeBodySprite);
		}
	}

	if (fruitType == STANDART)
	{
		appleSprite->setPosition(f.x*size, f.y*size);
		gameWindow.draw(*appleSprite);

	}
	else
	{
		speedAppleSprite->setPosition(f.x*size, f.y*size);
		gameWindow.draw(*speedAppleSprite);

	}
	text->setString("Score:" + std::to_string(score));
	text->setPosition(1, 1);
	gameWindow.draw(*text);
	gameWindow.display();
	if (isTailHit) gameWindow.close();
}