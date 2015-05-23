#include "LiveModel.h"

LiveModel::LiveModel(int x, int y)
{
	sizeX = x, sizeY = y;

	Field = new E_RSTATE*[y];
	for (int i = 0; i < y; i++)
	{
		Field[i] = new E_RSTATE[x];
		for (int j = 0; j < x; j++)
			Field[i][j] = R_DEAD;
	}
}

LiveModel::~LiveModel()
{
	for (int i = 0; i < sizeY; i++)
		delete[] Field[i];
	delete[] Field;
}

int LiveModel::Calculate(int x, int y)
{
	int p = 0;
	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if (i < 0 || j < 0 || i >= sizeY || j >= sizeX || (i == y && j == x))
				continue;

			if (Field[i][j] == R_ALIVE || Field[i][j] == R_DIED)  p++;
		}
	}
	return p;
}

E_RSTATE LiveModel::Rules(int p, E_RSTATE state)
{
	if (state == R_DEAD && p > 2)					return R_BORN;
	else if (state == R_ALIVE && (p < 2 || p > 3))	return R_DIED;
	else 											return state;
}

void LiveModel::Step()
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			Field[i][j] = Rules(Calculate(j, i), Field[i][j]);
		}
	}
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (Field[i][j] == R_BORN)		Field[i][j] = R_ALIVE;
			else if (Field[i][j] == R_DIED)	Field[i][j] = R_DEAD;
		}
	}
}

void LiveModel::SetRow(int x, int y, bool state)
{
	Field[x][y] = (state) ? R_ALIVE : R_DEAD;
}

bool LiveModel::GetRow(int x, int y)
{
	return Field[x][y];
}
