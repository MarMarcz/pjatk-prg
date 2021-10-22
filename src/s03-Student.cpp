#include <iostream>
#include <string>
#include "../include/s24566/Student.h"

int main()
{
auto me = student{};
me.imie = "Martyna";
me.nazwisko = "Marczak";
me.numer_indeksu = "24566";
me.aktualny_semestr = 1;
me.srednia_ocen = 4.2;

std::cout << student::to_string(me);
return 0;
}
