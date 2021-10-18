#include <iostream>
#include <string>

int main(int argc, char* argv[])
{

if(argv[1] == std::string{"-n"})
{
	for (int i = 2; i <= argc; i++)
	{
	std::cout << argv[i] << " ";
	}
}

if(argv[1] == std::string{"-l"})
{
	for( int i=2; i <= argc; i++)
	{
	std::cout << argv[i] << std::endl;
	}
}

 else {
	for(int i=1; i <= argc; i++)
	{
	std::cout << argv[i] << " ";
	}
}
return 0;
}
