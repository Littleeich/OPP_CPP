#pragma once
#pragma once
#include "Student.h"
#include <string>


class Aspirant : public Student
{
	string department;

public:
	Aspirant(char * name, char * second_name, char * surname, GENDER gender, Date birth, char * ofStudent, int * Exams, int * Courses, int * Moduls, string department)
		:Student(name, second_name, surname, gender, birth, ofStudent, Exams, Courses, Moduls)
	{
		this->department = department;
	}

	Aspirant() :Aspirant("John", "Iosifovich", "Dou", GENDER::MALE, (28, 12, 1970), "Khreshatic", nullptr, nullptr, nullptr, "Economics"){}
	Aspirant(string dep) :Aspirant("John", "Iosifovich", "Dou", GENDER::MALE, (28, 12, 1970), "Khreshatic", nullptr, nullptr, nullptr, dep){}
	Aspirant(char * name, char * second_name, char * surname, string dep) : Aspirant(name, second_name, surname, GENDER::MALE, (9, 5, 1945), "Khreschatic", nullptr, nullptr, nullptr, dep){}

	Aspirant(const Aspirant & other);
	const string const GetDep() const { return department; }

	void operator=(const Aspirant & other);

	~Aspirant();
};

