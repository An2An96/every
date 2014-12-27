#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>

#include "turn_class.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	Turn t;
	cin >> t;
	cout << t << endl;
	cout << t.Length() << endl;

	system("pause");
	return 0;
}
