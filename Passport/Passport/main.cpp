#include <iostream>
#include <string>
#include "Date.h"
#include "Passport.h"
#include "Visa.h"
#include "Visits.h"

using namespace std;

void main()
{
	setlocale(0, "ru");
	Passport a;
	a.Show();

	cout << endl << endl;

	Passport b("Иван", "Абрамов", Date(1, 3, 1995), Date(11, 9, 2003), Date(11, 9, 2023), "Centralniy RO m. Kiev");
	b.Show();

	b.SetDateEnd(11, 9, 2013);
	b.SetName("Пётр");
	cout << endl;
	b.Show();
}