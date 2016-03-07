#pragma once
#include <string>
#include "Date.h"
#include "List.h"

using namespace std;

struct Journey{
	string country;
	Date start;
	Date end;
};

class Passport
{
protected:
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

class FPassport : public Passport
{
	string fname;
	string fsurname;
	DList<Journey> myVisa;
	DList<Journey> myVisits;

public:
	FPassport(string name, string surname, Date ofBirth, Date ofGiving, Date ofEnd, 
		string placeOfGiving, string fname, string fsurname, DList<Journey> myVisa, DList<Journey> myVisits) 
		:Passport(name, surname, ofBirth, ofGiving, ofEnd, placeOfGiving)
	{
		this->fname = fname;
		this->fsurname = fsurname;
	}

	FPassport(string name, string surname, Date ofBirth, Date ofGiving, Date ofEnd, string placeOfGiving, string fname, string fsurname, 
		string country1, Date start1, Date end1, string country2, Date start2, Date end2)
		:Passport(name, surname, ofBirth, ofGiving, ofEnd, placeOfGiving)
	{
		this->fname = fname;
		this->fsurname = fsurname;
	
		this->myVisa.AddHead({ country1, start1, end1 });
		this->myVisits.AddHead({ country2, start2, end2 });
	}

	FPassport(string name, string surname, Date ofBirth, Date ofGiving, Date ofEnd, string placeOfGiving, string fname, string fsurname)
		:Passport(name, surname, ofBirth, ofGiving, ofEnd, placeOfGiving)
	{
		this->fname = fname;
		this->fsurname = fsurname;
	}

	FPassport() :Passport() 
	{
		this->fname = string("John");
		this->surname = string("Dou");
	}

	void SetFName(string _fname) { fname = _fname; }
	void SetFSurname(string _fsurname) { fsurname = _fsurname; }

	const string const GetFName() const { return fname; }
	const string const GetFSurname() const { return fsurname; }

	void AddVisa(string country, Date start, Date end) { myVisa.AddTail({ country, start, end }); }
	void AddVisit(string country, Date start, Date end) { myVisits.AddTail({ country, start, end }); }

	void ShowF();
};

