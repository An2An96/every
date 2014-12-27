#include <stdio.h>
#include <tchar.h>
#include <iostream>

#include "tic-tac-toe.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	game game_a;
	while (game_a.isOver() == false)
	{
		game_a.show();
		cout << "Ход " << (game_a.whoWalks() ? "крестиков" : "ноликов") << ":" << endl;
		cin >> game_a;
	}
	game_a.show();
	game_a.showResult();

	system("pause");
	return 0;
}
