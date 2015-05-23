#include "LiveModel.h"

LiveModel::LiveModel(int x, int y)
{
	sizeX = x, sizeY = y;

	Field = new bool*[y];
	uField = new bool*[y];
	for (int i = 0; i < y; i++)
	{
		Field[i] = new bool[x];
		uField[i] = new bool[x];
		for (int j = 0; j < x; j++)
		{
			Field[i][j] = false;
			uField[i][j] = false;
		}
	}
}

LiveModel::~LiveModel()
{
	for (int i = 0; i < sizeY; i++)
	{
		delete[] Field[i];
		delete[] uField[i];
	}
	delete[] Field;
	delete[] uField;
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

			if (Field[i][j])  p++;
		}
	}
	return p;
}

bool LiveModel::Rules(int p, bool state)
{
	if (p == 3)			return true;
	else if (p == 2)	return state;
	else				return false;
}

void LiveModel::Step()
{
	int p;
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			p = Calculate(j, i);
			uField[i][j] = Rules(p, Field[i][j]);
			
		}
	}
	std::swap(Field, uField);
}

void LiveModel::SetRow(int x, int y, bool state)
{
	Field[x][y] = state;
}

bool LiveModel::GetRow(int x, int y)
{
	return Field[x][y];
}
