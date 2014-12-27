enum Cell
{
	C_NONE,
	C_X,
	C_TOE
};

enum Move
{
	M_NONE,
	M_X,
	M_TOE
};

class game	{

	friend std::istream &operator>> (std::istream &, game &);

public:
	game();
	~game();
	bool whoWalks();
	bool makeMove(int, int);
	bool checkWin();
	bool isOver();
	void show();
	void showResult();

private:
	Cell square[3][3];
	Move move = M_X;
	Move win = M_NONE;
};
