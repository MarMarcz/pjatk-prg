
#include <iostream>
#include <string>
#include "../include/s24566/Time-to-midnight.h"

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

int Time::count_seconds()
{
	return ( (hour*3600) + (minute*60) + second );
}

int Time::count_minutes()
{
	return ((hour*60) + minute);
}

void Time::time_to_midnight()
{
	if ( minute > 0 | second > 0)
	{
		std::cout << "Hour to midnight: " << (24-hour-1) << "\nMinutes to midnight: " <<
		(60-minute-1) << "\nSeconds to midnight: " << (60-second) << "\n";
	} else if (minute == 0 && second == 0) {
	std::cout << "Hour to midnight: " << (24-hour) << "\nMinutes to midnight: " <<
                0 << "\nSeconds to midnight: " << 0 << "\n";
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
	czas.count_seconds();
	czas.count_minutes();
	czas.time_to_midnight();

return 0;
}

