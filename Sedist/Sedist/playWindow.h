#pragma once
#include <SFML/Graphics.hpp>
#include "helper.h"

using namespace sf;

void playWindowFunc(RenderWindow &gameWindow, bool isTailHit, int N, int M, int score, int size, int num, Text *text, Fruct f, Fruits fruitType, Snake s[], Sprite *appleSprite, Sprite *speedAppleSprite, Sprite *bgDarkSprite, Sprite *bgLightSprite, Sprite *snakeHeadSprite, Sprite *snakeBodySprite, Sprite *rotAppleSprite);