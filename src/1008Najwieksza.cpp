# include <iostream>
# include <string>
auto ask_user_for_integer ( std :: string const prompt ) -> int
{
if ( not prompt . empty ()) {
std :: cout << prompt ;
}
auto value = std :: string {};
std :: getline ( std :: cin , value );
return std :: stoi ( value );
}

int main()
{
int x;
x = ask_user_for_integer ("Podaj liczbe: ");
int y;
y = ask_user_for_integer ("Podaj liczbe: ");
int z;
z = ask_user_for_integer ("Podaj liczbe: ");
if ( x > y && x > z )
{
std::cout << x << "\n";
}
if ( y > x && y > z )
{
std::cout << y << "\n";
}
if ( z > x && z > y )
{
std::cout << z << "\n";
}

}
