#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
auto password = std::string{argv[1]};
auto write = std::string{};

do {
std::cout << "password:";
std::getline(std::cin, write);
} while (write != password);

std::cout << "ok!\n";

return 0;
}
