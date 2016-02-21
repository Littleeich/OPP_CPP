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

	~MyVector() { Clear(); } // деструктор

	void Clear(); // очистка вектора

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

double MyVector::modificator = 1.5;

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
		data = new int;
		*data = number;
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

