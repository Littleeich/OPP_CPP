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

	void Enqueue(int number, int pr = 0)
	{
		l.AddTail(number, pr);
		count++;
	}

	int Dequeue()
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
	system("title ���������������� ������� Queue (���������� ������)");
	srand(time(0));
	rand();

	Queue q(25);

	for (int i = 0; i < 5; i++)
		q.Enqueue(rand() % 90 + 10);

	q.Show();

	q.Dequeue();

	q.Show();

	for (int i = 0; i < 2; i++)
		q.Enqueue(rand() % 90 + 10, i + 1);

	q.Show();

	for (int i = 0; i < 3; i++)
		q.Dequeue();

	q.Show();
}
