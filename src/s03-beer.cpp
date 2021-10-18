#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
auto beer = std::string{argv[1]};
auto b = std::stoi(beer);
std::cout << b << " bottles of beer on the wall, " << b << " bottles of beer.\n";

for(int i = b - 1; i >= 1; i--)
{
	std::cout << "Take one down, pass it around, " << i << " bottles of beer on the wall...\n";
	std::cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n";
}

std::cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
std::cout << "Go to store and buy some more, " << b << " bottles of beer on the wall...\n";

return 0;
}
