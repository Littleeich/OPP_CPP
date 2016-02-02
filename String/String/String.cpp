#include "String.h"
#include "boobs.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

double String::modificator = 2;

int String::Compare(String first, String other)
{
	int i = 0;
	if (first.str == nullptr && other.str == nullptr)
		return 0;
	else if (first.str == nullptr)
		return -1;
	else if (other.str == nullptr)
		return 1;
	while (first.str[i] && other.str[i])
	{
		if (first.str[i] > other.str[i])
			return 1;
		if (first.str[i] < other.str[i])
			return -1;
		i++;
	}
	if (!first.str[i] && !other.str[i])
		return 0;
	if (!first.str[i])
		return -1;
	else
		return 1;;
}

int String::Compare(String first, char * some)
{
	int i = 0;
	if (first.str == nullptr && some == nullptr)
		return 0;
	else if (first.str == nullptr)
		return -1;
	else if (some == nullptr)
		return 1;
	while (first.str[i] && some[i])
	{
		if (first.str[i] > some[i])
			return 1;
		if (first.str[i] < some[i])
			return -1;
		i++;
	}
	if (!first.str[i] && !some[i])
		return 0;
	if (!first.str[i])
		return -1;
	else
		return 1;
}

void String::SetCapacity(unsigned int capacity)
{
	if (capacity > 10)
		this->capacity = capacity;
	else
		this->capacity = 10;
}

void String::SetLength(unsigned int length)
{
	while (length + 1 > capacity)
		capacity = unsigned int(capacity * modificator);
	this->length = length;
}

void String::ChangeLength(unsigned int newLength, bool type)
{
	unsigned int firstNum;
	if (type)
		firstNum = length;
	else
		firstNum = 0;

	if (firstNum + newLength > capacity)
	{
		char * temp = new char;
		for (unsigned int i = 0; i < firstNum; i++)
			temp[i] = str[i];
		temp[firstNum] = (char)'/0';
		SetLength(firstNum + newLength);
		SetCapacity(capacity);
		delete[] str;
		SetStr(temp);
	}
	else
	{
		SetLength(firstNum + newLength);
		SetCapacity(capacity);
	}
}

unsigned int String::StrLen(char * Str)
{
	unsigned int NewLength = 0;
	if (Str == nullptr) return 0;
	else
		while (*Str)
			{
				NewLength++;
				Str++;
			}
	return NewLength;
}

void String::SetStr(char * str)
{
	int Length = StrLen(str) + 1;
	if (Length < 2) return;

	if (this->str != nullptr)
	{ 
		//delete[] this->str;
		this->str = nullptr;
	}
	this->str = new char[capacity];
	myStrCpu(this->str, Length, str);
}

void String::myStrCpu(char *& str1, unsigned int Length, char * str2)
{
	for (unsigned int i = 0; i < Length; i++)
		str1[i] = str2[i];
	str1[Length] = '\0';
}

String::String(char * str, unsigned int capacity)
{
	SetCapacity(capacity);
	SetLength(StrLen(str));
	SetStr(str);
}

void String::operator=(const String& other)
{
	SetCapacity(other.capacity);
	SetLength(other.length);
	SetStr(other.str);
}

bool String::operator==(const String& other)
{
	if (length != other.length)
		return false;
	int i = 0;
	while (str[i])
	{
		if (str[i] != other.str[i])
			return false;
		i++;
	}
	return true;
}

bool String::operator!=(const String& other)
{
	if (length != other.length)
		return true;
	int i = 0;
	while (str[i])
	{
		if (str[i] != other.str[i])
			return true;
		i++;
	}
	return false;
}

bool String::operator>(const String& other)
{
	//если первой строки нету вообще, то она не может быть больше второй
	if (str == nullptr)
		return false;
	else if (other.str == nullptr)
		return true;
	
	//посимвольно провер€ем соотношение строк, пока не найдЄм различие в символах
	int i = 0;
	//проверка до тех пока пока хот€бы одна из строк не закончитс€
	while (str[i] && other.str[i])
	{
		//если символ первой строки меньше символа второй, то она не может быть больше - возврат Ћќ∆№
		if (str[i] > other.str[i])
			return false;
		else if (str[i] < other.str[i])
			return true;
		i++;
	}
	//если перва€ строка всЄ продолжаетс€, а втора€ уже закончилась, то возврат - Ћќ∆№
	if ((str[i] && !other.str[i]) || (!str[i] && !other.str[i]))
		return false;
	//иначе перва€ строка и првда больше второй
	return true;
}

