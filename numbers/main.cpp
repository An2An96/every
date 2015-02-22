#include "stdafx.h"

using namespace std;

vector<int> result;

//	Ф-ия добавляющая подходящее число в результирующий вектор
//	Отсеивающая повторяющие числа
void addResult(int num)
{
	for (vector<int>::iterator cur = result.begin(); cur < result.end(); cur++)
	{
		if (*cur == num)
		{
			return;
		}
	}
	result.push_back(num);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");

	//	Объявляем переменные
	int count = 0;

	vector <int> num[2];
	string	line[2], 
			s_Buffer;

	//	открываем файл
	ifstream F("input.txt", ios::in);
	getline(F, line[0]);	//	читаем первую строку
	getline(F, line[1]);	//	читаем вторую строку
	F.close();	//	закрываем файл

	//	Забиваем числа из 1 строки в вектор
	for (int i = 0; i < line[0].length(); i++)
	{
		if (line[0][i] != ' ')
		{
			s_Buffer.push_back(line[0][i]);
			count++;
			if (i + 1 != line[0].length())
			{
				continue;
			}
		}
		if (count)
		{
			num[0].push_back(atoi(s_Buffer.c_str()));
			s_Buffer.clear();
			count = 0;
		}
	}
	//	очищаем буффер и счетчик после обработки первой строки
	count = 0;
	s_Buffer.clear();
	//	Забиваем числа из 2 строки в вектор
	for (int i = 0; i < line[1].length(); i++)
	{
		if (line[1][i] != ' ')
		{
			s_Buffer.push_back(line[1][i]);
			count++;
			if (i + 1 != line[1].length())
			{
				continue;
			}
		}
		if (count)
		{
			num[1].push_back(atoi(s_Buffer.c_str()));
			s_Buffer.clear();
			count = 0;
		}
	}
	//	Выбор действия пользователем
	int opertion;
	cout << "Список операций:" << endl;
	cout << "1. Найти числа, присутствующие в обоих строках" << endl;
	cout << "2. Найти числа, присутствующие в первой строке, но отсутствующие во второй" << endl;
	cout << "3. Найти числа, присутствующие во второй строке, но отсутствующие в первой" << endl;
	cin >> opertion;
	//	Выполняем выбраное действие
	if (opertion == 1)
	{
		for (vector<int>::iterator cur = num[0].begin(); cur < num[0].end(); cur++)
		{
			for (vector<int>::iterator j = num[1].begin(); j < num[1].end(); j++)
			{
				if (*cur == *j)
				{
					addResult(*cur);
					break;
				}
			}
		}
	}
	else if (opertion == 2)
	{
		bool search = false;
		for (vector<int>::iterator cur = num[0].begin(); cur < num[0].end(); cur++)
		{
			for (vector<int>::iterator j = num[1].begin(); j < num[1].end(); j++)
			{
				if (*cur == *j)
				{
					search = true;
					break;
				}
			}
			if (search == false)	addResult(*cur);
			else					search = false;
		}
	}
	else if (opertion == 3)
	{
		bool search = false;
		for (vector<int>::iterator cur = num[1].begin(); cur < num[1].end(); cur++)
		{
			for (vector<int>::iterator j = num[0].begin(); j < num[0].end(); j++)
			{
				if (*cur == *j)
				{
					search = true;
					break;
				}
			}
			if (search == false)	addResult(*cur);
			else					search = false;
		}
	}
	//	Выводим результаты
	ofstream OF("output.txt", ios::out);
	for (vector<int>::iterator cur = result.begin(); cur < result.end(); cur++)
	{
		OF << *cur << " ";
	}
	OF.close();
	system("pause");
	return 0;
}
