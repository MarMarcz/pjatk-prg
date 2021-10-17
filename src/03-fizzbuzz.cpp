#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
auto number = std::string{argv[1]};
auto n = std::stoi(number);

if (n > 1)
{
	for( int i=1; i <= n ; i++)
	{
	std::cout << i << std::endl;
	}
}

if (n < 1)
{
	for(int i=1; i >= n ; i--)
	{
	std::cout << i << std::endl;
	}
}

if ( n % 3 == 0 && n % 5 != 0 )
{
	std::cout << "Fizz\n";
}
if ( n % 5 == 0 && n % 3 != 0)
{
	std::cout << "Buzz\n";
}
if ( n % 3 == 0 && n % 5 == 0 )
{
	std::cout << "FizzBuzz\n";
}
return 0;
}
