#pragma once
#include <cmath>

struct Snake {
	int x, y;
};

struct Fruct {
	int x, y;
};

enum Fruits {
	STANDART,
	SPEED
};

void logic(int *num, int dir, Snake *s, Fruct *f, Fruits *fruitType, float *delay, int *score, int N, int M, bool *isTailHit);

