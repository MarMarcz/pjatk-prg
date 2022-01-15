#include <iostream>
#include "./saper.h"

int main()
{
	std::fill(v.begin(), v.end(), ' ');
	generuj_bomby();

	short int nr_wiersza, nr_kolumny;
	char operacja;

	while (true)
	{
		system("clear");
		wyswietl_wszystkie_pola();
		std::cout << "\nWPISZ: nr.wiersza nr.kolumny dzialanie (PO SPACJI)\n";
		std::cout << "( MOZLIWE DZIALANIA:  Z-mina  P-odsloniecie pola  F-zdjecie oznaczenia pola jako zajetego przez mine )\n";

		try { //wpisujemy jaka akcje chcemy wykonac
			std::cin >> nr_wiersza >> nr_kolumny >> operacja;

			if (std::cin.fail() || nr_wiersza > rozmiar_pola || nr_wiersza < 1 || nr_kolumny > rozmiar_pola || nr_kolumny < 1)
			{
				std::cin.clear();
				throw "Zle dane";
			}
		} catch (...) {
			std::cout << "Zle dane!\n";
			return 0;
		}

		akcja( ktore_pole(nr_wiersza, nr_kolumny), operacja);

		if (wygrana() == true)
		{
			std::cout << "GRATULACJE, WYGRALES!\n";
			wyswietl_wszystkie_pola();
			exit(0);
		}
	}
return 0;
}
