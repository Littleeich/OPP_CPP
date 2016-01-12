#pragma once
class Date
{
	short day;
	short month;
	short year;
	short min_year = 1900;
	short max_year = 2100;

public:
	Date(short day, short month, short year);
	Date(short day, short month) :Date(day, month, min_year){};
	Date(short day) :Date(day, 01, min_year){};
	Date() :Date(01, 01, min_year){};

	void SetDay(short day);
	void SetMonth(short month);
	void SetYear(short year);

	int GetDayOfMonth(short month) const;
	short GetDay() const{ return day; };
	short GetMonth() const { return month; };
	short GetYear() const { return year; };

	void AddDay(short Aday);
	void AddMonth(short Amonth);
	void AddYear(short Ayear);

	short DiffOfTheDays(Date date);

	Date operator+(int k)
	{
		Date result(this->day, this->month, this->year);
		result.AddDay(k);
		return result;
	}

	Date operator+=(int k)
	{
		AddDay(k);
		Date result(this->day, this->month, this->year);
		return result;
	}

	short operator-(const Date & date)
	{
		Date some = *this;
		if (*this < date)
			return DiffOfTheDays(date);

		//не могу пон¤ть почему так нельз¤ стр. 52-53
		/*else
		return (-1) * date.DiffOfTheDays(some);*/
	}

	short operator-=(const Date & date)
	{
		Date some = *this;
		if (*this < date)
			return DiffOfTheDays(date);

		//не могу пон¤ть почему так нельз¤ стр. 45-46
		/*else
		return (-1) * date.DiffOfTheDays(some);*/
	}

	bool operator>(const Date & date);

	bool operator<(const Date & date);

	bool operator==(const Date & date)
	{
		if (this->year == date.year && this->month == date.month && this->day == date.day)
			return true;
		else
			return false;
	}

	bool operator!=(const Date & date)
	{
		if (this->year != date.year || this->month != date.month || this->day != date.day)
			return true;
		else
			return false;
	}

	Date operator++()
	{
		AddDay(1);
		return *this;
	}

	Date operator++(int)
	{
		Date result(this->day, this->month, this->year);
		AddDay(1);
		return result;
	}

	Date DeductDay();

	Date operator--()
	{
		return DeductDay();
	}

	~Date();
};

