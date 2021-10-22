#include <iostream>
#include <string>

int main(int argc, char* argv[])
{

if(argv[1] == std::string{"-n"} && argv[2] != std::string{"-r"})
{
	for (int i = 2; i <= argc; i++)
	{
	std::cout << argv[i] << " ";
	}
}
if(argv[1] == std::string{"-r"} && argv[2] != std::string{"-l"} && argv[2] != std::string{"-n"})
{
	for( int i = argc; i >= 3; i--)
	{
	std::cout << argv[i-1] << " ";
	}
}

if(argv[1] == std::string{"-l"} && argv[2] != std::string{"-r"})
{
	for( int i = 2; i <= argc; i++)
	{
	std::cout << argv[i] << std::endl;
	}
}

if(argv[1] == std::string{"-l"} && argv[2] == std::string{"-r"} || argv[1] == std::string{"-r"} && argv[2] == std::string{"-l"})
{
	for (int i = argc; i>=4; i--)
	{
	std::cout << argv[i-1] << std::endl;
	}
}
if(argv[1] == std::string{"-n"} && argv[2] == std::string{"-r"} || argv[1] == std::string{"-r"} && argv[2] == std::string{"-n"})
{
        for (int i = argc; i>=4; i--)
        {
        std::cout << argv[i-1] << " ";
        }
}



return 0;
}
