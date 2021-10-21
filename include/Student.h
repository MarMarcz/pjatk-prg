#include <iostream>
#include <string>

struct student
{
	std::string imię;
	std::string nazwisko;
	std::string numer_indeksu;
	int aktualny_semestr;
	double średnia_ocen;

	std::string to_string() const
	{
		std::cout << "imię: " << imię << "\n" << "nazwisko: " << nazwisko << "\n";
		std::cout << "numer indeksu: " << numer_indeksu << "\n" << "aktualny semestr: " << aktualny_semestr << "\n" << "średnia ocen: " << średnia_ocen << "\n";
	}

	student(std::string, int, double)
};

student::student(std::string i, std::string n, std::string ni, int as, double śo)
: imię{i}, nazwisko{n}, numer_indeksu{ni}, aktualny_semestr{as}, średnia_ocen{śo}

