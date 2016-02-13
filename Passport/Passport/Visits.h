#pragma once
#include "List.h"
#include "Date.h"

using namespace std;

class countrydata
{
public:
	string country;
	Date start;
	Date end;

	countrydata(string country, Date start, Date end)
	{
		this->country = country;
		this->start = start;
		this->end = end;
	}
};

class Visits
{
	DList<countrydata> myVisits;

public:

	DList<countrydata> GetCountriesList() const { return myVisits; }
	void AddVisits(string country, Date start, Date end) { myVisits.AddTail(countrydata(country, start, end)); }

	Visits(string country, Date start, Date end);
	Visits() : Visits("Ukraine", Date(1, 1, 1900), Date(31, 12, 2999)){}

	Visits(const Visits& other);

	~Visits();
};

Visits::Visits(string country, Date start, Date end)
{
	this->myVisits.AddTail(countrydata(country, start, end));
}

//I don't plan to use this...
Visits::Visits(const Visits& other)
{
	this->myVisits = other.myVisits;
}

