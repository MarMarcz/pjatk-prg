#include <iostream>
#include <string>
#include "../include/s24566/Time.h"

std::string Time::to_string()
{
	std::string x;
	if (hour <= 9)
	{
	x = "0" + std::to_string(hour) + ":";
	}
	else if (hour > 9)
	{
	x = std::to_string(hour) + ":";
	}
	if (minute <= 9)
	{
	x = x + "0" + std::to_string(minute) + ":";
	}
	else if(minute > 9)
	{
	x = x + std::to_string(minute) + ":";
	}
	if (second <=9)
	{
	x = x + "0" + std::to_string(second);
	}
	else if(second > 9)
	{
	x = x + std::to_string(second);
	}
return x;
}

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

Time::Time(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}

int main()
{
	Time czas(23, 59, 59);
	std::cout << czas.to_string() << std::endl;
	czas.next_hour();
	czas.next_minute();
	czas.next_second();
	std::cout << czas.to_string() << std::endl;

return 0;
}
