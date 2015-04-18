#include "jcword.h"

Jcword::Jcword(int row, int col)
{
	Init(row, col);
}

Jcword::Jcword(int row, int col, bool **cword)
{
	Init(row, col);
	WriteIn(row, col, cword);
}

Jcword::~Jcword()
{
	for (int i = 0; i < row; i++)
		delete[] crossword[i];
	delete[] crossword;
}

bool Jcword::WriteIn(int r_size, int c_size, bool **cword)
{
	if (r_size != row || c_size != col)
	{
		std::cerr << "Размеры создаваемого кроссворда не соответствуют размерам массива с информацией о его содержимом." << std::endl;
		return false;
	}
	else
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				crossword[i][j] = cword[i][j];
		Calculate();
		return true;
	}
}

bool Jcword::getElement(int numcol, int numrow)
{
	return crossword[numcol][numrow];
}

std::istream &operator>> (std::istream & is, Jcword &cword)
{
	is.clear();
	for (int i = 0; i < cword.row; i++)
		for (int j = 0; j < cword.col; j++)
			is >> cword.crossword[i][j];
	cword.Calculate();
	return is;
}

std::string Jcword::getRowInfo(int row)
{
	if (this->row == 0 || this->col == 0)
	{
		std::cerr << "Кроссворд еще не инициализирован значениями." << std::endl;
		return "error";
	}
	if (row < 0 || row > this->row)
	{
		std::cerr << "Попытка получить информацию о строке с несуществующим индексом." << std::endl;
		return "error";
	}
	return r_row[row];
}
   
std::string Jcword::getColInfo(int col)
{
	if (this->row == 0 || this->col == 0)
	{
		std::cerr << "Кроссворд еще не инициализирован значениями." << std::endl;
		return "error";
	}
	if (col < 0 || col > this->col)
	{
		std::cerr << "Попытка получить информацию о столбце с несуществующим индексом." << std::endl;
		return "error";
	}
	return r_col[col];
}

bool Jcword::show()
{
	//	Выведем реузльтат
		//	Результат по столбцам
	std::cout << "\t";
	for (int i = 0; i < col; i++)
		std::cout << r_col[i] << "\t";
	std::cout << std::endl;
		//	Результат по строкам
	for (int i = 0; i < row; i++)
	{
		std::cout << r_row[i] << "\t";
		for (int j = 0; j < col; j++)
			std::cout << crossword[i][j] << "\t";
		std::cout << std::endl;
	}
	return true;
}

void Jcword::Calculate()
{
	char s[15];
	// считем по столбцам
	int counter = 0;
	bool flag = false;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (crossword[j][i])	counter++;
			else if (counter)
			{
				if (flag)	r_col[i].append(",");
				r_col[i].append(std::to_string(counter));
				flag = true;
				counter = 0;
			}
		}
		if (counter)
		{
			if (flag)	r_col[i].append(",");
			r_col[i].append(std::to_string(counter));
			counter = 0;
		}
		else if (flag == false)
			r_col[i].append("0");
		flag = false;
	}
	//	считаем по строкам
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (crossword[i][j])	counter++;
			else if (counter)
			{
				if (flag)	r_row[i].append(",");
				r_row[i].append(std::to_string(counter));
				flag = true;
				counter = 0;
			}
		}
		if (counter)
		{
			if (flag)	r_row[i].append(",");
			r_row[i].append(std::to_string(counter));
			counter = 0;
		}
		else if (flag == false)
			r_row[i].append("0");
		flag = false;
	}
}

void Jcword::Init(int row, int col)
{
	this->row = row;
	this->col = col;
	crossword = new bool*[row];
	for (int i = 0; i < row; i++)
		crossword[i] = new bool[col];

	r_row = new std::string[row];
	r_col = new std::string[col];
}
