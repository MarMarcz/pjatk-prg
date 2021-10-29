#include <iostream>
#include <string>
#pragma once

struct student
{
	std::string imie, nazwisko, numer_indeksu;
	int aktualny_semestr;
	double srednia_ocen;

	std::string to_string();

	student(std::string i, std::string n, std::string ni, int as, double so);


};

