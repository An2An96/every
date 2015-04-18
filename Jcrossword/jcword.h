class Jcword	{

	friend std::istream &operator>> (std::istream &, Jcword &);

public:
	Jcword(int, int);
	Jcword(int, int, bool **);
	~Jcword();
	bool WriteIn(int, int, bool **);
	bool getElement(int, int);
	std::string getRowInfo(int);
	std::string getColInfo(int);
	bool show();

private:
	void Init(int, int);
	void Calculate();

	bool** crossword;	   
	std::string* r_row;
	std::string* r_col;

	int row = 0, col = 0;
};
