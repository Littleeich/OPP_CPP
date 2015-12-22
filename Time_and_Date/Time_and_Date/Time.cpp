#include "Time.h"

void Time::SetHours(short hours)
{
	if (hours < 0)
		this->hours = 0;
	else if (hours > 23)
		this->hours = hours % 24;
	else
		this->hours = hours;
}

void Time::SetMinutes(short minutes)
{
	if (minutes < 0)
		this->minutes = 0;
	else if (minutes > 59)
		this->minutes = minutes % 60;
	else
		this->minutes = minutes;
}

void Time::SetSeconds(short seconds)
{
	if (seconds < 0)
		this->seconds = 0;
	else if (seconds > 59)
		this->seconds = seconds % 60;
	else
		this->seconds = seconds;
}

Time::Time(short hours, short minutes, short seconds)
{
	SetSeconds(seconds);
	SetMinutes(minutes);
	SetHours(hours);
}

void Time::AddHours(short hours)
{
	if (this->hours + hours > 24)
	{
		//for future : AddDays((this->minutes + minutes) / 24);
		this->hours = (this->hours + hours) % 24;
	}
	else
		this->hours += hours;
}

void Time::AddMinutes(short minutes)
{
	if (this->minutes + minutes > 59)
	{
		AddHours((this->minutes + minutes) / 60);
		this->minutes = (this->minutes + minutes) % 60;
	}
	else
		this->minutes += minutes;
}

void Time::AddSeconds(short seconds)
{
	if (this->seconds + seconds > 59)
	{
		AddMinutes((this->seconds + seconds) / 60);
		this->seconds = (this->seconds + seconds) % 60;
	}
	else
		this->seconds += seconds;
}

void Time::DeductSeconds(short seconds)
{
	if (this->seconds - seconds < 0)
	{
		DeductMinutes((this->seconds - seconds) / -60);
		// без магических чисел тут никак... в минуте 60 секунд, поэтому всюду мигает 60
		this->seconds = this->seconds + 60 - (seconds % 60);
	}
	else
		this->seconds -= seconds;
}

void Time::DeductMinutes(short minutes)
{
	if (this->minutes - minutes < 0)
	{
		DeductHours((this->minutes - minutes) / -60);
		// без магических чисел тут никак... в часе 60 минут, поэтому всюду мигает 60
		this->minutes = this->minutes + 60 - (minutes % 60);
	}
	else
		this->minutes -= minutes;
}

void Time::DeductHours(short hours)
{
	if (this->hours - hours < 0)
	{
		DeductHours((this->hours - hours) / -24);
		// без магических чисел тут никак... в сутках 24 часа, поэтому всюду мигает 24
		this->hours = this->hours + 24 - (hours % 24);
	}
	else
		this->hours -= hours;
}

Time::~Time()
{
}
