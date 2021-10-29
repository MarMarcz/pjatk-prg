#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[])
{
auto number = std::string{argv[1]};
auto n = std::stoi(number);

if ( argc > 2 )
{
std::cerr << "wrong amount of arguments\n";
exit(0);
}

if (n >= 1)
{
	for( int i=1; i <= n ; i++)
	{
		if( i % 3 == 0 && i % 5 == 0 )
		{
		std::cout << i << " FizzBuzz\n";
		}
		if ( i % 3 == 0 && i % 5 != 0 )
		{
		std::cout << i << " Fizz\n";
		}
		if ( i % 3 != 0 && i % 5 == 0 )
		{
		std::cout << i << " Buzz\n";
		} else if( i % 3 != 0 && i % 5 != 0 )
		{
		std::cout << i << std::endl;
		}
	}
}

if (n < 1)
{
	for(int i=1; i >= n ; i--)
	{
		if( i % 3 == 0 && i % 5 == 0 )
		{
		std::cout << i << " FizzBuzz\n";
		}
		if ( i % 3 == 0 && i % 5 != 0 )
		{
		std::cout << i << " Fizz\n";
		}
		if ( i % 3 != 0 && i % 5 == 0 )
		{
		std::cout << i << " Buzz\n";
		} else if ( i % 3 != 0 && i % 5 != 0 )
		{
		std::cout << i << std::endl;
		}
	}
}

return 0;
}
