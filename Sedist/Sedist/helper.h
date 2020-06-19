#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
class Snake {
public:
	int x, y;
};

class Fruct {
public:
	int x, y;
};

enum Fruits {
	STANDART,
	SPEED,
	ROT
};

void logic(int *num, int dir, Snake *s, Fruct *f, Fruits *fruitType, float *delay, int *score, int N, int M, bool *isTailHit);

