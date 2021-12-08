#include <iostream>
#include "../include/s24566/Person.h"


int main()
{
Mr rob("Robert" , "Maklowicz" );
Mrs mag("Magda" , "Gessler" );
Queen el("Elizabeth", "Mary");
King st("Stephen", "King");

std::cout << who_is_it(rob) << "\n";
std::cout << who_is_it(mag) << "\n";
std::cout << who_is_it(el) << "\n";
std::cout << who_is_it(st) << "\n";

return 0;
}
