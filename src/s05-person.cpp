#include <iostream>
#include "../include/s24566/Person.h"


int main()
{
Mr rob("Robert" , "Maklowicz" );
Mrs mag("Magda" , "Gessler" );
Queen el("Elizabeth", "Mary");
King st("Stephen", "King");

Hello hello;
Good_evening good_evening;
Farewell farewell;

std::cout << who_is_it(rob) << "\n";
std::cout << who_is_it(mag) << "\n";
std::cout << who_is_it(el) << "\n";
std::cout << who_is_it(st) << "\n";
std::cout << hello.greet(mag) << "\n";
std::cout << good_evening.greet(st) << "\n";
std::cout << farewell.greet(el) << "\n";

return 0;
}
