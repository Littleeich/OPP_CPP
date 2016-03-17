#pragma once
#include <ctime>
#include <iostream>

using namespace std;

class Container
{
protected:
	unsigned int count;

public:
	/*Container(unsigned int count);
	Container() :Container(0){}
	~Container();*/
	
	unsigned int GetCount() const{ return count; }

	void Add(int number)
	{
		cout << "Add " << number << endl;
	}
	void Remove(int number)
	{
		cout << "Remove " << number << endl;
	}
	void Print()const
	{
		cout << "Print everything\n";
	}
	bool Search(int number)
	{
		cout << "Search " << number << endl;
	}
};

class MyVector: public Container
{
	int* data;
	unsigned int capacity;
	static double modificator;

public:
	// конструкторы
	MyVector(int* data, unsigned int capacity, unsigned int count);
	MyVector() :MyVector(nullptr, 10, 0){}
	MyVector(unsigned int capacity) :MyVector(nullptr, capacity, 0){}
	MyVector(const MyVector& original) : MyVector(original.data, original.capacity, original.count){}

	void Clear();

	~MyVector() { Clear(); } // деструктор

	MyVector& operator=(const MyVector& v); // присваивание
	bool operator==(const MyVector& other);
	void operator()(unsigned int capacity);
	void operator+=(const MyVector& other);
	MyVector operator+(const MyVector& other);

	// работа с размером вектора
	unsigned int GetCount() const { return count; }
	unsigned int GetCapacity() const { return capacity; }
	bool IsEmpty() const { return count == 0; }
	bool operator!() const { return IsEmpty(); }

	const int& operator[](unsigned int index) const; // доступ к элементам (просмотр!)

	// добавление и удаление элементов
	void Add(int number);
	void Insert(unsigned int index, int number);
	void Remove(int index);
	void RemoveEnd();
	void Resize(unsigned int capacity);

	void Print() const;
	short IndexOf(int number);
	short LastIndexOf(int number);
	void Revers();
	void Sort();
	void Shuffle();
	bool Search(int number);

	friend ostream& operator<<(ostream& os, const MyVector& obj);
	friend istream& operator>>(istream& is, MyVector& obj);
};

double MyVector::modificator = 3;

MyVector::MyVector(int array[], unsigned int arrayCapacity, unsigned int arraySize)
{
	if (arraySize == 0)
	{
		data = nullptr;
		capacity = arrayCapacity;
	}
	else
	{
		if (arrayCapacity <= arraySize)
			capacity = unsigned int(arraySize * modificator);
		else
			capacity = arrayCapacity;
		// выделяем память и копируем элементы
		data = new int[capacity];
		for (unsigned int i = 0; i < arraySize; i++)
			data[i] = array[i];
	}
	count = arraySize;
}

