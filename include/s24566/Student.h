#include <iostream>
#include <string>

struct student
{
	std::string imie;
	std::string nazwisko;
	std::string numer_indeksu;
	int aktualny_semestr;
	double srednia_ocen;

	std::string to_string() const
	{
	return std::string;
	};

	student(std::string, int, double);
};

student::student(std::string i, std::string n, std::string ni, int as, double so)
: imie{i}, nazwisko{n}, numer_indeksu{ni}, aktualny_semestr{as}, srednia_ocen{so}

