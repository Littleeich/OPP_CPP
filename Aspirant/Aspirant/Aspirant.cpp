#include "Aspirant.h"


Aspirant::Aspirant(const Aspirant & other)
{
	SetName(other.name);
	SetSecond(other.second_name);
	SetSurname(other.surname);
	SetGender(other.gender);
	this->birth = other.birth;
	SetAdress(other.ofStudent);
	SetExams(other.Exams);
	SetCourses(other.Courses);
	SetModuls(other.Moduls);
	this->department = other.department;
}

void Aspirant::operator=(const Aspirant & other)
{
	SetName(other.name);
	SetSecond(other.second_name);
	SetSurname(other.surname);
	SetGender(other.gender);
	this->birth = other.birth;
	SetAdress(other.ofStudent);
	SetExams(other.Exams);
	SetCourses(other.Courses);
	SetModuls(other.Moduls);
	this->department = other.department;
}


Aspirant::~Aspirant()
{
	cout << "Aspirant destructor!\n";
}
