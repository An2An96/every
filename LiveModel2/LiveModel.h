#pragma once

#include <algorithm>

enum E_RSTATE	{
	R_DEAD,
	R_ALIVE,
	R_BORN,
	R_DIED
};

class LiveModel
{
public:
	LiveModel(int, int);
	~LiveModel();

	void Step();
	void SetRow(int, int, bool);
	bool GetRow(int, int);

private:
	int Calculate(int, int);
	E_RSTATE Rules(int, E_RSTATE);

	int sizeX, sizeY;
	E_RSTATE** Field;
};

