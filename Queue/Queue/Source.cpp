#include "List.h"
#include <ctime>
#include <iostream>
using namespace std;

class Pair
{
public:
	int num;
	int prior;

	Pair(int num, int prior = 0) : num(num), prior(prior) {}
	Pair() : Pair(0, 0) {}
};

ostream& operator<<(ostream& os, Pair& p)
{
	os << p.num;
	return os;
}

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

			DList<Pair>::DListItem<Pair> * temp = new DList<Pair>::DListItem<Pair>();
			temp = l.tail;
			if (l.count > 1)
				for (int i = 0; i < l.count; i++)
					if (temp->prev != nullptr && (temp->item.prior > temp->prev->item.prior))
					{
						swap(temp->item, temp->prev->item);
						temp = temp->prev;
					}
					else
						return;
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

	Queue<Pair> q(25);

	for (int i = 0; i < 5; i++)
		q.Enqueue((i * 3, i));

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
