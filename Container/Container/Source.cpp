#include <iostream>
#include "Container.h"

using namespace std;

void main()
{
	srand(time(0));
	MyVector a(20);
	for (int i = 0; i < 10; i++)
	{
		a.Add(rand() % 20 + 1);
	}
	a.Print();
	a.Remove(8);
	a.Print();
}