#include <iostream>
#include "Student.h"

using namespace std;

void PrintDate(Date date)
{
	printf("%02d", date.GetDay());
	if (date.GetMonth() == 1)
		printf(" JAN ");
	else if (date.GetMonth() == 2)
		printf(" FEB ");
	else if (date.GetMonth() == 3)
		printf(" MAR ");
	else if (date.GetMonth() == 4)
		printf(" APR ");
	else if (date.GetMonth() == 5)
		printf(" MAY ");
	else if (date.GetMonth() == 6)
		printf(" JUN ");
	else if (date.GetMonth() == 7)
		printf(" JUL ");
	else if (date.GetMonth() == 8)
		printf(" AUG ");
	else if (date.GetMonth() == 9)
		printf(" SEP ");
	else if (date.GetMonth() == 10)
		printf(" OCT ");
	else if (date.GetMonth() == 11)
		printf(" NOV ");
	else
		printf(" DEC ");
	printf("%04d", date.GetYear());
}

void ShowMarks(int a[], int size = 10)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] < 0 || a[i] > 100)
			a[i] = 0;
		cout << i + 1 << ") " << a[i] << "  ";
	}
	cout << endl;
}

void ShowStudent(Student &stud, bool Marks = false)
{
	cout << "Name: " << stud.GetName() << endl <<
		"Second name: " << stud.GetSecond() << endl <<
		"Surname: " << stud.GetSurname() << endl <<
		"Gender: ";
	if (stud.GetGender() == GENDER::MALE)
		cout << "MALE";
	else
		cout << "FEMALE";
	cout << endl << "Date of birth: ";
	PrintDate(stud.GetDate());
	cout << "Adress: " << stud.GetAdress() << endl;

	if (Marks)
	{
		cout << "Marks: \nExams: ";
		ShowMarks(stud.GetExamsMarks());
		cout << "Cources: ";
		ShowMarks(stud.GetCoursesMarks());
		cout << "Moduls: ";
		ShowMarks(stud.GetModulsMarks());
	}
	cout << endl << endl;
}

void main()
{
	Student a;
	ShowStudent(a);
	char * change = new char[];
	change = "Syao";
	a.SetName(change);
	a.SetSecond(change);
	a.SetSurname(change);
	ShowStudent(a);
	//delete[] change;
	Student b = a;
	ShowStudent(b, true);

	b.changeExam(70, 4);
	b.changeCourse(120, 4);
	b.changeModule(100, 3);
	b.changeCourse(30, 16);
	ShowStudent(b, true);

	Student Kolya;
	Kolya = b;
	ShowStudent(Kolya, true);
}