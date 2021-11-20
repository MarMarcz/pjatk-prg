#include <iostream>
#include <string>
#ifndef ListOfStudents_h
#define ListOfStudents_h

struct Student
{
std::string imie, nazwisko, index;
int semestr;
float srednia;

Student(std::string, std::string, std::string, int, float);

auto wyswietl_studenta();
};
#endif


auto Student::wyswietl_studenta()
{
return imie + " " + nazwisko + " " + index + " " +
std::to_string(semestr) + " " + std::to_string(srednia);
}


