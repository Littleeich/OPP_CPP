#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Passport
{
	Date ofBirth;
	Date ofGiving;
	Date ofEnd;
	string name;
	string surname;
	string placeOfGiving;

public:
	Passport(string name, string surname, Date ofBirth, Date ofGiving, Date ofEnd, string placeOfGiving);
	Passport() : Passport("Джон", "Доу", Date(1, 1, 1970), Date(1, 1, 2000), Date(31, 12, 2999), "5104"){}

	Passport(const Passport & other);
	void operator=(const Passport & other);

	void SetName(string name);
	void SetSurname(string surname);
	void SetDateBirth(int day, int month, int year);
	void SetDateGiving(int day, int month, int year);
	void SetDateEnd(int day, int month, int year);
	void SetPlace(string place);

	string const GetName() const { return name; }
	string const GetSurname() const { return surname; }
	Date const GetBirth() const { return ofBirth; }
	Date const GetGiving() const { return ofGiving; }
	Date const GetEnd() const { return ofEnd; }
	string const GetPlace() const { return placeOfGiving; }

	void Show();
	
	~Passport();
};

