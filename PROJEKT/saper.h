#include <vector>
#include <string>
#include <algorithm> //zeby dzialalo fill
#include <cstdlib> //zeby dzialalo rand() i exit(0)
#include <ctime> //zeby dzialalo srand()
#include <unistd.h> //zeby dzialalo usleep

short int rozmiar_pola = 30; //pole 30 na 30 //30*30 -> tyle lacznie jest pol

auto v = std::vector<char> (rozmiar_pola*rozmiar_pola); //vector ten wyswietlany //900
auto v_bomb = std::vector<char> (rozmiar_pola*rozmiar_pola); //vector ktory zawiera bomby //900

short int ilosc_bomb = 15;

void generuj_bomby()
{
	std::fill(v_bomb.begin(), v_bomb.end(), 'n');
	short int powtarzaj = ilosc_bomb; //tyle bomb
	srand(time(NULL));
	for (int i = 0; i < powtarzaj; i++) //petla generowania bomb w losowych miejscach
	{
		int r = rand() % (rozmiar_pola * rozmiar_pola); //wylosuje losowa liczbe 0-899 //900 //30*30
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
	while (liczba <= (rozmiar_pola-1)) //liczba kolumn -1 //tyle razy chce wsywietlic elemnt w wierszu //29
	{
		std::cout << v[y] << "|";
		y++;
		liczba++;
	}
	if (y == rozmiar_pola*rozmiar_pola) //900 //30*30
		y = 0;
}

void wyswietl_wszystkie_pola()
{
	std::cout << "  1 2 3 4 5 6 7 8 9 101112131415161718192021222324252627282930" << "\n"; //najpeirw wyswietlamy wszystkie kolumny
	for (int i=1; i <= rozmiar_pola; i++ ) //wyswietlaj kazdy wiersz //30
	{
		if (i < 10)
			std::cout << " " << i;  //najpierw numer wiersza
		else
			std::cout << i;
		wyswietl_wiersz();
		std::cout << "\n";
	}
	//for (char& each : v_bomb) //pokazuje kazdy element vectora v_bomb //POMOCNICZE na czas testow
	//{
	//	std::cout << each;
	//}
}

short int ktore_pole(short int &n_w, short int &n_k) // na jakim polu z vectora bedziemy potem dzialac
//czyli obliczamy na jakim indexie bedziemy dzialac, ograniczenie do 900 pol wiec 899 index max
{
	return ( (n_w-1)*rozmiar_pola + (n_k-1) );//zwracamy jakie to bedzie pole vectora (index)
	//obliczenie jak to zrobilam mam na karetce
}

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

bool wygrana() //funkcja sprawdzajaca czy wygralismy
{
	short int l_p_o = 0; //liczba poprawnych oznaczen bomb
	for (int i=0; i<v.size(); i++)
	{
		if (v_bomb[i] == 'n' && v[i] == 'X')//jesli nie ma tam bomby a my sie pomylilismy i zaznaczylosmy jakby byla tam bomba
			return false; //to zwroc falsz i nie wygralismy jeszcze bo mamy blad
		else if (v_bomb[i] == 'B' && v[i] == 'X')
		{
			l_p_o = l_p_o + 1;
		}
	}
	if (l_p_o == ilosc_bomb)
		return true;
	else
		return false;
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
		if (v_bomb[k_p - rozmiar_pola] == 'B') //30
			return 1;
		else
			return 0;
	} else if (kierunek == "dol")
	{
		if (v_bomb[k_p + rozmiar_pola] == 'B') //30
			return 1;
		else
			return 0;
	} else if (kierunek == "lewo_gora")
	{
		if (v_bomb[k_p - (rozmiar_pola + 1) ] == 'B')  //30+1
			return 1;
		else
			return 0;
	} else if (kierunek == "lewo_dol")
	{
		if (v_bomb[k_p + (rozmiar_pola - 1)] == 'B') //30-1
			return 1;
		else
			return 0;
	}else if (kierunek == "prawo_gora")
	{
		if (v_bomb[k_p - (rozmiar_pola - 1)] == 'B') //30-1
			return 1;
		else
			return 0;
	} else if (kierunek == "prawo_dol")
	{
		if (v_bomb[k_p + (rozmiar_pola + 1)] == 'B') //30+1
			return 1;
		else
			return 0;
	}
	else //na wszelki wypadek
		return 0;

}

char ile(short int const& a) //sprawdza ile jest bomb i jakby przerzuca to na char ktory poleci potem do vecotra
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

