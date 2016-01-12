#include "Date.h"

void Date::SetYear(short year)
{
	if (year < min_year)
		this->year = min_year;
	else if (year > max_year)
		this->year = max_year;
	else
		this->year = year;
}

void Date::SetMonth(short month)
{
	if (month < 1)
		this->month = 1;
	else if (month > 12)
		this->month = 12;
	else
		this->month = month;
}

int Date::GetDayOfMonth(short month) const
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		if (year % 4 != 0)
			return 28;
		else
			return 29;
}

void Date::SetDay(short day)
{
	if (day < 0)
		this->day = 1;
	else if (day > GetDayOfMonth(this->month))
		this->day = GetDayOfMonth(this->month);
	else
		this->day = day;
}

Date::Date(short day, short month, short year)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

void Date::AddDay(short Aday)
{
	while (Aday > 365)
	{
		if (year % 4 != 0)
			Aday -= 365;
		else
			Aday -= 366;
		AddYear(1);
	}

	while (Aday > GetDayOfMonth(this->month))
	{
		Aday -= GetDayOfMonth(this->month);
		AddMonth(1);
	}

	if (day + Aday > GetDayOfMonth(this->month))
	{
		day += Aday - GetDayOfMonth(this->month);
		AddMonth(1);
	}
	else
		day += Aday;
}

void Date::AddMonth(short Amonth)
{
	if (month + Amonth <= 12)
		month += Amonth;
	else
	{
		month = month + Amonth - 12;
		AddYear(1);
	}
}

void Date::AddYear(short Ayear)
{
	if (year + Ayear < max_year)
		year += Ayear;
	else
		year = 9999;
}

int Date::DiffOfTheDays(Date date)
{
	int amount;
	if (this->day <= date.day)
		amount = date.day - this->day;
	else
	{
		if (date.month > 1)
		{
			date.month -= 1;
			amount = date.day + GetDayOfMonth(date.month) - this->day;
		}
		else
		{
			date.month = 12;
			date.year -= 1;
			amount = date.day + GetDayOfMonth(date.month) - this->day;
		}
	}

	if (this->month <= date.month)
		while (this->month != date.month)
		{
			amount += GetDayOfMonth(date.month - 1);
			date.month--;
		}
	else
	{
		while (this->month != (date.month) + 12)
		{
			if (date.month > 1)
			{
				amount += GetDayOfMonth(date.month - 1);
				date.month--;
			}
			else
			{
				amount += GetDayOfMonth(date.month + 12 - 1);
				date.month--;
			}
		}
		date.year--;
	}

	if (this->year <= date.year)
		while (this->year != date.year)
		{
			if ((date.year - 1) % 4 != 0)
				amount += 365;
			else
				amount += 366;
			date.year--;
		}

	return amount;

}

bool Date::operator>(const Date & date)
{
	if (this->year > date.year)
		return true;
	else if (this->year < date.year)
		return false;
	else if (this->month > date.month)
		return true;
	else if (this->month < date.month)
		return false;
	else if (this->day > date.day)
		return true;
	else
		return false;
}

bool Date::operator<(const Date & date)
{
	if (this->year < date.year)
		return true;
	else if (this->year > date.year)
		return false;
	else if (this->month < date.month)
		return true;
	else if (this->month > date.month)
		return false;
	else if (this->day < date.day)
		return true;
	else
		return false;
}

Date Date::DeductDay()
{
	if (day > 1)
		return Date(day - 1, month, year);
	else if (month > 1)
		return Date(GetDayOfMonth(month - 1), month - 1, year);
	else
		return Date(31, 12, year - 1);
}

char * Date::DayOfWeek()
{
	char * Day_of_week[4];
	Date etalon(1, 1, 1990);
	Date now (day, month, year);
	short result = (etalon - now) % 7;

	if (result == 0)
		* Day_of_week = "MON";
	else if (result == 1)
		* Day_of_week = "TUE";
	else if (result == 2)
		* Day_of_week ="WED";
	else if (result == 3)
		* Day_of_week = "THU";
	else if (result == 4)
		* Day_of_week = "FRI";
	else if (result == 5)
		* Day_of_week = "SAT";
	else if (result == 6)
		* Day_of_week = "SUN";
	else
		* Day_of_week = "NAN";

	return * Day_of_week;
}

Date::~Date()
{
}
