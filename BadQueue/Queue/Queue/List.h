#pragma once
#include <iostream>
//#include "Queue.h"
using namespace std;

typedef unsigned int uint;

template <class T>
class DList
{
	template <class T>
	struct DListItem
	{
		T item;
		DListItem *next;
		DListItem *prev;
	};

private:
	DListItem<T> *head;
	DListItem<T> *tail;
	uint count;
public:
	DList();
	DList(const DList& l);

	void Clear();
	~DList() { Clear(); }

	DList& operator=(const DList<T>& l);

	uint GetCount() const { return count; }
	bool IsEmpty() const { return count == 0; }

	T& operator[](uint index);

	void AddHead(const T& item);
	void AddTail(const T& item);
	void Remove(uint index);
};
