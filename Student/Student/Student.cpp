#include "Student.h"
#include "Date.h"

void Student::SetName(char * name)
{
	int length = strlen(name) + 1;
	if (length < 2) return;

	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

void Student::SetSecond(char * second_name)
{
	int length = strlen(second_name) + 1;
	if (length < 2) return;

	if (this->second_name)
	{
		delete[] this->second_name;
		this->second_name = nullptr;
	}
	this->second_name = new char[length];
	strcpy_s(this->second_name, length, second_name);
}

void Student::SetSurname(char * surname)
{
	int length = strlen(surname) + 1;
	if (length < 2) return;

	if (this->surname)
	{
		delete[] this->surname;
		this->surname = nullptr;
	}
	this->surname = new char[length];
	strcpy_s(this->surname, length, surname);
}

void Student::SetGender(GENDER gender)
{
	this->gender = gender;
}

void Student::SetAdress(char * _ofStudent)
{
	int length = strlen(_ofStudent) + 1;
	if (length < 2) return;

	if (ofStudent)
	{
		delete[] ofStudent;
		this->ofStudent = nullptr;
	}

	ofStudent = new char[length];
	strcpy_s(ofStudent, length, _ofStudent);
}

void Student::SetExams(int * Marks)
{
	if (Marks == nullptr)
		for (int i = 0; i < amountOfMarks; i++)
			Exams[i] = 0;
	else
	{
		for (int i = 0; i < amountOfMarks; i++)
			if (Marks[i] < 0 || Marks[i] > 100)
				Exams[i] = 0;
			else
				Exams[i] = Marks[i];
	}
}

void Student::SetCourses(int * Marks)
{
	if (Marks == nullptr)
		for (int i = 0; i < amountOfMarks; i++)
			Courses[i] = 0;
	else
	{
		for (int i = 0; i < amountOfMarks; i++)
			if (Marks[i] < 0 || Marks[i] > 100)
				Courses[i] = 0;
			else
				Courses[i] = Marks[i];
	}
}

void Student::SetModuls(int * Marks)
{
	if (Marks == nullptr)
		for (int i = 0; i < amountOfMarks; i++)
			Moduls[i] = 0;
	else
	{
		for (int i = 0; i < amountOfMarks; i++)
			if (Marks[i] < 0 || Marks[i] > 100)
				Moduls[i] = 0;
			else
				Moduls[i] = Marks[i];
	}
}

Student::Student(char * name, char * second_name, char * surname, GENDER gender, Date birth, char * ofStudent, int * Exams, int * Courses, int * Moduls)
{
	SetName(name);
	SetSecond(second_name);
	SetSurname(surname);
	SetGender(gender);
	this->birth = birth;
	SetAdress(ofStudent);
	SetExams(Exams);
	SetCourses(Courses);
	SetModuls(Moduls);
}

Student::Student(const Student & other)
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
}

void Student::operator=(const Student& other)
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
}

void Student::changeExam(int Mark, int number)
{
	if (number < 1 || number > amountOfMarks) return;
	if (Mark < 0 || Mark > 100) return;

	Exams[number - 1] = Mark;
}

void Student::changeCourse(int Mark, int number)
{
	if (number < 1 || number > amountOfMarks) return;
	if (Mark < 0 || Mark > 100) return;

	Courses[number - 1] = Mark;
}

void Student::changeModule(int Mark, int number)
{
	if (number < 1 || number > amountOfMarks) return;
	if (Mark < 0 || Mark > 100) return;

	Moduls[number - 1] = Mark;
}

Student::~Student()
{
	delete[] name;
	name = nullptr;
	delete[] surname;
	surname = nullptr;
	delete[] second_name;
	second_name = nullptr;
	delete[] ofStudent;
	ofStudent = nullptr;
	delete[] Exams;
	Exams = nullptr;
	delete[] Courses;
	Courses = nullptr;
	delete[] Moduls;
	Moduls = nullptr;
	cout << "\nOK!\n";
}
