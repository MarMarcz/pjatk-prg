#include <iostream>
#include "../include/s24566/Arytmetyka.h"

int main()
{
Time czas1(23, 5, 59);
Time czas2(14, 11, 11);

std::cout << "Time 1: " << czas1.to_string();
std::cout << "\nTime 2: " << czas2.to_string();

std::cout << "\noperator+ ";
operator+(czas1, czas2);

std::cout << "operator- ";
operator-(czas1, czas2);

std::cout << "operator< ";
show( operator<(czas1, czas2) );

std::cout << "operator> ";
show( operator>(czas1, czas2) );

std::cout << "operator== ";
show( operator==(czas1, czas2) );

std::cout << "operator!= ";
show( operator!=(czas1, czas2) );

return 0;
}
