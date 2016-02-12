#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

enum class GENDER{
	MALE, FEMALE
};

class Student
{
protected:
	int amountOfMarks = 10;
	int * Exams = new int[amountOfMarks];
	int * Courses = new int[amountOfMarks];
	int * Moduls = new int[amountOfMarks];
	Date birth;
	char * name;
	char * second_name;
	char * surname;
	char * ofStudent;
	GENDER gender;

	void SetGender(GENDER gender);

public:
	Student(char * name, char * second_name, char * surname, GENDER gender, Date birth, char * ofStudent, int * Exams, int * Courses, int * Moduls);
	Student(GENDER gender, Date birth) :Student("John", "Iosifovich", "Dou", gender, birth, "Khreshatic", nullptr, nullptr, nullptr){};
	Student(char * name, char * second_name, char * surname) : Student(name, second_name, surname, GENDER::MALE, (9, 5, 1945), "Khreschatic", nullptr, nullptr, nullptr){};
	Student() :Student("John", "Iosifovich", "Dou", GENDER::MALE, (28, 12, 1970), "Khreshatic", nullptr, nullptr, nullptr){};

	/*Student(const Student & other) : Student(other.GetName(), other.GetSecond(), other.GetSurname(), other.GetGender(), 
		other.GetDate(), other.ofStudent, other.GetExamsMarks(), other.GetCoursesMarks(), other.GetModulsMarks()){}*/

	Student(const Student & other);

	void SetName(char * name);
	void SetSecond(char * second_name);
	void SetSurname(char * surname);
	void SetBirth(Date birth);
	void SetAdress(char * _ofStudent);
	void SetExams(int * Marks);
	void SetCourses(int * Courses);
	void SetModuls(int * Moduls);

	char * GetName()const{ return name; };
	char * GetSecond()const { return second_name; };
	char * GetSurname()const { return surname; };
	GENDER GetGender()const { return gender; };
	Date GetDate()const { return birth; };
	char * GetAdress()const { return ofStudent; };
	int * GetExamsMarks() const { return Exams; };
	int * GetCoursesMarks() const { return Courses; };
	int * GetModulsMarks() const { return Moduls; };

	void changeExam(int Mark, int number);
	void changeCourse(int Mark, int number);
	void changeModule(int Mark, int number);

	void operator=(const Student& other);

	~Student();
};

