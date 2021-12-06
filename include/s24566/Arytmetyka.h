#include <string>
#ifndef Arytmetyka_h
#define Arytmetyka_h

struct Time
{
	int hour, minute, second;

	std::string to_string();
	auto operator+(Time const&);
	auto operator-(Time const&);
	bool operator<(Time const&);
	bool operator>(Time const&);
	bool operator==(Time const&);
	bool operator!=(Time const&);

	Time(int h, int m, int s)
	{
	hour=h;
	minute=m;
	second=s;
	}
};
#endif

std::string Time::to_string()
{
	std::string x;
	if (hour < 10)
		x = "0" + std::to_string(hour) + ":";
	else
		x = std::to_string(hour) + ":";
	if (minute < 10)
		x = x + "0" + std::to_string(minute) + ":";
	else
		x = x + std::to_string(minute) + ":";
	if (second < 10)
		x = x + "0" + std::to_string(second);
	else
		x = x + std::to_string(second);
return x;
}

auto look(int h,int m, int s) //funkcja potrzebna do wydrukowania godziny po + v -
{
        if ( h >= 24 )
                h = h-24;
        if ( h < 10 )
                std::cout << "0" << h << ":";
        else
                std::cout << h << ":";
        if ( m < 10 )
                std::cout << "0" << m << ":";
        else
                std::cout << m << ":";
        if ( s < 10 )
                std::cout << "0" << s << "\n";
        else
                std::cout << s << "\n";
}


auto operator+(Time const& a, Time const& b)
{
	int h,m,s;//pomocnicze zmienne
	s = a.second + b.second;
	m = a.minute + b.minute;
	h = a.hour + b.hour;
	//check
	if ( s >= 60 )
	{
		s = s-60;
		m++;
	}
	if ( m >= 60 )
	{
		m = m-60;
		h++;
	}
	if ( h >= 24 )
		h = h-24;
	look(h, m, s);
}

auto operator-(Time const& a, Time const& b)
{
	int h,m,s;//znow pomocnicze zmienne
	s = a.second - b.second;
	m = a.minute - b.minute;
	h = a.hour - b.hour;
	//check
	if ( s < 0 )
	{
	s = s+60;
	m = m-1;
	}
	if ( m < 0)
	{
	m = m+60;
	h = h-1;
	}
	if ( h < 0 )
	h = h+24;
	look(h, m, s);
}

bool operator<(Time const& a, Time const& b)
{
	if ( (a.hour < b.hour) || (a.hour == b.hour && a.minute < b.minute) ||
	(a.hour == b.hour && a.minute == b.minute && a.second < b.second) )
	return true;
	else
	return false;
}

bool operator>(Time const& a, Time const& b)
{
	if ( (a.hour > b.hour) || (a.hour == b.hour && a.minute > b.minute) ||
	(a.hour == b.hour && a.minute == b.minute && a.second > b.second) )
	return true;
	else
	return false;
}

bool operator==(Time const& a, Time const& b)
{
	if( (a.hour == b.hour) && (a.minute == b.minute) && (a.second == b.second) )
	return true;
	else
	return false;
}

bool operator!=(Time const& a, Time const& b)
{
	if ( (a.hour != b.hour) || (a.minute != b.minute) || (a.second != b.second) )
	return true;
	else
	return false;
}

auto show(bool x)
{
	if (x == true)
	std::cout << "true\n";
	else
	std::cout << "false\n";
}
