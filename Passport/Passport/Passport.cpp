#include "Passport.h"
#include <iostream>
#include <string>

using namespace std;


Passport::Passport(string name, string surname, Date ofBirth, Date ofGiving, Date ofEnd, string placeOfGiving)
{
	this->name = name;
	this->surname = surname;
	this->ofBirth = ofBirth;
	this->ofGiving = ofGiving;
	this->ofEnd = ofEnd;
	this->placeOfGiving = placeOfGiving;
}

Passport::Passport(const Passport & other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->ofBirth = other.ofBirth;
	this->ofGiving = other.ofGiving;
	this->ofEnd = other.ofEnd;
	this->placeOfGiving = other.placeOfGiving;
}

void Passport::operator=(const Passport & other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->ofBirth = other.ofBirth;
	this->ofGiving = other.ofGiving;
	this->ofEnd = other.ofEnd;
	this->placeOfGiving = other.placeOfGiving;
}

void Passport::Show()
{
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Date of Birth: " << ofBirth.GetDay() << "  " << ofBirth.GetMonth() << "  " << ofBirth.GetYear() << endl;
	cout << "Date of Giving: " << ofGiving.GetDay() << "  " << ofGiving.GetMonth() << "  " << ofGiving.GetYear() << endl;
	cout << "Date of End: " << ofEnd.GetDay() << "  " << ofEnd.GetMonth() << "  " << ofEnd.GetYear() << endl;
	cout << "Place of giving: " << placeOfGiving << endl;
}

void Passport::SetName(string name)
{
	this->name = name;
}

void Passport::SetSurname(string surname)
{
	this->surname = surname;
}

void Passport::SetDateBirth(int a, int b, int c)
{
	this->ofBirth = Date(a, b, c);
}

void Passport::SetDateGiving(int a, int b, int c)
{
	this->ofGiving = Date(a, b, c);
}

void Passport::SetDateEnd(int a, int b, int c)
{
	this->ofEnd = Date(a, b, c);
}

Passport::~Passport()
{
	cout << "destructor of passport\n";
}

void FPassport::ShowF()
{
	Show();
	cout << "Forein name: " << fname << endl;
	cout << "Forein surname: " << fsurname << endl;
	cout << "Visa information: " << endl << endl;
	if (myVisa.GetCount() == 0)
		cout << "No visa\n\n";
	else
		for (int i = 0; i < myVisa.GetCount(); i++)
			cout << myVisa[i].country << "  from " << myVisa[i].start.GetYear() << " " << myVisa[i].start.GetMonth()
			<< " " << myVisa[i].start.GetDay() << "  to " << myVisa[i].end.GetYear() << " " << myVisa[i].end.GetMonth()
			<< " " << myVisa[i].end.GetDay() << endl;

	cout << "Visits information: " << endl << endl;
	if (myVisits.GetCount() == 0)
		cout << "No visits\n\n";
	else
		for (int i = 0; i < myVisits.GetCount(); i++)
			cout << myVisits[i].country << "  from " << myVisits[i].start.GetYear() << " " << myVisits[i].start.GetMonth()
			<< " " << myVisits[i].start.GetDay() << "  to " << myVisits[i].end.GetYear() << " " << myVisits[i].end.GetMonth()
			<< " " << myVisits[i].end.GetDay() << endl;
	
}