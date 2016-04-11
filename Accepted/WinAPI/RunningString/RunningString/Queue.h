#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

class AnnularQueue
{
	TCHAR* ar;
	int max_count;
	int count;

public:
	AnnularQueue(int m)
	{
		max_count = m;
		ar = new TCHAR[max_count];
		count = 0;
	}

	AnnularQueue(TCHAR _ar[], int size)
	{
		ar = new TCHAR[size];
		for (int i = 0; i < size - 1; i++)
			ar[i] = _ar[i];
		ar[size - 1] = '\0';
		max_count = size - 1;
		count = size - 1;
	}

	const TCHAR* const GetChar() const { return ar; }

	~AnnularQueue()
	{
		delete[]ar;
	}

	void Clear()
	{
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
		if (!IsFull())
			ar[count++] = number;
	}

	void Dequeue()
	{
		if (!IsEmpty())
		{
			TCHAR first = ar[0];
			for (int i = 1; i < count - 1; i++) ar[i - 1] = ar[i];
			ar[count - 1 - 1] = first;
		}
	}

	void Show()
	{
		cout << "-----------------------------------------------------\n";
		for (int i = 0; i < count; i++)
			cout << ar[i] << "  ";
		cout << "\n";
		cout << "-----------------------------------------------------\n";
	}
};