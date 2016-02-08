#pragma once
#include <iostream>
#include <time.h>
using namespace std;

template <typename T>
class List
{
public:
	template <typename T>
	struct Elem
	{
		T data;
		int priority;
		Elem* next;
		Elem* prev;
	};

private:
	Elem<T> *Head;
	Elem<T> *Tail;
	int length;

public:
	List();
	~List();
	int GetLength();
	void AddTail(T n, int pr = 0);
	void AddHead(T n, int pr = 0);
	void SingleTailSort();
	void SingleHeadSort();
	void Del(int pos);
	void DelAll();
	Elem<T>* GetElem(int pos);
};
