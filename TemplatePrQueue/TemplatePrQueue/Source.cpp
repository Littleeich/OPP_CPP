#include "List.h"
#include <ctime>
using namespace std;

template <class T>
class Queue
{
	DList<T> l;
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

	void Enqueue(T number)
	{
		l.AddTail(number);
		count++;
	}

	T Dequeue()
	{
		if (!IsEmpty())
		{
			T first = l[1];
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


void main()
{
	system("title Пользовательский адаптер Queue (двусвязный список)");
	srand(time(0));
	rand();

	Queue<double> q(25);

	for (int i = 0; i < 5; i++)
		q.Enqueue(rand() % 90 + 10);

	q.Show();

	q.Dequeue();

	q.Show();

	for (int i = 0; i < 2; i++)
		q.Enqueue(rand() % 90 + 10);

	q.Show();

	for (int i = 0; i < 3; i++)
		q.Dequeue();

	q.Show();
}
