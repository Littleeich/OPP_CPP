#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class List
{
public:

	struct Elem
	{
		int data;
		int priority;
		Elem* next;
		Elem* prev;
	};

private:
	Elem *Head, *Tail;
	int length;

public:
	List();
	~List();
	int GetLength();
	void AddTail(int n, int pr = 0);
	void AddHead(int n, int pr = 0);
	void SingleTailSort();
	void SingleHeadSort();
	void Del(int pos);
	void DelAll();
	Elem* GetElem(int);
};
