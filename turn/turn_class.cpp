#include "turn_class.h"

Turn::Turn()
{
}

Turn::~Turn()
{
	while (HeadElement)
	{	 
		TurnElement* t = HeadElement[0].next;
		delete HeadElement;
		HeadElement = t;
	}
	delete HeadElement, OldElement;
}

void Turn::Enqueue(string s)
{
	int len = Length();
	if (len)
	{
		TurnElement* t = OldElement;
		OldElement = new TurnElement;
		OldElement[0].content = s;
		OldElement[0].prev = &t[0];
		t[0].next = OldElement;
	}
	else
	{
		HeadElement = new TurnElement;
		HeadElement[0].content = s;
		OldElement = HeadElement;
	}
}

std::string Turn::Begin()
{
	return HeadElement[0].content;
}

int Turn::Length()
{
	Turn::TurnElement* t = HeadElement;
	int i;
	while (t)
	{	
		t = t[0].next;
		i++;
	}
	return i;
}

std::ostream& operator<<(std::ostream& os, const Turn& t)
{
	Turn::TurnElement* turnData = t.HeadElement;
	while (turnData)
	{
		os << turnData[0].content;
		turnData = turnData[0].next;
		if (turnData)
			os << ", ";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Turn& t)
{
	string s;
	for (int i = 0; getline(is, s); i++)
		t.Enqueue(s);
	return is;
}
