#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameOver.h"

using namespace sf;

void gameOverFunc(RenderWindow &resultWindow, GameOver *gameOver, bool *isReplay, int score);