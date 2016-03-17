#include <iostream>
#include "Time.h"
using namespace std;

void show_time(Time t)
{
	printf("%02d", t.GetHours());
	printf(":");
	printf("%02d", t.GetMinutes());
	printf(":");
	printf("%02d", t.GetSeconds());
}

void main()
{
	Time a;
	Time b(11, 20, 25);
	Time c (22, 50, 59);

	show_time(a);
	cout << endl;
	show_time(b);
	cout << endl;
	show_time(c);
	cout << endl;

	Time d = b + c;
	show_time(d);
	cout << endl;
	
	Time e(1, 2, 3);
	d = d - e;
	show_time(d);
	cout << endl;

	Time f(2, 2, 2);
	d += f;
	show_time(d);
	cout << endl;

	Time g(1, 1, 1);
	d -= g;
	show_time(d);
	cout << endl;

	if (d != g)
		cout << "\n!= is working!";
	else
		cout << "Error!";

	if (a == (g - g))
		cout << "\n== is working!\n";
	else
		cout << "Error!";

	if (f > g)
		cout << "> is working!\n";

	if (g < f)
		cout << "< is working!\n";

	d = g--;
	show_time(d);
	cout << endl;

	show_time(g);
	cout << endl;
	
}