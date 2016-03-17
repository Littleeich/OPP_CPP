#pragma once
class Time
{
	short hours;
	short minutes;
	short seconds;

public:
	void SetSeconds(short seconds);
	void SetMinutes(short minutes);
	void SetHours(short hours);

	Time(short hours, short minutes, short seconds);
	Time(short hours, short minutes) :Time(hours, minutes, 0){};
	Time(short hours) :Time(hours, 0, 0){};
	Time() :Time(0, 0, 0){};
	~Time();

	short GetSeconds() const { return seconds; };
	short GetMinutes() const { return minutes; };
	short GetHours() const { return hours; };

	void AddSeconds(short seconds);
	void AddMinutes(short minutes);
	void AddHours(short hours);

	void DeductSeconds(short seconds);
	void DeductMinutes(short minutes);
	void DeductHours(short hours);

	Time operator+(const Time & time){
		Time result;
		result.AddSeconds(this->seconds + time.GetSeconds());
		result.AddMinutes(this->minutes + time.GetMinutes());
		result.AddHours(this->hours + time.GetHours());
		return result;
	}

	Time operator-(const Time & time){
		Time result(this->hours, this->minutes, this->seconds);
		result.DeductSeconds(time.GetSeconds());
		result.DeductMinutes(time.GetMinutes());
		result.DeductHours(time.GetHours());
		return result;
	}

	Time operator+=(const Time & time){
		AddSeconds(time.GetSeconds());
		AddMinutes(time.GetMinutes());
		AddHours(time.GetHours());
		return *this;
	}

	Time operator-=(const Time & time){
		DeductSeconds(time.GetSeconds());
		DeductMinutes(time.GetMinutes());
		DeductHours(time.GetHours());
		return *this;
	}

	bool operator==(const Time & time)
	{
		if (this->hours == time.hours && this->minutes == time.minutes && this->seconds == time.seconds)
			return true;
		else
			return false;
	}

	bool operator!=(const Time & time)
	{
		if (this->hours != time.hours || this->minutes != time.minutes || this->seconds != time.seconds)
			return true;
		else
			return false;
	}

	bool operator>(const Time & time)
	{
		if (this->hours > time.hours)
			return true;
		else if (this->hours < time.hours)
			return false;
		else if (this->minutes > time.minutes)
			return true;
		else if (this->minutes < time.minutes)
			return false;
		else if (this->seconds > time.seconds)
			return true;
		else 
			return false;
	}

	bool operator<(const Time & time)
	{
		if (this->hours < time.hours)
			return true;
		else if (this->hours > time.hours)
			return false;
		else if (this->minutes < time.minutes)
			return true;
		else if (this->minutes > time.minutes)
			return false;
		else if (this->seconds < time.seconds)
			return true;
		else
			return false;
	}

	Time operator++()
	{
		AddSeconds(1);
		return *this;
	}

	Time operator--()
	{
		DeductSeconds(1);
		return *this;
	}

	Time operator++(int)
	{
		Time temp(hours, minutes, seconds);
		AddSeconds(1);
		return temp;
	}

	Time operator--(int)
	{
		Time temp(hours, minutes, seconds);
		DeductSeconds(1);
		return temp;
	}
};


