#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class Stack
{
	int SIZE = 10;
	const int EMPTY = 0;
	T * mass = new T[SIZE];
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

	void Push(T digit)
	{
		if (IsFull())
		{
			T * temp = new T[SIZE * 2];
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

	bool Contains(T number)
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

	Stack<char> st;

	while (st.IsFull() == false)
		st.Push(rand() % 90 + 10);

	st.Push('k');

	while (st.GetTop() < 18)
		st.Push(rand() % 90 + 10);

	cout << st.Peek() << endl;
	cout << boolalpha << st.Contains('k') << endl;

	while (st.IsEmpty() == false)
		cout << st.Pop() << "  ";

	cout << "\n\n";
}