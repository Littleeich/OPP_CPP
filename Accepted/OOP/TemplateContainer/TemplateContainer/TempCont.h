#pragma once
#include <ctime>
#include <iostream>

using namespace std;

template <class T>
class Container
{
protected:
	unsigned int count;

public:
	/*Container(unsigned int count);
	Container() :Container(0){}
	~Container();*/

	unsigned int GetCount() const{ return count; }

	void Add(T number)
	{
		cout << "Add " << number << endl;
	}
	void Remove(T number)
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

template <class T>
class MyVector : public Container<T>
{
	T* data;
	unsigned int capacity;
	static double modificator;

public:
	// конструкторы
	MyVector(T* data, unsigned int capacity, unsigned int count);
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

	const T& operator[](unsigned int index) const; // доступ к элементам (просмотр!)

	// добавление и удаление элементов
	void Add(T number);
	void Insert(unsigned int index, T number);
	void Remove(int index);
	void RemoveEnd();
	void Resize(unsigned int capacity);

	void Print() const;
	short IndexOf(T number);
	short LastIndexOf(T number);
	void Revers();
	void Sort();
	void Shuffle();
	bool Search(T number);

	friend ostream& operator<<(ostream& os, const MyVector& obj);
	friend istream& operator>>(istream& is, MyVector& obj);
};

template <class T>
double MyVector<T>::modificator = 3;

template <class T>
MyVector<T>::MyVector(T array[], unsigned int arrayCapacity, unsigned int arraySize)
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
		data = new T[capacity];
		for (unsigned int i = 0; i < arraySize; i++)
			data[i] = array[i];
	}
	count = arraySize;
}

