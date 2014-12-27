#include "tic-tac-toe.h"

game::game()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			square[i][j] = C_NONE;
}

game::~game()
{
}

bool game::whoWalks()
{
	return (move == M_X) ? true : false;
}

std::istream &operator>> (std::istream & is, game &g)
{
	is.clear();
	int x, y;
	is >> x >> y;
	while (g.makeMove(x, y) == false)
	{
		std::cout << "Вы ввели неверную ячейку или эта ячейка занята, введите другую:" << std::endl;
		is >> x >> y;
	}
	return is;
}

bool game::makeMove(int x, int y)
{
	if (x < 0 || x > 3 || y < 0 || y > 3 || square[x][y] != C_NONE)
	{
		return false;
	}
	else
	{
		square[x][y] = (move == M_X) ? C_X : C_TOE;
		if (checkWin() == false)
			move = (move == M_X) ? M_TOE : M_X;
		return true;
	}
}

bool game::checkWin()
{
	for (int i = 0; i < 3; i++)
	{
		if (square[i][0] != C_NONE && (square[i][0] == square[i][1] && square[i][0] == square[i][1] == square[i][2]))
			win = (square[i][0] == C_X) ? M_X : M_TOE;
		else if (square[0][i] != C_NONE && (square[0][i] == square[1][i] && square[0][i] == square[1][i] == square[2][i]))
			win = (square[0][i] == C_X) ? M_X : M_TOE;
	}
	if (win == M_NONE)
	{
		if (square[0][0] != C_NONE && (square[0][0] == square[1][1] && square[1][1] == square[2][2]))
			win = (square[0][0] == C_X) ? M_X : M_TOE;
		else if (square[0][2] != C_NONE && (square[0][2] == square[1][1] && square[1][1] == square[2][0]))
			win = (square[0][2] == C_X) ? M_X : M_TOE;
	}
	return (win != M_NONE) ? true : false;
}

bool game::isOver()
{
	if (win == M_NONE)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (square[i][j] == C_NONE)
					return false;
	return true;
}

void game::showResult()
{
	if (win == M_NONE)	std::cout << "Игра закончилась ничьей." << std::endl;
	else			std::cout << "Победили " << ((win == M_X) ? "крестики" : "нолики") << std::endl;
}

void game::show()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (square[i][j] == C_X)		std::cout << "X\t";
			else if (square[i][j] == C_TOE)		std::cout << "O\t";
			else					std::cout << "\t";
		}
		std::cout << std::endl;
	}
}
