#pragma once

#include <algorithm>

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
	bool Rules(int, bool);

	int sizeX, sizeY;
	bool** Field;
	bool** uField;
};

