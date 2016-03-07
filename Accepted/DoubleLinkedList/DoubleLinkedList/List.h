#pragma once
#include <iostream>
using namespace std;

struct Elem
{
	int data;
	Elem* next;
	Elem* prev;
};

class List
{
	Elem *Head, *Tail;
	int length;
public:
	List();
	List(const List&);
	~List();
	int GetLength();
	Elem * GetHead()const { return Head; }
	void AddTail(int n);
	void AddHead(int n);
	void AddTailRange(int n[], int length);
	void AddHeadRange(int n[], int length);
	void Insert(int pos = 0, int number = 10);
	void InsertRange(int a[], int size, int pos = 0);
	void Del(int pos = 0);
	void DelAll();
	void Print();
	void Print(int pos);
	Elem* GetElem(int);

	List& operator = (const List&);
	List operator + (const List&);

	bool operator == (const List&);
	bool operator != (const List&);
	
	friend ostream& operator<<(ostream& os, const List&);
	Elem& operator[] (int num);
	Elem* GetElementAt(int index);
	bool Equals(const List& other);
	int IndexOf(int num);
	int LastIndexOf(int num);

	void Remove(int number);
	void RemoveAll(int number);
	void Revers();
	int * ToArray();
	void Sort();

	List operator - (); // переворачивание

	bool Contains(int num);
};
