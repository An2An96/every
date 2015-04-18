#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <fstream>
#include <vector>

#include <string>
#include <conio.h>

using namespace std;

void delim_date(const string s, int &day, int &mon, int &year)
{
	char result[4];
	int index = 0, step = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			if (step == 0)		day = atoi(result);
			else if (step == 1)	mon = atoi(result);
			step++;
			index = 0;
			strcpy_s(result, "\0\0\0\0");	//	clear string
		}
		else
			result[index++] = s[i];
	}
	year = atoi(result);
}

void swap(int &a, int &b)
{
	int buff = a;
	a = b;
	b = buff;
}

int main()
{
	setlocale(LC_ALL, "russian");

	ifstream F("input.txt", ios::in);
	string s;
	int count = 0;
	//	посчитаем кол-во строк с датами (для выделения памяти)
	while (F.eof() == false)
	{
		getline(F, s);
		count++;
	}
	F.seekg(0);	//	сбрасываем последовательность чтения
	//	выделяем память
	int **date = new int*[count];
	for (int i = 0; i < count; i++)
		date[i] = new int[3];
	//	считываем даты в массив
	count = 0;
	while (F.eof() == false)
	{	  
		getline(F, s);
		delim_date(s, date[count][0], date[count][1], date[count][2]);
		count++;
	}
	F.close();	//	закрываем файл
	//	сортируем
	int buff;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((date[j][2] > date[j + 1][2])										//	если год больше - меняем 
				|| (date[j][2] == date[j + 1][2] && date[j][1] > date[j + 1][1])	//	год один, месяц больше - меняем
				|| (date[j][2] == date[j + 1][2] && date[j][1] == date[j + 1][1] && date[j][0] > date[j + 1][0]))	//	год, месяц один, день больше - меняем
			{
				swap(date[j][0], date[j + 1][0]);
				swap(date[j][1], date[j + 1][1]);
				swap(date[j][2], date[j + 1][2]);
			}
		}
	}
	//	выводим в файл
	ofstream OF("output.txt", ios::out);
	for (int i = 0; i < count; i++)
		OF << date[i][0] << "." << date[i][1] << "." << date[i][2] << endl;
	OF.close();

	system("pause");
	return 0;
}
