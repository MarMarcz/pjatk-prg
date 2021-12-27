#include <vector>
#include <algorithm> //zeby dzialalo fill
#include <cstdlib> //zeby dzialalo rand()
#include <ctime> //zeby dzialalo srand()
//#ifndef saper_h
//#define saper_h

auto v = std::vector<char> (81); //vector ten wyswietlany
auto v_bomb = std::vector<char> (81); //vector ktory zawiera bomby

void generuj_bomby()
{
	std::fill(v_bomb.begin(), v_bomb.end(), 'n');
	short int powtarzaj = 10; //tyle bomb
	srand(time(NULL));
	for (int i = 0; i < powtarzaj; i++) //petla generowania bomb w losowych miejscach
	{
		int r = rand() % 81; //wylosuje losowa liczbe 0-80
		if (v_bomb[r] == 'n')
			v_bomb[r] = 'B';
		else if (v_bomb[r] == 'B') //jesli juz tam byla bomba to powtorz
			powtarzaj++;
	}
}

short int y = 0; //ktory z kolei element wektora

void wyswietl_wiersz()
{
	short int liczba = 0; //ilosc elementow w wierszu pozniej
	while (liczba <= 8) //liczba kolumn -1 //tyle razy chce wsywietlic elemnt w wierszu
	{
		std::cout << v[y];
		y++;
		liczba++;
	}
	if (y == 81)
		y = 0;
}

void wyswietl_wszystkie_pola()
{
	std::cout << " 123456789" << "\n"; //najpeirw wyswietlamy wszystkie kolumny
	for (int i=1; i <= 9; i++ ) //wyswietlaj kazdy wiersz
	{
		std::cout << i; //najpierw numer wiersza
		wyswietl_wiersz();
		std::cout << "\n";
	}
}
//#endif
