#include <iostream>
#include <string>
#include "../include/s24566/Student.h"

std::string Student::to_string()
{
	std::string x = "imie:" + imie + " " + "nazwisko:" + nazwisko + " " + "numer indeksu:"
 	+ numer_indeksu + " " + "semestr:" + std::to_string(semestr) + " " + "srednia ocen:" + std::to_string(srednia_ocen);
return x;
}

Student::Student(std::string i, std::string n, std::string ni, int s, double so)
{
	imie = i;
	nazwisko = n;
	numer_indeksu = ni;
	semestr = s;
	srednia_ocen = so;
}

int main()
{
	Student st("Martyna", "Marczak", "24566", 1, 4.1);
	std::cout << st.to_string() << std::endl;

return 0;
}
