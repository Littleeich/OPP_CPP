#include <iostream>
using namespace std;

typedef unsigned int uint;

template <class T>
struct DListItem
{
	T item;
	DListItem *next;
	DListItem *prev;
};

template <class T>
class DList
{
protected:
	DListItem<T> *head;
	DListItem<T> *tail;
	uint count;
public:
	DList();
	DList(const DList& l);
	~DList() { Clear(); }

	void Clear();

	DList& operator=(const DList<T>& l);

	uint GetCount() const { return count; }
	bool IsEmpty() const { return count == 0; }

	T& operator[](uint index);

	void AddHead(T& item);
	void AddTail(T& item);
	void Remove(uint index);
};

template <class T>
DList<T>::DList()
{
	head = tail = 0;
	count = 0;
}

template <class T>
DList<T>::DList(const DList<T>& l)
{
	head = tail = 0;
	count = 0;

	DListItem<T> *temp = l.head;
	while (temp != 0)
	{
		AddTail(temp->item);
		temp = temp->next;
	}
}

template <class T>
void DList<T>::Clear()
{
	while (count)
		Remove(0);
}

template <class T>
DList<T>& DList<T>::operator=(const DList<T> & l)
{
	if (this == &l) return *this;

	Clear();

	DListItem<T> *temp = l.head;
	while (temp != 0)
	{
		AddTail(temp->item);
		temp = temp->next;
	}

	return *this;
}

template <class T>
T& DList<T>::operator[](uint index)
{
	if (index >= count)
		return head->item;

	DListItem<T> *temp = head;

	int i = 0;
	while (i++ < index)
		temp = temp->next;

	return temp->item;
}

template <class T>
void DList<T>::AddHead(T& item)
{
	DListItem<T> *temp = new DListItem<T>;
	temp->prev = 0;
	temp->item = item;
	temp->next = head;

	if (head)
		head->prev = temp;

	if (!count)
		head = tail = temp;
	else
		head = temp;

	count++;
}

template <class T>
void DList<T>::AddTail(T& item)
{
	DListItem<T> *temp = new DListItem<T>;
	temp->next = 0;
	temp->item = item;
	temp->prev = tail;

	if (tail)
		tail->next = temp;

	if (!count)
		head = tail = temp;
	else
		tail = temp;

	count++;
}

template <class T>
void DList<T>::Remove(uint index)
{
	if (index >= count)
		return;

	DListItem<T> *delitem = head;

	int i = 0;
	while (i < index)
	{
		delitem = delitem->next;
		i++;
	}

	DListItem<T> *prevdelitem = delitem->prev;
	DListItem<T> *nextdelitem = delitem->next;

	if (prevdelitem != 0 && count != 0)
		prevdelitem->next = nextdelitem;

	if (nextdelitem != 0 && count != 0)
		nextdelitem->prev = prevdelitem;

	if (index == 0)
		head = nextdelitem;
	if (index == count - 1)
		tail = prevdelitem;

	delete delitem;

	count--;
}
