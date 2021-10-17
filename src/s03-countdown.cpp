#include <iostream>
#include <string>

int main(int argc,char* argv[])
{
auto number = std::string{argv[1]};
auto n = std::stoi(number);

if (n > 0)
{
for ( int i=n; i >=0 ; i--)
{
std::cout << i << "...\n";
}

}

if (n <= 0)
{
for ( int i=n; i <=0; i++)
{
std::cout << i << "...\n";
}

}
return 0;
}
