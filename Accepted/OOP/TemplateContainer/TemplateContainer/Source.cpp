#include <iostream>
#include "TempCont.h"

using namespace std;

void main()
{
	srand(time(0));
	MyVector<int> a(20);

	for (int i = 0; i < 10; i++)
	{
		a.Add(rand() % 20 + 1);
	}
	a.Print();
	a.Remove(8);
	a.Print();

	SingleLinkedList<int> b;
	for (int i = 0; i < 20; i++)
	{
		b.Add(rand() % 10 + 1);
	}
	b.Print();
	cout << boolalpha << b.Search(2) << endl;

	BinaryTree<int> tr;
	tr.Add(500);
	tr.Add(450);
	tr.Print();
	cout << boolalpha << tr.Search(450) << endl;
	tr.Remove();
	cout << boolalpha << tr.Search(450) << endl;

}

