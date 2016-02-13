#pragma once
#include "List.h"
#include "Date.h"

using namespace std;

enum class country
{
	Europe,
	Great_Britain,
	Egypt,
	Russia,
	Belaruss,
	Moldova,
	China,
	Ukraine
};

class visadata
{
public:
	country tur;
	Date start;
	Date end;

	visadata(country tur, Date start, Date end)
	{
		this->tur = tur;
		this->start = start;
		this->end = end;
	}
};

class Visa
{
	DList<visadata> myVisa;

public:

	DList<visadata> GetVisaList() const { return myVisa; }
	void AddVisa(country tur, Date start, Date end) { myVisa.AddTail(visadata(tur, start, end)); }

	Visa(country tur, Date start, Date end);
	Visa() : Visa(country::Ukraine, Date(1, 1, 1900), Date(31,12,2999)){}

	Visa(const Visa& other);

	~Visa();
};

Visa::Visa(country tur, Date start, Date end)
{
	DList<visadata> a;
	this->myVisa = a;
	this->myVisa.AddTail(visadata(tur, start, end));
}

//I don't plan to use this...
Visa::Visa(const Visa& other)
{
	this->myVisa = other.myVisa;
}

