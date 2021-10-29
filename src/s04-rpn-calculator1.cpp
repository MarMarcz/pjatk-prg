#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

int main(int argc, char *argv[])
{

 if ( argc != 4 && argc != 3)
{
	std::cerr << "wrong amount of arguments\n";
	exit(0);
}
float a = std::stof(argv[1]);

if ( argc == 4 )
{
	float b = std::stof(argv[2]);
	int x = std::stoi(argv[1]);
	int y = std::stoi(argv[2]);
	std::string op = argv[3];

	if (op == "+")
	{
		std::cout << a + b << std::endl;
	} else if ( op == "-" )
	{
		std::cout << a - b << std::endl;
	} else if ( op == "*" )
	{
		std::cout << a * b << std::endl;
	} else if( op == "/")
	{
		std::cout << a / b << std::endl;
	} else if ( op == "//" )
	{
		std::cout << round(a / b) << std::endl;
	} else if ( op == "%")
	{
		std::cout << x % y << std::endl;
	} else {
	std::cerr << "wrong operator\n";
	}
}
if ( argc == 3 )
{
	std::string opop = argv[2];

	if ( opop == "sqrt" )
	{
		std::cout << sqrt(a) << std::endl;
	} else if ( opop == "abs" )
	{
		std::cout << abs(a) << std::endl;
	} else {
	std::cerr << "wrong operator\n";
	}
}
return 0;
}