template <class T>
void MyVector<T>::Resize(unsigned int capacity)
{
	if (capacity == this->capacity) return;
	else if (capacity > count)
	{
		int * temp = new T[capacity];
		for (unsigned int i = 0; i < count; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
	}
	else
	{
		int * temp = new T[capacity];
		for (unsigned int i = 0; i < capacity; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		count = capacity;
	}
	this->capacity = capacity;
}

template <class T>
void MyVector<T>::Clear()
{
	if (count)
	{
		delete[] data;
		data = nullptr;
		count = 0;
		capacity = 80;
	}
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& original)
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
		int* temp = new T[original.capacity];
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

template <class T>
const T& MyVector<T>::operator[](unsigned int index) const
{
	if (index >= count) throw "Incorrect index!"; // генерация исключения!
	return data[index];
}

template <class T>
void MyVector<T>::operator()(unsigned int capacity)
{
	Resize(capacity);
}

template <class T>
void MyVector<T>::Add(T number)
{
	if (count == 0)
	{
		data = new T[capacity];
		data[0] = number;
	}
	else
	{
		if (count + 1 <= capacity)
			data[count] = number;
		else
		{
			// выделяем память и копируем элементы
			T* temp = new T[int(capacity * modificator)];
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

template <class T>
void MyVector<T>::Insert(unsigned int index, T number)
{
	if (index > count) index = count;

	if (count == 0)
	{
		data = new T[capacity];
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
		T* temp = new T[int(capacity * arrayIndex)];
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

template <class T>
void MyVector<T>::Remove(int index)
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
		T *temp = new T[capacity];
		for (unsigned int i = 0; i < count; i++)
			if (i < index) temp[i] = data[i];
			else if (i > index) temp[i - 1] = data[i];
			// удаляем старый массив
			delete[] data;
			data = temp;
	}
	count--;
}

template <class T>
void MyVector<T>::RemoveEnd()
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

template <class T>
void MyVector<T>::Print() const
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

template <class T>
short MyVector<T>::IndexOf(T number)
{
	for (short i = 0; i < (short)count; i++)
		if (data[i] == number)
			return i;
	return -1;
}

template <class T>
short MyVector<T>::LastIndexOf(T number)
{
	short index = -1;
	for (short i = 0; i < (short)count; i++)
		if (data[i] == number)
			index = i;
	return index;
}

template <class T>
void MyVector<T>::Revers()
{
	T * temp = new T[capacity];
	for (unsigned int i = 0; i < count; i++)
		temp[i] = data[count - 1 - i];
	delete[] data;
	data = temp;
}

template <class T>
void MyVector<T>::Sort()
{
	for (int j = count - 1; j > 0; j--)
		for (int i = 0; i < j; i++)
			if (data[i] > data[i + 1])
				swap(data[i], data[i + 1]);
}

template <class T>
void MyVector<T>::Shuffle()
{
	int count2 = count;
	T * temp = new T[count2];
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

template <class T>
bool MyVector<T>::operator==(const MyVector<T>& other)
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

template <class T>
void MyVector<T>::operator+=(const MyVector<T>& other)
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
		T* temp = new T[int(capacity)];
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

template <class T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& other)
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

template <class T>
bool MyVector<T>::Search(T number)
{
	for (int i = 0; i < count; i++)
		if (data[i] == number)
			return true;
	return false;
}

template <class T>
ostream& operator<<(ostream& os, const MyVector<T>& obj)
{
	cout << "My array of int: " << endl;
	for (int i = 0; i < obj.count - 1; i++)
		os << obj.data[i] << ",  ";
	os << obj.data[obj.count - 1] << '.' << endl;
	return os;
}

template <class T>
istream& operator>>(istream& is, MyVector<T>& obj)
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
template <class T>
class SingleLinkedList : public Container<T>
{
public:
	struct Element
	{
		T data;
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
	void Add(T data)
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

	void Add_Head(T data)
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

	bool Search(T num)
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

template <class T>
class BinaryTree : public Container<T>
{
public:
	struct Node
	{
		T value;

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

	bool Search(T num)
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

	void Add(T value)
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

	void DeleteNode(T value)
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

template <class T>
class List: public Container<T>
{
public:
	struct Elem
	{
		T data;
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
	void Add(T n);
	void AddHead(T n);
	void AddTailRange(T n[], int length);
	void AddHeadRange(T n[], int length);
	void Insert(int pos = 0, T number = 10);
	void InsertRange(T a[], int size, int pos = 0);
	void Del(int pos = 0);
	void DelAll();
	void Print();
	void Print(int pos);

	List& operator = (const List&);
	List operator + (const List&);

	bool operator == (const List&);
	bool operator != (const List&);

	friend ostream& operator<<(ostream& os, const List&);
	
	bool Equals(const List& other);
	int IndexOf(T num);
	int LastIndexOf(T num);

	void Remove(T number);
	void RemoveAll(T number);
	void Revers();
	int * ToArray();
	void Sort();

	List operator - (); // переворачивание

	bool Search(T num);
};

template <class T>
List<T>::List()
{
	Head = Tail = NULL;
	length = 0;
}

template <class T>
void List<T>::AddHead(T n)
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

template <class T>
void List<T>::AddHeadRange(T n[], int length)
{
	for (int i = 0; i < length; i++)
		AddHead(n[length - 1 - i]);
}

template <class T>
void List<T>::Add(T n)
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

template <class T>
void List<T>::AddTailRange(T n[], int length)
{
	for (int i = 0; i < length; i++)
		Add(n[i]);
}

// конструктор копирования
template <class T>
List<T>::List(const List<T> & L)
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

template <class T>
void List<T>::Insert(int pos, T number)
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

template <class T>
void List<T>::InsertRange(T a[], int size, int pos)
{
	for (int i = 0; i < size; i++)
	{
		Insert(pos, a[i]);
		pos++;
	}
}

template <class T>
void List<T>::Del(int pos)
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

template <class T>
void List<T>::DelAll()
{
	while (length != 0) Del(1);
}

template <class T>
List<T>::~List()
{
	DelAll();
}

template <class T>
void List<T>::Print(int pos)
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

template <class T>
void List<T>::Print()
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

template <class T>
int List<T>::GetLength()
{
	return length;
}

template <class T>
List<T> & List<T>::operator = (const List<T> & L)
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

template <class T>
List<T> List<T>::operator + (const List<T>& L)
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

template <class T>
bool List<T>::operator == (const List<T>& L)
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

template <class T>
bool List<T>::operator != (const List<T>& L)
{
	return !(*this == L);
}

template <class T>
ostream& operator<<(ostream& os, const List<T>& L)
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

template <class T>
bool List<T>::Equals(const List<T>& other)
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

template <class T>
int List<T>::IndexOf(T num)
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

template <class T>
int List<T>::LastIndexOf(T num)
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

template <class T>
void List<T>::Remove(T number)
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

template <class T>
void List<T>::RemoveAll(T number)
{
	while (IndexOf(number) != -1)
		Remove(number);
}

// переворот
template <class T>
List<T> List<T>::operator - ()
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

template <class T>
bool List<T>::Search(T num)
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

template <class T>
void List<T>::Revers()
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

template <class T>
int * List<T>::ToArray()
{
	T * a = new T[length];
	int i = 0;
	Elem * temp = Head;
	while (temp)
	{
		a[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return a;
}

template <class T>
void List<T>::Sort()
{
	T*array = new T[length];
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