bool String::operator>=(const String& other)
{
	//если первой строки нету вообще, то она не может быть больше второй
	if (str == nullptr)
		return false;
	else if (other.str == nullptr)
		return true;
	//посимвольно провер€ем соотношение строк, пока не найдЄм различие в символах
	int i = 0;
	//проверка до тех пока пока хот€бы одна из строк не закончитс€
	while (str[i] && other.str[i])
	{
		//если символ первой строки меньше символа второй, то она не может быть больше - возврат Ћќ∆№
		if (str[i] > other.str[i])
			return false;
		i++;
	}
	//если перва€ строка всЄ продолжаетс€, а втора€ уже закончилась, то возврат - Ћќ∆№
	if (str[i] && !other.str[i]) 
		return false;
	//иначе перва€ строка и првда больше второй
	return true;
}

bool String::operator<=(String& other)
{
	if (other >= *this)
		return true;
	else
		return false;
}

bool String::operator<(String& other)
{
	if (other.operator>(*this))
		return true;
	else
		return false;
}

void String::operator()(char * str)
{
	SetLength(StrLen(str));
	SetStr(str);
}

void String::operator()(const String& other)
{
	SetLength(StrLen(other.str));
	SetStr(other.str);
}

char String::operator[](unsigned int index)
{
	if (str == nullptr || index > length - 1)
		return '\0';
	return str[index];
}

String String::operator+(const String& other)
{
	unsigned int wide = this->length;
	String * result = new String("s");
	result->SetLength(wide + other.length);
	result->SetCapacity(capacity);
	if (this->str)
	for (unsigned int i = 0; i < wide; i++)
		result->str[i] = this->str[i];
	if (other.str)
	for (unsigned int i = wide; i < (wide + other.length); i++)
		result->str[i] = other.str[i - wide];
	result->str[wide + other.length] = '\0';
	return *result;
}

String String::operator+(char * some)
{
	String result = *this + String(some);
	return result;
}

void String::AddStr(char * added)
{
	*this = *this + added;
}

void String::operator+=(const String& other)
{
	*this = *this + other;
}

void String::operator+=(char * other)
{
	*this = *this + other;
}

String::operator char *() const
{
	return this->str;
}

String::operator int()const
{
	int result = atoi(this->str);
	return result;
}

String::operator double() const
{
	double result = atof(this->str);
	return result;
}

String::~String()
{
	delete[] str;
	str = nullptr;
}

void String::Print()
{
	if (str)
		printf(str);
	else
		printf("Error! No string in the line.");
}

void String::PrintLn()
{
	if (str)
		printf(str);
	else
		printf("Error! No string in the line.");
	printf("\n");
}

void String::GetLine()
{
	cin >> *this;
}

const String* String::GetString()const
{
	return this;
}

const char* String::GetCharArray() const
{
	return this->str;
}

int String::CompareTo(String& other)
{
	if (*this > other)
		return 1;
	else if (other > *this)
		return -1;
	else
		return 0;
}

int String::CompareTo(char * some)
{
	String temp(some);
	return CompareTo(temp);
}

void String::Concat(String &other)
{
	*this += other;
}

void String::Concat(char * other)
{
	*this += other;
}

void String::Concat(int number)
{
	if (number == 0)
	{
		*this += "0";
		return;
	}
	unsigned int size = myCountOfNumbers(number);
	char * some = new char[size + 1];
	_itoa_s(number, some, size + 1, 10);
	*this += some;
	delete[] some;
}

void String::Concat(double number, int accuracy)
{
	Concat((int)number);
	*this += ".";
	number -= (int)number;
	for (int i = 0; i < accuracy; i++)
		number *= 10;
	Concat((int)number);
}

void String::Concat(String * other, int count)
{
	if (other->length < (unsigned int)count)
		count = other->length;
	else
	{
		unsigned int width = length;
		SetLength(length + count);
		SetCapacity(capacity);
		char * temp = new char[capacity];
		if (width > 0)
			for (unsigned int i = 0; i < width; i++)
				temp[i] = str[i];
		if (count > 0)
			for (unsigned int i = width; i < length; i++)
				temp[i] = other->str[i - width];
		temp[length] = '\0';
		delete[] str;
		str = temp;
	}
}

bool String::Contains(const String& other)
{
	if (length < other.length)
		return false;
	for (unsigned int i = 0; i < length - other.length + 1; i++)
		if (str[i] == other.str[0])
		{
			int num = 1;
			for (unsigned int j = 1; j < other.length; j++)
				if (str[i + j] == other.str[j])
					num++;
				else
					break;
			if (num == other.length)
				return true;
		}
	return false;
}

