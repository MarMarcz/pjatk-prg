#include <iostream>
#include "./saper.h"

//najpeirw testuje sobie na mniejszej planszy 9 na 9

int main()
{
	std::fill(v.begin(), v.end(), '.');
	generuj_bomby();
	wyswietl_wszystkie_pola();
	std::cout << "\n";

	short int nr_wiersza, nr_kolumny;
	char operacja;

	std::cin >> nr_wiersza >> nr_kolumny >> operacja; //tu musze dorobic obslugiwalnosc bledow
	akcja( ktore_pole(nr_wiersza, nr_kolumny), operacja);
	wyswietl_wszystkie_pola();

return 0;
}
