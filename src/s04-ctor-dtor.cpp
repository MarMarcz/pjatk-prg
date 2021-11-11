#include <iostream>
#include <string>

struct Something
{
	std::string napis;

	Something(std::string n)
	{
	napis = n;
	}
	~Something()
	{
	std::cout << napis << "\nDESTRUCTION!\n";
	}
};

int main()
{
	Something obiekt("napis");

return 0;
}