bool String::EndsWith(const String& other)
{
	if (length < other.length)
		return false;
	unsigned int i = length - other.length;
		if (str[i] == other.str[0])
		{
			int num = 1;
			for (unsigned int j = 1; j < other.length; j++)
				if (str[i + j] == other.str[j])
					num++;
				else
					break;
			if (num == other.length)
				return true;
		}
	return false;
}

bool String::StartsWith(const String& other)
{
	if (length < other.length)
		return false;
	unsigned int i = 0;
	if (str[i] == other.str[0])
	{
		int num = 1;
		for (unsigned int j = 1; j < other.length; j++)
			if (str[i + j] == other.str[j])
				num++;
			else
				break;
		if (num == other.length)
			return true;
	}
	return false;

}

bool String::Equals(const String& other)
{
	return *this == other;
}

void String::CopyTo(String& other)
{
	other.SetLength(length);
	other.SetCapacity(capacity);
	other.SetStr(str);
}

void String::Clear()
{
	delete[] str;
	str = nullptr;
}

int String::IndexOf(char s)
{
	for (unsigned int i = 0; i < length; i++)
		if (str[i] == s)
			return (int)i;
	return -1;
}

int String::LastIndexOf(char s)
{
	int result = -1;
	for (unsigned int i = 0; i < length; i++)
		if (str[i] == s)
			result = (int)i;
	return result;
}

int String::IndexOf(const String& other)
{
	if (length < other.length)
		return -1;
	for (unsigned int i = 0; i < length - other.length + 1; i++)
		if (str[i] == other.str[0])
		{
			int num = 1;
			for (unsigned int j = 1; j < other.length; j++)
				if (str[i + j] == other.str[j])
					num++;
				else
					break;
			if (num == other.length)
				return (int)i;
		}
	return -1;
}

int String::LastIndexOf(const String & other)
{
	if (length < other.length)
		return -1;
	int Index = -1;
	for (unsigned int i = 0; i < length - other.length + 1; i++)
		if (str[i] == other.str[0])
		{
			int num = 1;
			for (unsigned int j = 1; j < other.length; j++)
				if (str[i + j] == other.str[j])
					num++;
				else
					break;
			if (num == other.length)
				Index = i;
		}
	return Index;
}

int String::IndexOfAny(const String& other)
{
	for(unsigned int i = 0; i < length; i++)
		for(unsigned int j = 0; j < other.length; j++)
			if(str[i] == other.str[j])
				return (int)i;
	return -1;
}

void String::TrimEnd()
{
	unsigned int num = 0;
	for (unsigned int i = length - 1; i > 0; i--)
		if (str[i] == ' ')
			num++;
		else
			break;

	if (num > 0)
	{
		str[length - num] = '\0';
		SetLength(length - num);
	}
}

void String::TrimStart()
{
	unsigned int num = 0;
	for (unsigned int i = 0; i < length; i++)
		if (str[i] == ' ')
			num++;
		else
			break;

	if (num > 0)
	{
		char * temp = new char[capacity];
		for (unsigned int j = num; j < length; j++)
			temp[j - num] = str[j];
		temp[length - num] = '\0';
		delete[] str;
		str = temp;
		SetLength(length - num);
	}
}

void String::Trim()
{
	TrimEnd();
	TrimStart();
}

//вот тут даже рекурси€ есть! я теперь себ€ программистом чувствую!))))
void String::Normalize()
{
	Trim();
	for (unsigned int i = 1; i < length; i++)
		if (str[i] == 32)
			if (str[i + 1] == 32)
			{
				char * temp = new char[capacity];
				for (unsigned int j = 0; j < i + 1; j++)
					temp[j] = str[j];
				for (unsigned int j = i + 1; j < length - 1; j++)
					temp[j] = str[j + 1];
				temp[length - 1] = '\0';
				length--;
				delete[] str;
				str = temp;
				Normalize();
			}
}

void String::PadLeft(int number, char s)
{
	if (number > 0)
	{
		ChangeLength((unsigned int)number);
		SetCapacity(capacity);

		char * temp = new char[capacity];
		for (int i = 0; i < number; i++)
			temp[i] = s;
		for (unsigned int i = (unsigned int)number; i < length; i++)
			temp[i] = str[i - number];
		temp[length] = '\0';
		delete[] str;
		str = temp;
	}
}

void String::PadRight(int number, char s)
{
	if (number > 0)
	{
		unsigned int width = length;
		ChangeLength((unsigned int)number);
		SetCapacity(capacity);

		for (unsigned int i = width; i < length; i++)
			str[i] = s;
		str[length] = '\0';
	}
}

