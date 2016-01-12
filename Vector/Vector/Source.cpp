#include <iostream>
#include <ctime>
using namespace std;

class MyVector
{
	int* data;
	unsigned int count;
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
	void Remove(unsigned int index);
	void RemoveEnd();
	void Resize(unsigned int capacity);

	void Print() const;
	short IndexOf(int number);
	short LastIndexOf(int number);
	void Revers();
	void Sort();
	void Shuffle();

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
		// выдел€ем пам€ть и копируем элементы
		data = new int[capacity];
		for (unsigned int i = 0; i < arraySize; i++)
			data[i] = array[i];
	}
	count = arraySize;
}

void MyVector::Resize(unsigned int capacity)
{
	if(capacity == this->capacity) return;
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
		// выдел€ем пам€ть и копируем элементы
		int* temp = new int[original.capacity];
		for (unsigned int i = 0; i < original.count; i++)
			temp[i] = original.data[i];
		// удал€ем старый массив
		delete[] data;
		data = temp;
	}
	count = original.count;
	capacity = original.capacity;

	return *this;
}

const int& MyVector::operator[](unsigned int index) const
{
	if (index >= count) throw "Incorrect index!"; // генераци€ исключени€!
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
			// выдел€ем пам€ть и копируем элементы
			int* temp = new int[int(capacity * modificator)];
			for (unsigned int i = 0; i < count; i++)
				temp[i] = data[i];
			// добавл€ем новый элемент
			temp[count] = number;
			// удал€ем старый массив
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
				// выдел€ем пам€ть и копируем элементы
				int* temp = new int[int(capacity * arrayIndex)];
				capacity = unsigned int(capacity * modificator);
				for (unsigned int i = 0; i < count; i++)
					if (i < index) temp[i] = data[i];
					else if (i >= index) temp[i + 1] = data[i];
					// вставл€ем новый элемент
					temp[index] = number;
					// удал€ем старый массив
					delete[] data;
					data = temp;
					capacity = unsigned int(capacity * arrayIndex);
	}
	count++;
}

void MyVector::Remove(unsigned int index)
{
	if (index >= count) throw "Incorrect index!";

	if (count == 1)
	{
		delete[] data;
		data = nullptr;
	}
	else
	{
		// выдел€ем пам€ть и копируем элементы
		int *temp = new int[capacity];
		for (unsigned int i = 0; i < count; i++)
			if (i < index) temp[i] = data[i];
			else if (i > index) temp[i - 1] = data[i];
			// удал€ем старый массив
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
		// выдел€ем пам€ть и копируем элементы
		int* temp = new int[int(capacity)];
		for (unsigned int i = 0; i < count; i++)
			temp[i] = data[i];
		// добавл€ем новый элемент
		for (unsigned int i = 0; i < other.count; i++)
			temp[count + i] = other.data[i];
		// удал€ем старый массив
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

void main()
{
	system("title ѕользовательский контейнер MyVector");
	srand(time(0));
	rand();

	int some[10] = { 2, 5, 6, 7, 5, 2, 2 };
	MyVector a(some, 80, 7);
	a.Print();
	
	for (int i = 0; i < 5; i++)
		a.Add(rand() % 90 + 10); // добавл€ем в вектор 5 случайных двузначных чисел
	a.Print();

	for (int i = 0; i < 3; i++)
		a.Insert(i + 1, 97 + i); // вставл€ем по индексу 1,2,3 числа 97,98,99
	a.Print();

	for (int i = 0; i < 6; i++) // удал€ем 6 чисел, по индексу 1
		a.Remove(2);
	a.Print();

	a.Resize(30);
	a.RemoveEnd();
	a.Print();

	cout << "Position of number 2 is " << a.IndexOf(2) << endl;
	cout << "Last Position of number 2 is " << a.LastIndexOf(2) << endl << endl;

	a.Revers();
	a.Print();
	MyVector c = a;

	a.Sort();
	a.Print();

	a.Shuffle();
	a.Print();

	MyVector b = a;
	if (b == a)
		cout << "True!\n\n";
	else
		cout << "False!\n\n";

	a(50);
	cout << a.GetCapacity() << endl;
	a(80);
	cout << a.GetCapacity() << endl;
	cout << a[4] << endl;
	a += c;
	a.Print();

	b.Print();
	c.Print();
	(b + c).Print();

	cout << b;
	cin >> a;
	cout << a;
}
