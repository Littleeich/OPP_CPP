#include "List.h"
using namespace std;


class Queue
{
	List l;
	int max_count;
	int count = 0;

public:
	Queue(int m)
	{
		max_count = m;
	}

	~Queue()
	{
		l.DelAll();
	}

	void Clear()
	{
		l.DelAll();
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

	void EnqueueT(int number, int pr = 0)
	{
		l.AddTail(number, pr);
		count++;
	}

	void EnqueueH(int number, int pr = 0)
	{
		l.AddHead(number, pr);
		count++;
	}

	int DequeueH()
	{
		if (!IsEmpty())
		{
			int first = l.GetElem(1)->data;
			l.Del(1);
			count--;
			return first;
		}
		else throw "Queue is empty!";
	}

	int DequeueT()
	{
		if (!IsEmpty())
		{
			int first = l.GetElem(count)->data;
			l.Del(count);
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
			cout << l.GetElem(i + 1)->data << "  ";
		cout << "\n";
		cout << "-----------------------------------------------------\n";
	}
};

void main()
{
	system("title Пользовательский адаптер Queue (двусвязный список)");
	srand(time(0));
	rand();

	Queue q(25);

	for (int i = 0; i < 5; i++)
		q.EnqueueT(rand() % 90 + 10);

	q.Show();

	q.DequeueT();

	q.Show();

	for (int i = 0; i < 2; i++)
		q.EnqueueH(rand() % 90 + 10, i + 1);

	q.Show();

	for (int i = 0; i < 3; i++)
		q.DequeueH();

	q.Show();
}