void String::Remove(int Index)
{
	if (Index >= 0)
	{
		str[(unsigned int)Index] = (char)'/0';
		SetLength((unsigned int)Index);
	}
}

void String::Remove(int Index, int Count)
{
	if (Index > 0 && Count > 0)
	{
		if (Index + Count > (int)length)
		{
			Remove(Index);
			return;
		}
		else
		{
			char * temp = new char[capacity];
			for (unsigned int i = 0; i < (unsigned int)Index; i++)
				temp[i] = str[i];
			for (unsigned int i = Index; i < length - Count; i++)
				temp[i] = str[i + Count];
			temp[length - Count] = '\0';
			delete[] str;
			str = temp;
			SetLength(length - Count);
		}
	}
}

void String::Replace(char R, char Z)
{
	for (unsigned int i = 0; i < length; i++)
		if (str[i] == R)
			str[i] = Z;
}

void String::Replace(const String& other, const String& newStr)
{
	if (other.str == nullptr)
		return;
	if (length < other.length)
		return;
	for (unsigned int i = 0; i < length - other.length + 1; i++)
		if (str[i] == other.str[0])
		{
			int num = 1;
			for (unsigned int j = 1; j < other.length; j++)
				if (str[i + j] == other.str[j])
					num++;
				else
					break;
			if (num == other.length)
			{
				if (newStr.length >= other.length)
					ChangeLength(newStr.length - other.length);
				else
					SetLength(length + newStr.length - other.length);
				SetCapacity(capacity);

				char * temp = new char[capacity];
				unsigned int l;
				for (l = 0; l < i; l++)
					temp[l] = str[l];
				for (l = i; l < i + newStr.length; l++)
					temp[l] = newStr.str[l - i];
				for (l = i + newStr.length; l < length; l++)
					if (newStr.length > 0)
						temp[l] = str[l + other.length - newStr.length];
					else
						temp[l] = str[l + other.length];
				temp[length] = '\0';

				delete[] str;
				str = temp;
			}
		}
	return ;
}

//заменил возвратный тип на войд
void String::ToLower()
{
	
	if (this->str == nullptr)
		return;

	for (unsigned int i = 0; i < length; i++)
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'ј' && str[i] <= 'я'))
			str[i] += 'a' - 'A';
}

//заменил возвратный тип на войд
void String::ToUpper()
{
	if (this->str == nullptr)
		return;

	for (unsigned int i = 0; i < length; i++)
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= -32 && str[i] <= -1))
			str[i] -= 32;
}

void String::Revers()
{
	_strrev(str);
}

void String::SortAZ()
{
	for (unsigned int j = length - 1; j > 0; j--)
		for (unsigned int i = 0; i < j; i++)
			if (str[i]>str[i + 1])
				swap(str[i], str[i + 1]);
}

void String::SortZA()
{
	SortAZ();
	Revers();
}

void String::Shuffle()
{
	unsigned int j = 0;
	for (unsigned int i = 0; i < length; i++)
	{
		j = rand() % length;
		swap(str[i], str[j]);
	}
}

void String::RandomFill()
{
	SetLength(capacity - 2);
	for (unsigned int i = 0; i < capacity - 1; i++)
		str[i] = rand() % 256 - 128;
	str[capacity - 1] = (char)'/0';
}

void String::Resize(int NewLength)
{
	Remove(NewLength);
}

void String::Insert(const String & other, int Index)
{
	if(other.str == nullptr || Index < 0)
		return;

	ChangeLength(other.length);
	SetCapacity(capacity);
	char * temp = new char[capacity];
	
	unsigned int middle = Index + other.length;

	for (unsigned int i = 0; i < (unsigned int)Index; i++)
		temp[i] = str[i];
	for (unsigned int i = (unsigned int)Index; i < middle; i++)
		temp[i] = other.str[i - (unsigned int)Index];
	for (unsigned int i = middle; i < length; i++)
		temp[i] = str[i - other.length];
	temp[length] = '\0';

	delete[] str;
	str = temp;
}

ostream& operator<<(ostream& os, String& other)
{
	if (other.str != nullptr)
		for (unsigned int i = 0; i < other.GetLength(); i++)
			os << other.GetStr()[i];
	else
		os << "Error! No string in the line!\n";
	return os;
}

istream& operator>>(istream& is, String& obj)
{
	is >> obj.str;
	obj.SetLength(obj.StrLen(obj.str));
	obj.SetCapacity(obj.capacity);
	return is;
}