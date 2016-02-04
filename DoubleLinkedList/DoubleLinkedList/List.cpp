#include "List.h"
#include <iostream>
using namespace std;


List::List()
{
	Head = Tail = NULL;
	length = 0;
}

void List::AddHead(int n)
{
	Elem * temp = new Elem();
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;

	// если в списке уже есть элементы
	if (Head != 0) Head->prev = temp;

	// если элементов не было
	if (length == 0) Head = Tail = temp;
	else Head = temp;

	length++;
}

void List::AddHeadRange(int n[], int length)
{
	for (int i = 0; i < length; i++)
		AddHead(n[length - 1 - i]);
}

void List::AddTail(int n)
{
	Elem * temp = new Elem();
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;

	// если в списке уже есть элементы
	if (Tail != 0) Tail->next = temp;

	// если элементов не было
	if (length == 0) Head = Tail = temp;
	else Tail = temp;

	length++;
}

void List::AddTailRange(int n[], int length)
{
	for (int i = 0; i < length; i++)
		AddTail(n[i]);
}

// конструктор копирования
List::List(const List & L)
{
	Head = Tail = NULL;
	length = 0;

	// голова списка, который копируется
	Elem* temp = L.Head;

	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

void List::Insert(int pos, int number)
{
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}

	if (pos < 1 || pos > length + 1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	if (pos == length + 1)
	{
		AddTail(number);
		return;
	}
	else if (pos == 1)
	{
		AddHead(number);
		return;
	}

	int i = 1;
	Elem * Ins = Head;
	while (i < pos)
	{
		Ins = Ins->next;
		i++;
	}

	Elem * PrevIns = Ins->prev;

	Elem * temp = new Elem();

	temp->data = number;

	// настройка связей
	if (PrevIns != 0 && length != 1)
		PrevIns->next = temp;

	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	length++;
}

void List::InsertRange(int a[], int size, int pos)
{
	for (int i = 0; i < size; i++)
	{
		Insert(pos, a[i]);
		pos++;
	}
}

void List::Del(int pos)
{
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < 1 || pos > length)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	int i = 1;
	Elem * Del = Head;
	while (i < pos)
	{
		Del = Del->next;
		i++;
	}

	Elem * PrevDel = Del->prev;
	Elem * AfterDel = Del->next;

	// если удаляется не голова
	if (PrevDel != 0 && length != 1)
		PrevDel->next = AfterDel;
	// если удаляется не хвост
	if (AfterDel != 0 && length != 1)
		AfterDel->prev = PrevDel;

	// удаление крайних элементов
	if (pos == 1) Head = AfterDel;
	if (pos == length) Tail = PrevDel;

	delete Del;

	length--;
}

void List::DelAll()
{
	while (length != 0) Del(1);
}

List::~List()
{
	DelAll();
}

void List::Print(int pos)
{
	if (pos < 1 || pos > length)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	Elem * temp;

	if (pos <= length / 2)
	{
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		temp = Tail;
		int i = 1;
		while (i <= length - pos)
		{
			temp = temp->prev;
			i++;
		}
	}

	cout << pos << " element: ";
	cout << temp->data << endl;
}

void List::Print()
{
	if (length != 0)
	{
		Elem * temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}

int List::GetLength()
{
	return length;
}

Elem * List::GetElem(int pos)
{
	Elem *temp = Head;

	if (pos < 1 || pos > length)
	{
		cout << "Incorrect position !!!\n";
		return 0;
	}

	int i = 1;
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}

	if (temp == 0) return 0;
	else return temp;
}

List & List::operator = (const List & L)
{
	// проверка на присвоение элемента самому себе
	if (this == &L) return *this;

	// удаление старого списка
	this->~List(); // DelAll();

	Elem* temp = L.Head;

	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}

	return *this;
}

List List::operator + (const List& L)
{
	List Result = *this;

	Elem * temp = L.Head;

	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}

	return Result;
}

