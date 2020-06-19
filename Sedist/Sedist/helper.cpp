#include "helper.h"

void logic(int *num, int dir, Snake *s, Fruct *f, Fruits *fruitType, float *delay, int *score, int N, int M, bool *isTailHit)
{
	for (int i = *num; i > 0; --i)
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

	if (((s[0].x == f->x) && (s[0].y == f->y)) || ((s[1].x == f->x) && (s[1].y == f->y)))
	{
		if (*fruitType == SPEED)
		{
			*delay = 0.05;
			*score = *score + 1;
		}
		if (*fruitType == STANDART)
		{
			*delay = 0.1;
		}
		if (*fruitType == ROT)
		{
			*delay = 0.1;
			*num = *num - 2;
			*score = *score - 2;
		}
		*num = *num + 1;
		*score = *score + 1;
		if (*score > 10)
		{
			*fruitType = static_cast<Fruits>(rand() % 3);
		}
		else
		{
			*fruitType = static_cast<Fruits>(rand() % 2);
		}
		
		f->x = 2 + rand() % (N - 2);
		f->y = 2 + rand() % (M - 2);
		for (int i = 0; i < *num; i++) {
			if (f->x == s[i].x && f->y == s[i].y) {
				f->x = 2 + rand() % (N - 2);
				f->y = 2 + rand() % (M - 2);
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
	for (int i = 1; i < *num; i++)
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y) {
			*isTailHit = true;
		}
	}
}