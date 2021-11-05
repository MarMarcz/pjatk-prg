#include <iostream>
#include <string>
#ifndef Time_h
#define Time_h

struct Time
{
	int hour;
	int minute;
	int second;

	std::string to_string();
	void next_hour();
	void next_minute();
	void next_second();

	Time(int h, int m, int s);

};
#endif