void MyVector::Resize(unsigned int capacity)
{
	if (capacity == this->capacity) return;
	else if (capacity > count)
	{
		int * temp = new int[capacity];
		for (unsigned int i = 0; i < count; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
	}
	else
	{
		int * temp = new int[capacity];
		for (unsigned int i = 0; i < capacity; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		count = capacity;
	}
	this->capacity = capacity;
}

void MyVector::Clear()
{
	if (count)
	{
		delete[] data;
		data = nullptr;
		count = 0;
		capacity = 80;
	}
}

MyVector& MyVector::operator=(const MyVector& original)
{
	// проверка на самоприсваивание
	if (this == &original) return *this;

	if (original.count == 0)
	{
		delete[] data;
		data = nullptr;
	}
	else
	{
		// выделяем память и копируем элементы
		int* temp = new int[original.capacity];
		for (unsigned int i = 0; i < original.count; i++)
			temp[i] = original.data[i];
		// удаляем старый массив
		delete[] data;
		data = temp;
	}
	count = original.count;
	capacity = original.capacity;

	return *this;
}

const int& MyVector::operator[](unsigned int index) const
{
	if (index >= count) throw "Incorrect index!"; // генерация исключения!
	return data[index];
}

void MyVector::operator()(unsigned int capacity)
{
	Resize(capacity);
}

void MyVector::Add(int number)
{
	if (count == 0)
	{
		data = new int[capacity];
		data[0] = number;
	}
	else
	{
		if (count + 1 <= capacity)
			data[count] = number;
		else
		{
			// выделяем память и копируем элементы
			int* temp = new int[int(capacity * modificator)];
			for (unsigned int i = 0; i < count; i++)
				temp[i] = data[i];
			// добавляем новый элемент
			temp[count] = number;
			// удаляем старый массив
			delete[] data;
			data = temp;
			capacity = unsigned int(capacity * modificator);
		}
	}
	count++;
}

void MyVector::Insert(unsigned int index, int number)
{
	if (index > count) index = count;

	if (count == 0)
	{
		data = new int;
		*data = number;
	}
	else
	{
		double arrayIndex;
		if (count + 1 <= capacity)
			arrayIndex = 1;
		else
		{
			arrayIndex = modificator;
		}
		// выделяем память и копируем элементы
		int* temp = new int[int(capacity * arrayIndex)];
		capacity = unsigned int(capacity * modificator);
		for (unsigned int i = 0; i < count; i++)
			if (i < index) temp[i] = data[i];
			else if (i >= index) temp[i + 1] = data[i];
			// вставляем новый элемент
			temp[index] = number;
			// удаляем старый массив
			delete[] data;
			data = temp;
			capacity = unsigned int(capacity * arrayIndex);
	}
	count++;
}

void MyVector::Remove(int index)
{
	if (index >= count) throw "Incorrect index!";

	if (count == 1)
	{
		delete[] data;
		data = nullptr;
	}
	else
	{
		// выделяем память и копируем элементы
		int *temp = new int[capacity];
		for (unsigned int i = 0; i < count; i++)
			if (i < index) temp[i] = data[i];
			else if (i > index) temp[i - 1] = data[i];
			// удаляем старый массив
			delete[] data;
			data = temp;
	}
	count--;
}

void MyVector::RemoveEnd()
{
	if (count == 0) throw "Empty array!\n";

	if (count == 1)
	{
		delete[] data;
		data = nullptr;
	}
	// нам нет смысла проводить операции по удалению последнего числа в массиве, мы просто перекрыли к нему доступ
	count--;
}

void MyVector::Print() const
{
	if (IsEmpty()) cout << "Vector is empty!";
	else
	{
		for (unsigned int i = 0; i < count; i++)
		{
			cout << data[i];
			if (i < count - 1) cout << ",  ";
			else cout << ".";
		}
	}
	cout << "\n\n";
}

short MyVector::IndexOf(int number)
{
	for (short i = 0; i < (short)count; i++)
		if (data[i] == number)
			return i;
	return -1;
}

short MyVector::LastIndexOf(int number)
{
	short index = -1;
	for (short i = 0; i < (short)count; i++)
		if (data[i] == number)
			index = i;
	return index;
}

void MyVector::Revers()
{
	int * temp = new int[capacity];
	for (unsigned int i = 0; i < count; i++)
		temp[i] = data[count - 1 - i];
	delete[] data;
	data = temp;
}

void MyVector::Sort()
{
	for (int j = count - 1; j > 0; j--)
		for (int i = 0; i < j; i++)
			if (data[i] > data[i + 1])
				swap(data[i], data[i + 1]);
}

void MyVector::Shuffle()
{
	int count2 = count;
	int * temp = new int[count2];
	for (int i = 0; i < count2; i++)
		temp[i] = data[i];

	for (int i = 0; i < count2; i++)
	{
		int randInt = rand() % count;
		temp[i] = data[randInt];
		Remove(randInt);
	}
	delete[] data;
	data = temp;
	count = count2;
}

bool MyVector::operator==(const MyVector& other)
{
	if (count != other.count)
		return false;
	for (unsigned int i = 0; i < count; i++)
	{
		if (data[i] != other.data[i])
			return false;
	}
	return true;
}

void MyVector::operator+=(const MyVector& other)
{
	if (count + other.count <= capacity)
	{
		for (unsigned int i = 0; i < other.count; i++)
			data[count + i] = other.data[i];
	}
	else
	{
		capacity += unsigned int(other.count * modificator);
		// выделяем память и копируем элементы
		int* temp = new int[int(capacity)];
		for (unsigned int i = 0; i < count; i++)
			temp[i] = data[i];
		// добавляем новый элемент
		for (unsigned int i = 0; i < other.count; i++)
			temp[count + i] = other.data[i];
		// удаляем старый массив
		delete[] data;
		data = temp;
	}
	count += other.count;
}

MyVector MyVector::operator+(const MyVector& other)
{
	MyVector sum;
	if (capacity > count + other.count)
		sum(capacity);
	else if (other.capacity > count + other.count)
		sum(other.capacity);
	else
		sum(unsigned int((count + other.count) * modificator));

	for (unsigned int i = 0; i < count; i++)
		sum.data[i] = data[i];
	for (unsigned int i = count; i < count + other.count; i++)
		sum.data[i] = other.data[i - count];

	sum.count = count + other.count;

	//или как вариант в начале можно было сделать так:
	/*sum += *this;
	sum += other;*/
	return sum;
}

bool MyVector::Search(int number)
{
	for (int i = 0; i < count; i++)
		if (data[i] == number)
			return true;
	return false;
}

ostream& operator<<(ostream& os, const MyVector& obj)
{
	cout << "My array of int: " << endl;
	for (int i = 0; i < obj.count - 1; i++)
		os << obj.data[i] << ",  ";
	os << obj.data[obj.count - 1] << '.' << endl;
	return os;
}

istream& operator>>(istream& is, MyVector& obj)
{
	cout << "Amount of numbers: ";
	is >> obj.count;
	if (obj.capacity < obj.count)
		obj.capacity = unsigned int(obj.count * MyVector::modificator);

	cout << "data: ";
	for (int i = 0; i < obj.count; i++)
		is >> obj.data[i];
	return is;
}

/*               Single linked list!!!!         */

class SingleLinkedList: public Container
{
public:
	struct Element
	{
		int data;
		Element* next;
	};

private:
	Element* head; // обязательное поле
	Element* tail; // необязательное поле

public:
	SingleLinkedList()
	{
		head = tail = nullptr;
		count = 0;
	}

	// добавляет число в конец списка (метод входит в стандартный интерфейс)
	void Add(int data)
	{
		Element* temp = new Element();
		temp->data = data;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		count++;
	}

	void Add_Head(int data)
	{
		Element* temp = new Element();
		temp->data = data;
		temp->next = temp;
		if (head == nullptr)
		{
			temp->next = nullptr;
			head = tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		count++;
	}
	// (метод не входит в стандартный интерфейс)
	void RemoveHead()
	{
		if (count != 0)
		{
			Element* temp = head;
			head = head->next;
			delete temp;
			count--;
		}
	}

	void Remove()
	{
		if (count != 0)
		{
			if (count == 1)
				head = tail = nullptr;
		}
	}
	// удаляет все элементы списка (метод входит в стандартный интерфейс)
	void Clear()
	{
		while (head != nullptr)
			RemoveHead();
	}

	// обязательный метод в С++
	~SingleLinkedList()
	{
		Clear();
	}

	// (метод не входит в стандартный интерфейс)
	void Print() const
	{
		Element* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n\n";
	}

	bool Search(int num)
	{
		Element* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == num)
			{
				return true;
			}
			else
				temp = temp->next;
		}
		return false;
	}
};

class BinaryTree: public Container
{
public:
	struct Node 
	{
		int value;

		Node* parent;
		Node* right;
		Node* left;

		void ShowNode()
		{
			cout << value << "\t";
		}
	};

	//////////////////////////

private:
	Node* root;
	// int count;

public:
	BinaryTree()
	{
		root = 0;
	}

	bool IsEmpty()
	{
		return root == 0;
	}

	~BinaryTree()
	{
		Remove();
	}

private:
	void ShowTree(Node* elem)
	{
		if (elem != 0)
		{
			ShowTree(elem->left);
			elem->ShowNode();
			ShowTree(elem->right);
		}
	}

public:
	void Print()
	{
		cout << "\n\n";
		ShowTree(root);
		cout << "\n\n";
	}

	Node* GetRoot()
	{
		return root;
	}

private:
	int GetCount(Node* elem, int count)
	{
		if (elem != 0)
		{
			count = GetCount(elem->left, count);
			count++;
			count = GetCount(elem->right, count);
		}
		return count;
	}

public:
	int GetCount()
	{
		int count = 0;
		count = GetCount(root, count);
		return count;
	}

private:
	void Clear(Node* elem)
	{
		if (elem != 0)
		{
			Clear(elem->left);
			Clear(elem->right);
			delete elem;
			elem = 0;
		}
	}

public:
	void Remove()
	{
		if (!IsEmpty())
		{
			Clear(root);
			root = 0;
		}
	}

	Node* FindNode(int value)
	{
		if (IsEmpty())
			return 0;
		else
		{
			Node* f = root;
			while (true)
			{
				if (value < f->value)
				{
					if (f->left != 0)
						f = f->left;
					else
						break;
				}
				else if (value > f->value)
				{
					if (f->right != 0)
						f = f->right;
					else
						break;
				}
				else
					return f;
			}
			return 0;
		}
	}

	bool Search(int num)
	{
		if (IsEmpty())
			return 0;
		else
		{
			Node* f = root;
			while (true)
			{
				if (num < f->value)
				{
					if (f->left != 0)
						f = f->left;
					else
						break;
				}
				else if (num > f->value)
				{
					if (f->right != 0)
						f = f->right;
					else
						break;
				}
				else
					return true;
			}
			return 0;
		}
	}

	void Add(int value)
	{
		if (FindNode(value))
			return;
		Node* n = new Node;
		n->right = n->left = 0;
		n->value = value;
		Node* parent = 0;
		if (IsEmpty())
		{
			root = n;
			root->parent = parent;
		}
		else
		{
			Node*p = root;
			while (p != 0)
			{
				parent = p;
				if (n->value>p->value)
					p = p->right;
				else
					p = p->left;
			}
			if (n->value<parent->value)
				parent->left = n;
			else
				parent->right = n;
			n->parent = parent;
		}
	}

	BinaryTree& operator = (const BinaryTree& obj)
	{
		if (!IsEmpty())
			Remove();
		Add(obj.root->value);
		Copy(obj.root);
		return *this;
	}

	BinaryTree(const BinaryTree& obj)
	{
		root = 0;
		Add(obj.root->value);
		Copy(obj.root);
	}

	void Copy(Node* elem)
	{
		if (elem->left != 0)
			Add(elem->left->value);
		if (elem->right != 0)
			Add(elem->right->value);
		if (elem->left != 0)
			Copy(elem->left);
		if (elem->right != 0)
			Copy(elem->right);
	}

	void DeleteNode(int value)
	{
		Node* d = FindNode(value);
		if (d == 0)
			return;
		Node* parent = d->parent;
		if (d == root && GetCount() == 1)
		{
			Remove();
			return;
		}
		if (d->left == 0 && d->right == 0)
		{
			if (parent->left == d)
				parent->left = 0;
			else
				parent->right = 0;
			delete d;
			return;
		}
		if (d->left == 0 && d->right != 0)
		{
			if (parent->left == d)
			{
				parent->left = d->right;
			}
			else
			{
				parent->right = d->right;

			}
			d->right->parent = parent;
			delete d;
			return;
		}
		if (d->left != 0 && d->right == 0)
		{
			if (parent->left == d)
			{
				parent->left = d->left;
			}
			else
			{
				parent->right = d->left;

			}
			d->left->parent = parent;
			delete d;
			return;
		}
		if (d->left != 0 && d->right != 0)
		{
			Node*r = d->right;
			if (r->right == 0 && r->left == 0)
			{
				d->value = r->value;
				d->right = 0;
				delete r;
			}
			else if (r->left != 0)
			{
				Node*p = r->left;
				while (p->left != 0)
					p = p->left;
				d->value = p->value;
				if (p->right == 0)
					p->parent->left = 0;
				else
					p->parent->left = p->right;
				delete p;
			}
			else
			{
				d->value = r->value;
				d->right = r->right;
				delete r;
			}
		}
	}
};

/*                  Double linked list         */


class List : public Container
{
public:
	struct Elem
	{
		int data;
		Elem* next;
		Elem* prev;
	};
private:
	Elem *Head, *Tail;
	int length;

public:
	
	List();
	List(const List&);
	~List();
	int GetLength();
	Elem * GetHead()const { return Head; }
	void Add(int n);
	void AddHead(int n);
	void AddTailRange(int n[], int length);
	void AddHeadRange(int n[], int length);
	void Insert(int pos = 0, int number = 10);
	void InsertRange(int a[], int size, int pos = 0);
	void Del(int pos = 0);
	void DelAll();
	void Print();
	void Print(int pos);
	Elem* GetElem(int);

	List& operator = (const List&);
	List operator + (const List&);

	bool operator == (const List&);
	bool operator != (const List&);

	friend ostream& operator<<(ostream& os, const List&);
	Elem& operator[] (int num);
	Elem* GetElementAt(int index);
	bool Equals(const List& other);
	int IndexOf(int num);
	int LastIndexOf(int num);

	void Remove(int number);
	void RemoveAll(int number);
	void Revers();
	int * ToArray();
	void Sort();

	List operator - (); // переворачивание

	bool Search(int num);
};


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

void List::Add(int n)
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
		Add(n[i]);
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
		Add(temp->data);
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
		Add(number);
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

List::Elem * List::GetElem(int pos)
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
		Add(temp->data);
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
		Result.Add(temp->data);
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
	List::Elem * temp;
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

List::Elem& List::operator[](int num)
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

List::Elem* List::GetElementAt(int index)
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
	Elem * temp = Head, *temp2 = other.Head;
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

bool List::Search(int num)
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