bool List::operator == (const List& L)
{
	// сравнение по количеству
	if (length != L.length)
		return false;

	// сравнение по содержанию
	Elem *t1, *t2;

	t1 = Head;
	t2 = L.Head;

	while (t1 != 0)
	{
		// Сверяем данные, которые
		// находятся на одинаковых позициях
		if (t1->data != t2->data)
			return false;

		t1 = t1->next;
		t2 = t2->next;
	}

	return true;
}

bool List::operator != (const List& L)
{
	return !(*this == L);
}

ostream& operator<<(ostream& os, const List& L)
{
	Elem * temp;
	temp = L.GetHead();
	os << "( ";
	while (temp)
	{
		os << (temp->data) << " ";
		temp = temp->next;
	}
	os << ")" << endl;
	return os;
}

Elem& List::operator[](int num)
{
	while (num >= length)
	{
		cout << "Please, choose index from 0 to " << length - 1 << endl;
		cout << "Index: ";
		cin >> num;
	}
	int i = 0;
	Elem* temp = Head;
	while (i < num)
	{
		temp = temp->next;
		i++;
	}
	return *temp;
}

Elem* List::GetElementAt(int index)
{
	if (index >= length && index < 0)
		return nullptr;
	int i = 0;
	Elem * temp = Head;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

bool List::Equals(const List& other)
{
	if (length != other.length)
		return false;
	else if (length = 0)
		return true;
	Elem * temp = Head, * temp2 = other.Head;
	for (int i = 0; i < length; i++)
	{
		if (temp->data != temp2->data)
			return false;
		temp = temp->next;
		temp2 = temp2->next;
	}
	return true;
}

int List::IndexOf(int num)
{
	int index = 0, i = 0;
	Elem * temp = Head;
	while (temp)
	{
		if (temp->data == num)
		{
			index = i;
			return index;
		}
		i++;
		temp = temp->next;
	}
	return -1;
}

int List::LastIndexOf(int num)
{
	int index = -1, i = 0;
	Elem * temp = Head;
	while (temp)
	{
		if (temp->data == num)
		{
			index = i;
		}
		i++;
		temp = temp->next;
	}
	return index;
}

void List::Remove(int number)
{
	Elem * temp = Head;
	int i = 0;
	while (temp)
	{
		if (temp->data == number)
		{
			if (temp->prev == nullptr)
			{
				Head = temp->next;
				length--;
				return;
			}
			else
			{
				Del(i + 1);
				return;
			}
		}
		i++;
		temp = temp->next;
	}
}

void List::RemoveAll(int number)
{
	while (IndexOf(number) != -1)
		Remove(number);
}

// переворот
List List::operator - ()
{
	List Result;

	Elem * temp = Head;
	// копирование элементов списка, начиная с головного,
	// в Result путем добавления элементов в голову.
	// таким образом временный список Result будет содержать
	// все элементы в обратном порядке
	while (temp != 0)
	{
		Result.AddHead(temp->data);
		temp = temp->next;
	}

	return Result;
}

bool List::Contains(int num)
{
	Elem * Cont = Head;
	while (Cont)
	{
		if (Cont->data == num)
			return true;
		Cont = Cont->next;
	}
	return false;
}

void List::Revers()
{
	List temp;
	Elem * temp2 = Head;
	while (temp2)
	{
		temp.AddHead(temp2->data);
		temp2 = temp2->next;
	}
	DelAll();
	*this = temp;
}

int * List::ToArray()
{
	int * a = new int[length], i = 0;
	Elem * temp = Head;
	while (temp)
	{
		a[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return a;
}

void List::Sort()
{
	int*array = new int[length];
	Elem* temp = Head;
	for (int i = 0; i < length; i++)
	{
		array[i] = temp->data;
		temp = temp->next;
	}

	for (int j = length - 1; j>0; j--)
		for (int i = 0; i < j; i++)
			if (array[i]>array[i + 1])
				swap(array[i], array[i + 1]);

	List Result;
	Result.AddTailRange(array, length);
	
	this->~List();
	*this = Result;
	delete[]array;
}