#pragma once
#include "String.h"

//String operator+(char * some, String& other)
//{
//	String result = other + String(some);
//	return result;
//}

template <typename T>
T row(T some, unsigned int step)
{
	T result = 1;
	for (int i = 0; i < (int)step; i++)
		result *= some;
	return result;
}

template <typename T>
unsigned int myCountOfNumbers(T number2)
{
	unsigned int count1 = 0;
	T number = number2;
	while ((int)number > 0)
	{
		number = number / 10;
		count1++;
	}
	return count1;
}

template <typename T>
unsigned int CountDoublePart(T number)
{
	unsigned int count2 = 0;
	T number3 = number;
	while (number3 - (int)number3 != 0)
	{
		number3 *= 10;
		count2++;
	}
	return count2;
}
