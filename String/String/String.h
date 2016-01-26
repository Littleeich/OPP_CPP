#pragma once
#include <iostream>
using namespace std;

class String
{
	unsigned int capacity;
	unsigned int length;
	char * str;

	void ChangeLength(unsigned int newLength, bool type = true);

public:

	static int Compare(String first, String second);
	static int Compare(String other, char* some);
	void SetLength(unsigned int length);
	void SetCapacity(unsigned int capacity);
	void SetStr(char * str);
	void AddStr(char * added);

	unsigned int GetCapacity() { return capacity; }
	unsigned int GetLength() { return length; }
	char * GetStr() { return str;}
	
	unsigned int StrLen(char * str);
	void myStrCpu(char *& Destimation, unsigned int Length, char * Resource);

	static double modificator;

	String(char * str, unsigned int capacity);
	String() :String(nullptr, 80){}
	explicit String(unsigned int capacity) : String(nullptr, capacity){}
	explicit String(char * str) :String(str, 80){}
	String(const String & other, unsigned int capacity) :String(other.str, capacity){}

	String(const String& other) : String(other.str, other.capacity){}
	
	void operator=(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	bool operator>(const String&other);
	bool operator>=(const String& other);
	bool operator<(const String& other);
	bool operator<=(const String& other);
	void operator()(char * str);
	void operator()(const String& other);
	char operator[](unsigned int index);
	String operator+(const String& other);
	String operator+(char * some);
	void operator+=(const String& other);
	void operator+=(char * some);

	friend ostream& operator<<(ostream& os, String& other);
	friend istream& operator>>(istream& is, String& other);

	operator char*()const;
	operator int()const;
	operator double() const;

	void Print();
	void PrintLn();
	void GetLine();

	const String* GetString()const;
	const char* GetCharArray() const;

	void Concat(String &other);
	void Concat(char * other);
	void Concat(int number);
	void Concat(double number);
	void Concat(String * other, int count);

	bool Contains(const String& other);
	bool EndsWith(const String& other);
	bool StartsWith(const String& other);
	bool Equals(const String& other);
	void CopyTo(String& other);
	void Clear();

	int CompareTo(String &other);
	int CompareTo(char * some);

	int IndexOf(char s);
	int LastIndexOf(char s);
	int IndexOf(const String& other);
	int LastIndexOf(const String& other);
	int IndexOfAny(const String& other);

	void TrimEnd();
	void TrimStart();
	void Trim();
	void Normalize();
	void PadLeft(int number, char s = ' ');
	void PadRight(int number, char s = ' ');

	void Remove(int Index);
	void Remove(int Index, int Count);
	void Replace(char R, char Z);
	void Replace(const String& from,const String& to);

	void ToLower();
	void ToUpper();
	void Revers();
	void SortAZ();
	void SortZA();
	void Shuffle();
	void RandomFill();
	void Resize(int NewLength);
	void Insert(const String& other, int Index);
	~String();
};


