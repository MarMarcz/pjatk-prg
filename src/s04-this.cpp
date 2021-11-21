#include <iostream>

struct Str
{
	auto wartosc_this()
	{
		 std::cout << this << "\n";
	}
};

int main()
{
	Str obiekt;
	obiekt.Str::wartosc_this();
	std::cout << &obiekt << "\n";

return 0;
}
