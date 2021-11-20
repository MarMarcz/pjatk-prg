#include <iostream>
#include "../include/s24566/ListOfStudents.h"
#include <vector>
#include <unistd.h> // zeby dzialalo usleep

auto v = std::vector <Student> {}; // vektor obiektow

std::string imiee;
std::string nazwiskoo;
std::string indexx;
int semestrr;
float sredniaa; // to zmienne na potrzeby funkcji dodaj_studenta
int dzialanie; // do switcha

Student::Student(std::string im, std::string n, std::string in, int se, float sr)
{
imie = im;
nazwisko = n;
index = in;
semestr = se;
srednia = sr;
}

void dodaj_studenta()
{
std::cout << "Wpisz imie: ";
std::cin >>  imiee;
std::cout << "Wpisz nazwisko: ";
std::cin >> nazwiskoo;
std::cout << "Wpisz index: ";
std::cin >> indexx;
std::cout << "Wpisz semestr: ";
std::cin >> semestrr;
std::cout << "Wpisz srednia: ";
std::cin >> sredniaa;
Student dodaj(imiee, nazwiskoo, indexx, semestrr, sredniaa);
v.push_back(dodaj);
}

void usun_studenta()
{
	std::cout << "Ktorego studenta usunac z listy (podaj numer) : ";
	int n;
	std::cin >> n;
	if(n > v.size())
	{
	std::cout << "Nie ma takiego studenta\n";
	} else {
	v.erase(v.begin() + (n-1) );
	v.shrink_to_fit();
	}
}

int main()
{

while (true)
{
	std::cout << "LIST OF STUDENTS\n" << "1.Dodaj studenta\n" << "2.Wyswietl studentow\n" << "3.Usun studenta\n" << "4.Wyjdz\n";
	std::cout << "Co chcesz zrobic: ";
	std::cin >> dzialanie;

	switch (dzialanie)
	{
		case 1:
		{
			dodaj_studenta();
			usleep(1000000);
			system("clear");
		}
		break;
		case 2:
		{
			if (v.size() == 0)
			{
			std::cout << "Brak studentow\n";
			} else {
				for (int i = 0; i < v.size(); i++)
				{
					std::cout << i+1 << "."<< v[i].wyswietl_studenta() << "\n";
				}
			}
			usleep(3000000);
			system("clear");
		}
		break;
		case 3:
		{
			usun_studenta();
			usleep(1000000);
			system("clear");
		}
		break;
		case 4:
		{
			exit(0);
		}
		break;
		default:
		{
			std::cout << "Zly numer!\n";
			usleep(1000000);
			system("clear");
		}
		break;
	}
}
return 0;
}
