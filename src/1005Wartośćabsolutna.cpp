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
x = ask_user_for_integer("Podaj liczbe: ");
std::cout << abs(x);
return 0;
}
