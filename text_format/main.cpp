#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>

#define S_LEN	80

int main()
{
	std::string s;
	std::getline(std::cin, s);
	printf("\n\n");

	//	формируем корректные переносы строк (без разрывов слов)
	int i = 0, k = 0, space = 0;
	while (s[i])
	{
		if (space && k == S_LEN)
		{
			s.replace(space, 1, "\n");
			k = 0;
			continue;
		}
		if (s[i] == ' ')	space = i;
		i++;	k++;
	}

	i = 0;	k = 0;
	int p = 0, start = 0, np = 0;
	while (s[i])
	{
		if (s[i] != '\n')
		{
			if (k == 0)	start = i;
			k++;

			if (s[i] == ' ')	p++;	//	считаем кол-во пробелов
			
			if (s[i + 1] == '\n' || s[i + 1] == '\0')
			{	
				if (p == 0)	np = 0;
				else		np = (double)(S_LEN - k);
					
				//	добавляем пробелы
				int j = start;
				while (np)
				{
					if (j > i)	j = start;
					if (s[j] == ' ')
					{
						s.insert(j, " ");
						np--;
						i++;	j++;
					}
					j++;
				}
				//	выводим строку
				for (j = start; j <= i; j++)
					std::cout << s[j];

				k = 0;	p = 0;
			}
		}
		i++;
	}

	system("pause");
	return 0;
}
