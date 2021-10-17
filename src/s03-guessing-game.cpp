#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int ask_user_for_integer(std::string promt)
{
std::cout << promt;
auto guess_n = std::string{};
std::getline(std::cin, guess_n);
return std::stoi(guess_n);
}

int main()
{
srand(time(NULL));
int n = (rand() % 100 + 1);
int a;
do
{
a = ask_user_for_integer("guess:");
if (a > n)
{
std::cout << "number is too big!\n";
}
if (a < n)
{
std::cout << "number is too small!\n";
}
} while (a != n);

std::cout << "Well done :D\n";
return 0;
}
