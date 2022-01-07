#include <vector>
#include <string>
#include <algorithm> //zeby dzialalo fill
#include <cstdlib> //zeby dzialalo rand() i exit(0)
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
	for (char& each : v_bomb) //pokazuje kazdy element vectora v_bomb //POMOCNICZE na czas testow
	{
		std::cout << each;
	}
}

short int ktore_pole(short int n_w, short int n_k) // na jakim polu z vectora bedziemy potem dzialac
//czyli obliczamy na jakim indexie bedziemy dzialac, ograniczenie do 81 pol wiec 80 index max
{
	return ( (n_w-1)*9 + (n_k-1) );//zwracamy jakie to bedzie pole vectora (index)
	//obliczenie jak to zrobilam mam na karetce
}

//Tu bedzie funkcja dla Wygranej
void przegrana() //gracz trfil na mine wiec konczy sie gra //pokazuje nam wszystkie pola z minami
{
	for (int i=0; i < v.size(); i++ ) //dla kazdego pola sprawdz
	{
		if (v_bomb[i] == 'B') //jesli byla tam mina to
		{
			if (v[i] == 'X') //sprawdz czy gracz dobrze obstawil jesli tak to
			{
				v[i] = '+';
			}
			else //jesli nie zaznaczyl tego pola jako zaminowane to
				v[i] = '*';
		}
	}
}

short int sprawdz(std::string kierunek, short int k_p) //sprawdza czy w danym kierunku znajduje sie bomba
{
	if (kierunek == "prawo")
	{
		if (v_bomb[k_p + 1] == 'B') //jesli jest tam bomba to zwroc 1
			return 1;
		else
			return 0; //jesli nie ma tam bomby to zwroc 0
	}else if (kierunek == "lewo")
	{
		if (v_bomb[k_p - 1] == 'B')
			return 1;
		else
			return 0;
	}else if (kierunek == "gora")
	{
		if (v_bomb[k_p - 9] == 'B')
			return 1;
		else
			return 0;
	} else if (kierunek == "dol")
	{
		if (v_bomb[k_p + 9] == 'B')
			return 1;
		else
			return 0;
	} else if (kierunek == "lewo_gora")
	{
		if (v_bomb[k_p - 10] == 'B')
			return 1;
		else
			return 0;
	} else if (kierunek == "lewo_dol")
	{
		if (v_bomb[k_p + 8] == 'B')
			return 1;
		else
			return 0;
	}else if (kierunek == "prawo_gora")
	{
		if (v_bomb[k_p - 8] == 'B')
			return 1;
		else
			return 0;
	} else if (kierunek == "prawo_dol")
	{
		if (v_bomb[k_p + 10] == 'B')
			return 1;
		else
			return 0;
	}
	else //na wszelki wypadek
		return 0;

}

char ile(short int a) //sprawdza ile jest bomb i jakby przerzuca to na char ktory poleci potem do vecotra
{
	switch(a)
	{
		case 0: return '.';
			break;
		case 1: return '1';
			break;
		case 2: return '2';
			break;
		case 3: return '3';
			break;
		case 4: return '4';
			break;
		case 5: return '5';
			break;
		case 6: return '6';
			break;
		case 7: return '7';
			break;
		case 8: return '8'; //maksymalnie pole moze byc otoczone 8 bombami
			break;
		default: return '.'; //na wszelki wypadek deafultowy
	}
}

char sprawdz_sasiadujace_pola(short int k_p) //funkcja sprawdzajaca sasiadujece pola zwracajaca ilosc bomb wokol lub . bo nie bedzie bomb
{
	short int ile_bomb; //liczba bomb wokol

	if (k_p == 0) //wierzcholek czyli narazie sprawdzam dla skrajnych przypadkow
	{
		ile_bomb = (sprawdz("prawo", k_p) + sprawdz("dol", k_p) + sprawdz("prawo_dol", k_p)); //sprawdz czy wokol bomby i dodaj je
		return ile(ile_bomb); //tyle mamy bomb wokol
	}
	else if (k_p == 8) //wierzchoek
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("lewo_dol", k_p) + sprawdz("dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 72) //wierzcholek
	{
		ile_bomb = (sprawdz("gora", k_p) + sprawdz("prawo", k_p) + sprawdz("prawo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 80) //wierzcholek
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("gora", k_p) + sprawdz("lewo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p >= 1 && k_p <= 7) //pierwzy wiersz bez wierzcholka
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("prawo", k_p) + sprawdz("dol", k_p) + sprawdz("lewo_dol", k_p) + sprawdz("prawo_dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p >= 73 && k_p <= 79) //ostatni wiersz bez wierzcholka
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("prawo", k_p) + sprawdz("gora", k_p) + sprawdz("lewo_gora", k_p) + sprawdz("prawo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 9 || k_p == 18 || k_p == 27 || k_p == 36 || k_p == 45 || k_p == 54 || k_p == 63) //lewa kolumna //Pomysl nad optymalizacja!!
	{
		ile_bomb = (sprawdz("prawo", k_p) + sprawdz("gora", k_p) + sprawdz("dol", k_p) + sprawdz("prawo_gora", k_p) + sprawdz("prawo_dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 17 || k_p == 26 || k_p == 35 || k_p == 44 || k_p == 53 || k_p == 62 || k_p == 71) //prawa kolumna //Pomysl nad optymalizacja!!
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("gora", k_p) + sprawdz("dol", k_p) + sprawdz("lewo_gora", k_p) + sprawdz("lewo_dol", k_p));
		return ile(ile_bomb);
	}
	else //czyli reszta normalnych co sasiaduja z 8 polami
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("prawo", k_p) + sprawdz("gora", k_p) + sprawdz("dol", k_p) + sprawdz("prawo_gora", k_p) +
			sprawdz("lewo_gora", k_p) + sprawdz("prawo_dol", k_p) + sprawdz("lewo_dol", k_p));
		return ile(ile_bomb);
	}
}

auto akcja(short int k_p, char op) //funkcja dzialania w zaleznosci od operatora (Z, P, F)
{
	switch (op) //dzaialnie w zaleznosci od operatora
	{
		case 'Z': //oznacznei jako mina
		{
			v[k_p] = 'X'; //ocnacz te pole jako zaminowane X
		}
		break;
		case 'P': //odkrywamy pole
		{
			if (v_bomb[k_p] == 'B') //jesli odslonimy bombe to koniec gry //przegrywamy
			{
				przegrana();
				wyswietl_wszystkie_pola();
				exit(0);
			}
			else //inne gdy odslonimy ale nie ma tam bobmy wiec sprawdzy czy z jakimis sasiaduje
			v[k_p] = sprawdz_sasiadujace_pola(k_p);
		}
		break;
		case 'F': //zdjecie oznacznia pola jako zajetego przez mine
		{
			if (v[k_p] == 'X') //jesli zaznaczylsmy wczesniej jako zaminowane -> zdjejmij oznaczenie
				v[k_p] = ' ';
			else
				std::cout << "Pole nie jest oznaczone jako zaminowane wiec nie mozna zdjac oznaczenia\n";
		}
		break;
		default: std::cout << "Zly operator!\n"; //jesli ktos poda cos innego niz Z, P, F
	}
}

//#endif
