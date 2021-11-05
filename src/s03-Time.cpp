#include <iostream>
#include <string>
#include "../include/s24566/Time.h"

std::string Time::to_string()
{
	std::string x = std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
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
	if (minute == 59 && second == 59 || minute == 59 && second == 0)
	{
	minute = 0;
	}
	else if(second == 0)
	{
	minute += 1;
	}
}

void Time::next_hour()
{
	if (hour == 23 && minute == 59 && second == 59 || hour == 23 && minute == 0 && second == 0)
	{
	hour = 0;
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
	czas.next_second();
	czas.next_minute();
	czas.next_hour();
	std::cout << czas.to_string() << std::endl;


return 0;
}
