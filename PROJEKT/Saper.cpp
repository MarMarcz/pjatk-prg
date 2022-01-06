#include <iostream>
#include "./saper.h"

//najpeirw testuje sobie na mniejszej planszy 9 na 9

int main()
{
	std::fill(v.begin(), v.end(), ' ');
	generuj_bomby();
	wyswietl_wszystkie_pola();
	//std::cout << "\n";

	short int nr_wiersza, nr_kolumny;
	char operacja;

	while (true)
	{
		std::cout << "\nWpisz: nr.wiersza, nr.kolumny, dzialanie\n";
		std::cout << "Dzialanie:\nZ-mina  P-odsloniecie pola  F-zdjecie oznaczenia pola jako zajetego przez mine\n";

		try {
			std::cin >> nr_wiersza >> nr_kolumny >> operacja;

			if (std::cin.fail() || nr_wiersza > 9 || nr_wiersza < 1 || nr_kolumny > 9 || nr_kolumny < 1)
			{
				std::cin.clear();
				throw "Zle dane";
			}
		} catch (...) {
			std::cout << "Zle dane!\n";
			return 0;
		}

		akcja( ktore_pole(nr_wiersza, nr_kolumny), operacja);
		wyswietl_wszystkie_pola();
	}
return 0;
}
