#include <iostream>
#include <string>
#ifndef Student_h
#define Student_h

struct Student
{
	std::string imie, nazwisko, numer_indeksu;
	int semestr;
	double srednia_ocen;

	std::string to_string();

	Student(std::string i, std::string n, std::string ni, int as, double so);
};
#endif
