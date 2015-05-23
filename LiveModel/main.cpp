#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "LiveModel.h"

#define FIELD_N		15
#define FIELD_M		15

int random(int min, int max)
{
	return (min + rand() % (max - min + 1));
}

int main(int argc, char* argv[])
{
	srand((int)time(NULL));
	LiveModel a(FIELD_N, FIELD_M);

	//	Инизиализируем поле
	for (int i = 0; i < 80; i++)
	{
		a.SetRow(random(0, FIELD_N - 1), random(0, FIELD_M - 1), (bool)random(0, 1));
	}
	
	while (true)
	{
		for (int i = 0; i < FIELD_N; i++)
		{
			for (int j = 0; j < FIELD_M; j++)
			{
				printf("%i", a.GetRow(i, j));
			}
			std::cout << std::endl;
		}

		//_getch();
		system("CLS");
		a.Step();
	}
	return false;
}
