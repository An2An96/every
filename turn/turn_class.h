class Turn	{
public:
	Turn();
	~Turn();
	void Enqueue(string);
	std::string Begin();
	int Length();

	friend std::ostream& operator<<(std::ostream&, const Turn&);
	friend std::istream& operator>>(std::istream&, Turn&);

private:

	struct TurnElement	{
		string content;
		TurnElement* prev = NULL;
		TurnElement* next = NULL;
	}	*HeadElement, 
		*OldElement;
};
