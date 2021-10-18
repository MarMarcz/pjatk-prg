#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
auto first = std::string{argv[1]};
auto f = std::stoi(first);
int x = argc;

for ( int i=f; i <= x; i++)
{
std::cout << i << "\n";
}

return 0;
}
