#include <string>
#ifndef Pora_dnia_h
#define Pora_dnia_h

enum class Time_of_day {rano, popoludnie, wieczor, noc};
//rano 06:00 - 11:59
//popoludnie 12:00 - 17:59
//wiwczor 18:00 - 23:59
//noc 00:00 - 05:59

struct Time {

int hour, minute, second;

std::string to_string(); // drukuje HH:MM:SS
std::string to_string_timeofday(Time_of_day); //drukuje pore dnia
void next_hour();
void next_minute();
void next_second();
Time_of_day time_of_day() const; //zwraca nam jaka jest pora dnia


Time(int h, int m, int s)
{
hour = h;
minute = m;
second = s;
}

};
#endif

void Time::next_second()
{
        if (second == 59)
        {
                second = 0;
        }
        else {
                second += 1;
        }
}

void Time::next_minute()
{
        if (minute == 59 && second == 59)
        {
                minute = 0;
        }
        else if(second == 59)
        {
                minute += 1;
        }
}

void Time::next_hour()
{
        if (hour == 23 && minute == 59 && second == 59)
        {
                hour = 0;
        }
        else if(minute == 59 && second == 59)
        {
                hour += 1;
        }
}

Time_of_day Time::time_of_day() const
{
	if (hour >= 6 && hour < 12)
	{
		return Time_of_day::rano;
	} else if (hour >= 12 && hour < 18)
	{
		return Time_of_day::popoludnie;
	} else if (hour >= 18 && hour < 24)
	{
		return Time_of_day::wieczor;
	} else if (hour >= 0 && hour < 6)
	{
		return Time_of_day::noc;
	}
}

std::string Time::to_string_timeofday(Time_of_day o)
{
	if ( o == Time_of_day::rano)
	{
		return "rano";
	} else if ( o == Time_of_day::popoludnie)
	{
		return "popoludnie";
	} else if ( o == Time_of_day::wieczor)
	{
		return "wieczor";
	} else if ( o == Time_of_day::noc)
	{
		return "noc";
	}
}

