#include <iostream>
#include "List.h"
using namespace std;


void main()
{
	List L;
	L.AddHead(1);

	L.AddTail(2);

	L.AddHead(3);

	L.AddTail(4);

	L.AddHead(5);

	L.Print();

	L.Insert();

	L.Print();

	L.Print(2);

	L.Print(8);

	List T;

	T = L;

	T.Print();

	List Sum = -L + T;

	Sum.Print();

	int a[10] = { 8, 6, 7, 4 };
	Sum.AddTailRange(a, 10);
	Sum.Print();
	cout << boolalpha << Sum.Contains(70) << endl;
	cout << Sum << endl;
	Sum[2].data = 500;
	cout << Sum << endl;
	cout << Sum.GetElementAt(5)->data << endl;
	List Sum2 = Sum;
	cout << boolalpha << Sum2.Equals(Sum) << endl;
	Sum[1].data = 500;
	cout << boolalpha << Sum2.Equals(Sum) << endl;
	cout << "Index of 3 is: " << Sum.IndexOf(3) << endl;
	cout << "Last index of 3 is: " << Sum.LastIndexOf(3) << endl;
	Sum.InsertRange(a, 5, 1);
	cout << Sum << endl;
	Sum.Remove(5);
	Sum.RemoveAll(500);
	Sum.RemoveAll(0);
	cout << Sum << endl;
	cout << Sum.GetLength() << endl;
	Sum.Revers();
	cout << Sum << endl;

	int * b = Sum.ToArray();
	for (int i = 0; i < Sum.GetLength(); i++)
		cout << b[i] << "  ";
	cout << endl;
	delete[] b;

	Sum.Sort();
	cout << Sum << endl;
}