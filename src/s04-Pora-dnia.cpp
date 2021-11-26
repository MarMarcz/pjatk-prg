#include <iostream>
#include "../include/s24566/Pora-dnia.h"

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

int main()
{
	Time czas(23, 59, 59);
	std::cout << czas.to_string() << "\n";
	std::cout << czas.to_string_timeofday( czas.time_of_day() ) << "\n";
	czas.next_hour();
	czas.next_minute();
	czas.next_second();
	std::cout << czas.to_string() << "\n";
	std::cout << czas.to_string_timeofday( czas.time_of_day() ) << "\n";

return 0;
}
