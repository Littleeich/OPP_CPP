#include "List.h"

template <typename T>
List<T>::List()
{
	Head = Tail = nullptr;
	length = 0;
}

template <typename T>
void List<T>::SingleTailSort()
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

template <typename T>
void List<T>::SingleHeadSort()
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

template <typename T>
void List<T>::AddHead(T n, int pr)
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

template <typename T>
void List<T>::AddTail(T n, int pr)
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

template <typename T>
void List<T>::Del(int pos)
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

template <typename T>
void List<T>::DelAll()
{
	while (length != 0) Del(1);
}

template <typename T>
List<T>::~List()
{
	DelAll();
}

template <typename T>
int List<T>::GetLength()
{
	return length;
}

template <typename T>
List<T>::Elem<T>*  List<T>::GetElem(int pos)
{
	if (pos < 1 || pos > length)
		throw "Incorrect position";

	Elem<T> *temp = Head;

	int i = 1;
	while (i < pos && temp != nullptr)
	{
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) return nullptr; // ничего не найдено :(
	return temp;
}