#include "List.h"


List::List()
{
	Head = Tail = nullptr;
	length = 0;
}

void List::SingleTailSort()
{
	Elem * temp = new Elem();
	temp = Tail;
	if (length > 1)
		for (int i = 0; i < length; i++)
			if (temp->prev != nullptr && (temp->priority > temp->prev->priority))
		{
			swap(temp->data, temp->prev->data);
			swap(temp->priority, temp->prev->priority);
			temp = temp->prev;
		}
			else
				return;
}

void List::SingleHeadSort()
{
	Elem * temp = new Elem();
	temp = Head;
	if (length > 1)
		for (int i = 0; i < length; i++)
			if (temp->next != nullptr && (temp->priority > temp->next->priority))
			{
				swap(temp->data, temp->next->data);
				swap(temp->priority, temp->next->priority);
				temp = temp->next;
			}
			else
				return;
}

void List::AddHead(int n, int pr)
{
	Elem * temp = new Elem();
	temp->prev = nullptr;
	temp->data = n;
	temp->priority = pr;
	temp->next = Head;

	// если в списке уже есть элементы
	if (Head != nullptr)
	{
		Head->prev = temp;
	}

	// если элементов не было
	if (length == 0)
	{
		Head = Tail = temp;
	}
	else Head = temp;

	length++;
	SingleHeadSort();
}

void List::AddTail(int n, int pr)
{
	Elem * temp = new Elem();
	temp->next = nullptr;
	temp->data = n;
	temp->priority = pr;
	temp->prev = Tail;

	// если в списке уже есть элементы
	if (Tail != nullptr)
	{
		Tail->next = temp;
	}

	// если элементов не было
	if (length == 0)
	{
		Head = Tail = temp;
	}
	else Tail = temp;

	length++;
	SingleTailSort();
}

void List::Del(int pos)
{
	if (pos < 1 || pos > length)
		throw "Incorrect position";

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
	if (PrevDel != nullptr && length != 1)
		PrevDel->next = AfterDel;
	// если удаляется не хвост
	if (AfterDel != nullptr && length != 1)
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

int List::GetLength()
{
	return length;
}

List::Elem* List::GetElem(int pos)
{
	if (pos < 1 || pos > length)
		throw "Incorrect position";

	Elem *temp = Head;

	int i = 1;
	while (i < pos && temp != nullptr)
	{
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) return nullptr; // ничего не найдено :(
	return temp;
}