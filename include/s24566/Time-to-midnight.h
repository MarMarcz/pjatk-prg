#include <iostream>
#include <string>
#ifndef Time_to_midnight_h
#define Time_to_midnight_h

struct Time
{
        int hour;
        int minute;
        int second;

        std::string to_string();

        void next_hour();
        void next_minute();
        void next_second();

	int count_seconds(); //liczy sekundy od 00:00:00
	int count_minutes(); //liczy minuty od 00:00:00
	void time_to_midnight(); //liczy ile zostało do północy

        Time(int h, int m, int s);

};
#endif

