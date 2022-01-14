#include <vector>
#include <string>
#include <algorithm> //zeby dzialalo fill
#include <cstdlib> //zeby dzialalo rand() i exit(0)
#include <ctime> //zeby dzialalo srand()
#include <unistd.h> //zeby dzialalo usleep

auto v = std::vector<char> (81); //vector ten wyswietlany //TU ZMIANA //900
auto v_bomb = std::vector<char> (81); //vector ktory zawiera bomby //TU ZMIANA //900

//pole 30 na 30 //zaznaczam gdzie musze wprowadzic zmiany
//short int rozmiar_pola = 30; //30*30 -> tyle lacznie jest pol 
short int ilosc_bomb = 10;
void generuj_bomby()
{
	std::fill(v_bomb.begin(), v_bomb.end(), 'n');
	short int powtarzaj = ilosc_bomb; //tyle bomb
	srand(time(NULL));
	for (int i = 0; i < powtarzaj; i++) //petla generowania bomb w losowych miejscach
	{
		int r = rand() % 81; //wylosuje losowa liczbe 0-80 //TU ZMIANA //900 //30*30
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
	while (liczba <= 8) //liczba kolumn -1 //tyle razy chce wsywietlic elemnt w wierszu //TU ZMIANA //29 //30-1
	{
		std::cout << v[y];
		y++;
		liczba++;
	}
	if (y == 81) //TU ZMIANA //900 //30*30
		y = 0;
}

void wyswietl_wszystkie_pola()
{
	std::cout << " 123456789" << "\n"; //najpeirw wyswietlamy wszystkie kolumny //TU ZMIANA
	for (int i=1; i <= 9; i++ ) //wyswietlaj kazdy wiersz //TU ZMIANA //30
	{
		std::cout << i; //najpierw numer wiersza
		wyswietl_wiersz();
		std::cout << "\n";
	}
	//for (char& each : v_bomb) //pokazuje kazdy element vectora v_bomb //POMOCNICZE na czas testow
	//{
	//	std::cout << each;
	//}
}

short int ktore_pole(short int &n_w, short int &n_k) // na jakim polu z vectora bedziemy potem dzialac
//czyli obliczamy na jakim indexie bedziemy dzialac, ograniczenie do 81 pol wiec 80 index max
{
	return ( (n_w-1)*9 + (n_k-1) );//zwracamy jakie to bedzie pole vectora (index) //TU ZMIANA //30
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
		if (v_bomb[k_p - 9] == 'B') //TU ZMIANA //30
			return 1;
		else
			return 0;
	} else if (kierunek == "dol")
	{
		if (v_bomb[k_p + 9] == 'B') //TU ZMIANA //30
			return 1;
		else
			return 0;
	} else if (kierunek == "lewo_gora")
	{
		if (v_bomb[k_p - 10] == 'B') //TU ZMIANA //30+1
			return 1;
		else
			return 0;
	} else if (kierunek == "lewo_dol")
	{
		if (v_bomb[k_p + 8] == 'B') //TU ZMIANA //30-1
			return 1;
		else
			return 0;
	}else if (kierunek == "prawo_gora")
	{
		if (v_bomb[k_p - 8] == 'B') //TU ZMIANA //30-1
			return 1;
		else
			return 0;
	} else if (kierunek == "prawo_dol")
	{
		if (v_bomb[k_p + 10] == 'B') //TU ZMIANA //30+1
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

char sprawdz_sasiadujace_pola(short int k_p) //funkcja sprawdzajaca sasiadujece pola zwracajaca ilosc bomb wokol lub . bo nie bedzie bomb
{
	short int ile_bomb; //liczba bomb wokol

	if (k_p == 0) //wierzcholek czyli narazie sprawdzam dla skrajnych przypadkow
	{
		ile_bomb = (sprawdz("prawo", k_p) + sprawdz("dol", k_p) + sprawdz("prawo_dol", k_p)); //sprawdz czy wokol bomby i dodaj je
		return ile(ile_bomb); //tyle mamy bomb wokol
	}
	else if (k_p == 8) //prawy gora wierzchoek //TU ZMIANA //30-1
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("lewo_dol", k_p) + sprawdz("dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 72) //lewa dol wierzcholek //TU ZMIANA //870
	{
		ile_bomb = (sprawdz("gora", k_p) + sprawdz("prawo", k_p) + sprawdz("prawo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 80) //prawy dol wierzcholek //TU ZMIANA //899
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("gora", k_p) + sprawdz("lewo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p >= 1 && k_p <= 7) //pierwzy wiersz bez wierzcholka //TU ZMIANA //28
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("prawo", k_p) + sprawdz("dol", k_p) + sprawdz("lewo_dol", k_p) + sprawdz("prawo_dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p >= 73 && k_p <= 79) //ostatni wiersz bez wierzcholka //TU ZMIANA //871-898
	{
		ile_bomb = (sprawdz("lewo", k_p) + sprawdz("prawo", k_p) + sprawdz("gora", k_p) + sprawdz("lewo_gora", k_p) + sprawdz("prawo_gora", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 9 || k_p == 18 || k_p == 27 || k_p == 36 || k_p == 45 || k_p == 54 || k_p == 63) //lewa kolumna //Pomysl nad optymalizacja!! //TU ZMIANA
	{
//30,60,90,120,150,180,210,240,270,300,330,360,390,420,450,480,510,570,600,630,660,690,720,750,780,810,840
		ile_bomb = (sprawdz("prawo", k_p) + sprawdz("gora", k_p) + sprawdz("dol", k_p) + sprawdz("prawo_gora", k_p) + sprawdz("prawo_dol", k_p));
		return ile(ile_bomb);
	}
	else if (k_p == 17 || k_p == 26 || k_p == 35 || k_p == 44 || k_p == 53 || k_p == 62 || k_p == 71) //prawa kolumna //Pomysl nad optymalizacja!! //TU ZMIANA
	{
//59,89,119,149,179,209,239,269,299,329,359,389,419,449,479,509,569,599,629,659,689,719,749,779,809,839,869
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
