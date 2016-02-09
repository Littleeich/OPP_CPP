#pragma once
#include "List.h"

using namespace std;

class Queue
{
	DList<int> l;
	int max_count;
	int count = 0;

public:
	Queue(int m)
	{
		max_count = m;
	}

	~Queue()
	{
		l.~DList();
	}

	void Clear()
	{
		l.~DList();
		count = 0;
	}

	bool IsEmpty()
	{
		return count == 0;
	}

	bool IsFull()
	{
		return count == max_count;
	}

	int GetCount()
	{
		return count;
	}

	void Enqueue(int number)
	{
		l.AddTail(number);
		count++;
	}

	int Dequeue()
	{
		if (!IsEmpty())
		{
			int first = l[1];
			l.Remove(1);
			count--;
			return first;
		}
		else throw "Queue is empty!";
	}

	void Show()
	{
		//l.Print();
		cout << "-----------------------------------------------------\n";
		for (int i = 0; i < count; i++)
			cout << l[i + 1] << "  ";
		cout << "\n";
		cout << "-----------------------------------------------------\n";
	}
};
