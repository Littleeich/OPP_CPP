#include <iostream>
#include "Date.h"

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

void main()
{
	Date a;
	Date b(31, 12, 1991);
	PrintDate(a);
	cout << endl;
	PrintDate(b);
	cout << endl;

	Date c;
	c = b + 4125;
	PrintDate(c);
	cout << endl;

	Date f = b;
	f += 4125;
	PrintDate(f);
	cout << endl;
	//ещё надо откорректировать данную процедуру
	Date e(17, 4, 2003);
	cout << b - e << endl;

	Date g = b;
	cout << (g -= e) << endl;

	PrintDate(b++);
	cout << endl;
	PrintDate(b);
	cout << endl;
	PrintDate(++b);
	cout << endl;
	PrintDate(b--);
	cout << endl;
	PrintDate(b);
	cout << endl;
	PrintDate(--b);
	cout << endl;
	
	/*Date today(25, 12, 2015);
	cout << today.DayOfWeek() << endl;*/

}