char sprawdz_sasiadujace_pola(short int const& k_p) //funkcja sprawdzajaca sasiadujece pola zwracajaca ilosc bomb wokol lub . bo nie bedzie bomb
{
	short int ile_bomb; //liczba bomb wokol

	if (k_p == 0) //leaw gora wierzcholek czyli narazie sprawdzam dla skrajnych przypadkow
	{
		ile_bomb = (sprawdz("prawo", k_p) + sprawdz("dol", k_p) + sprawdz("prawo_dol", k_p)); //sprawdz czy wokol bomby i dodaj je
		return ile(ile_bomb); //tyle mamy bomb wokol
	}
	else if (k_p == (rozmiar_pola-1)) //prawy gora wierzchoek //30-1
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("lewo_dol", k_p) + sprawdz("dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == (rozmiar_pola*rozmiar_pola)-rozmiar_pola) //lewa dol wierzcholek //870
	{
		ile_bomb = (sprawdz("gora", k_p) + sprawdz("prawo", k_p) + sprawdz("prawo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == ( (rozmiar_pola * rozmiar_pola)-1) ) //prawy dol wierzcholek //899
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("gora", k_p) + sprawdz("lewo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p >= 1 && k_p <= (rozmiar_pola - 2)) //pierwzy wiersz bez wierzcholka //28
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("prawo", k_p) + sprawdz("dol", k_p) + sprawdz("lewo_dol", k_p) + sprawdz("prawo_dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p >= ((rozmiar_pola * rozmiar_pola) - rozmiar_pola + 1) && k_p <= (rozmiar_pola * rozmiar_pola)-2) //ostatni wiersz bez wierzcholka //871-898
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("prawo", k_p) + sprawdz("gora", k_p) + sprawdz("lewo_gora", k_p) + sprawdz("prawo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 30 || k_p == 60 || k_p == 90 || k_p == 120 || k_p == 150 || k_p == 180 || k_p == 210 ||
		k_p == 240 || k_p == 270 || k_p == 300 || k_p == 330 || k_p == 360 || k_p == 390 || k_p == 420 ||
		k_p == 450 || k_p == 480 || k_p == 510 || k_p == 570 || k_p == 600 || k_p == 630 || k_p == 660 ||
		k_p == 690 || k_p == 720 || k_p == 750 || k_p == 780 || k_p == 810 || k_p == 840) //lewa kolumna //Pomysl nad optymalizacja!!
	{
		ile_bomb = (sprawdz("prawo", k_p) + sprawdz("gora", k_p) + sprawdz("dol", k_p) + sprawdz("prawo_gora", k_p) + sprawdz("prawo_dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 59 || k_p == 89 || k_p == 119 || k_p == 149 || k_p == 179 || k_p == 209 || k_p == 239 ||
		k_p == 269 || k_p == 299 || k_p == 329 || k_p == 359 || k_p == 389 || k_p == 419 || k_p == 449 ||
		k_p == 479 || k_p == 509 || k_p == 569 || k_p == 599 || k_p == 629 || k_p == 659 || k_p == 689 ||
		k_p == 719 || k_p == 749 || k_p == 779 || k_p == 809 || k_p == 839 || k_p == 869) //prawa kolumna //Pomysl nad optymalizacja!!
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

auto akcja(short int const&  k_p, char op) //funkcja dzialania w zaleznosci od operatora (Z, P, F)
{
	switch (op) //dzaialnie w zaleznosci od operatora
	{
		case 'Z': //oznacznei jako mina //Nie mozna zaznaczyc odkrytych pol
		{
			if (v[k_p] == ' ') //jesli pole jest jeszcze nie okryte
			v[k_p] = 'X'; //ocnacz te pole jako zaminowane X
			else //jesli pole juz bylo odkryte
			{
			std::cout << "Pole jest juz odkryte. Nie mozna zaznaczyc jako bomba!\n";
			usleep(2000000);
			}
		}
		break;
		case 'P': //odkrywamy pole
		{
			if (v[k_p] == 'X')
			{
				std::cout << "Nie mozna odkryc pola oznaczonego jako bomba!\n";
				usleep(2000000);
			}
			else if (v_bomb[k_p] == 'B') //jesli odslonimy bombe to koniec gry //przegrywamy
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
			{
				std::cout << "Pole nie jest oznaczone jako zaminowane wiec nie mozna zdjac oznaczenia\n";
				usleep(2000000);
			}
		}
		break;
		default:
		{
			std::cout << "Zly operator!\n"; //jesli ktos poda cos innego niz Z, P, F
			usleep(2000000);
		}
	}
}
