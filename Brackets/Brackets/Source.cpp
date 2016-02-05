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

bool checkBrackets(char * text)
{
	Stack<char> st;
	int size = strlen(text);
	for (int i = 0; i < size; i++)
		if (text[i] == '(' || text[i] == '{' || text[i] == '[' || text[i] == '<')
			st.Push(text[i]);
		else if (text[i] == ')' || text[i] == '}' || text[i] == ']' || text[i] == '>')
		{
			if (st.IsEmpty())
				return false;

			if (((char)st.Peek() == '(' && text[i] == ')') || 
				((char)st.Peek() == '{' && text[i] == '}') || 
				((char)st.Peek() == '[' && text[i] == ']') || 
				((char)st.Peek() == '<' && text[i] == '>'))
			{
				st.Pop();
			}
			else return false;
		}

	if (st.IsEmpty())
		return true;
	else
		return false;
}

void main()
{
	//system("title Проверка скобок");
	setlocale(0, "ru");
	srand(time(0));
	rand();

	char * viraz = new char[];
	cout << "ВВедите Ваше выражение: ";
	cin >> viraz;
	if (checkBrackets(viraz))
		cout << "Всё правильно!\n";
	else
		cout << "Где то ошибочка!\n";
}