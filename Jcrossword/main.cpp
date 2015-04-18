#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>

#include "jcword.h"

#define N	3

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	int row, col;
	cout << "Введите размер 'Японского кроссворда':" << endl;
	cin >> row >> col;

	Jcword word_one(row, col);

	cout << "Введите размер содержимое кроссврода:" << endl;
	bool **result = new bool*[row];
	for (int i = 0; i < row; i++)
	{	  
		cout << "Введите " << i << " строку: ";
		result[i] = new bool[col];
		for (int j = 0; j < col; j++)
			cin >> result[i][j];						   
	}

	word_one.WriteIn(row, col, result);
	cout << "Результат:" << endl;
	word_one.show();

	Jcword word_two(N, N);
	cout << "Введите значение для второго кроссворда: " << endl;
	cin >> word_two;

	//	Вывод вручную с помощью вспомогательных функций
	cout << "\t";
	for (int i = 0; i < N; i++)
		cout << word_two.getColInfo(i) << "\t";
	cout << endl;
	//	Результат по строкам
	for (int i = 0; i < N; i++)
	{
		cout << word_two.getRowInfo(i) << "\t";
		for (int j = 0; j < N; j++)
			cout << word_two.getElement(i, j) << "\t";
		cout << endl;
	}

	system("pause");
	return 0;
}
