#include <iostream>
#include <ctime>
using namespace std;

class Stack
{
	int SIZE = 10; 
	const int EMPTY = 0;
	int * mass = new int[SIZE];
	int top; // индекс вершины стека

public:
	Stack() : top(EMPTY) {}
	~Stack() { delete[] mass; }

	int GetTop()const { return top; }

	void Clear()
	{
		top = EMPTY;
	}

	bool IsEmpty()
	{
		return top == EMPTY;
	}

	bool IsFull()
	{
		return top == SIZE;
	}

	int GetCount()
	{
		return top;
	}

	void Push(int digit)
	{
		for (int i = 0; i < top; i++)
			if (mass[i] == digit)
				return;

		if (IsFull())
		{
			int * temp = new int[SIZE * 2];
			for (int i = 0; i < SIZE; i++)
				temp[i] = mass[i];
			delete[] mass;
			this->mass = temp;
			SIZE *= 2;
		}
		mass[top++] = digit;
	}

	int Pop()
	{
		if (!IsEmpty())
			return mass[--top];
		else throw "Stack is empty!";
	}

	int Peek()
	{
		return mass[top - 1];
	}

	bool Contains(int number)
	{
		for (int i = 0; i < top; i++)
			if (mass[i] == number)
				return true;
		return false;
	}
};

void main()
{
	system("title ѕользовательский адаптер Stack (статический массив)");
	srand(time(0));
	rand();

	Stack st;

	while (st.IsFull() == false)
		st.Push(rand() % 90 + 10);

	while (st.GetTop() < 18)
		st.Push(rand() % 90 + 10);

	cout << st.Peek() << endl;
	cout << boolalpha << st.Contains(55) << endl;

	while (st.IsEmpty() == false)
		cout << st.Pop() << "  ";

	cout << "\n\n";
}