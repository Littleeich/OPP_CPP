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
