#include <iostream>
#include <string>

int main()
{
auto name = std::string{};
std::getline(std::cin, name);

std::cout << "Hello, " << name << "!\n";
return 0;
}
