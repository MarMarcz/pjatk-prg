#include <string>
#ifndef Person_h
#define Person_h

struct Person
{
	std::string name;
	std::string surname;

	virtual std::string to_string() const = 0;

	Person(std::string n, std::string s)
	{
	name=n;
	surname=s;
	}

};

struct Mr : Person
{
	std::string to_string() const override
	{
		return ("Mr " + name);
	}

	Mr(std::string n, std::string s):Person(n, s)
	{}
};

struct Mrs : Person
{
	std::string to_string() const override
	{
        	return ("Mrs " + name);
	}

	Mrs(std::string n, std::string s):Person(n, s)
	{}
};

struct Queen : Person
{
	std::string to_string() const override
	{
        	return ("Queen " + name);
	}

	Queen(std::string n, std::string s):Person(n, s)
	{}
};

struct King : Person
{
	std::string to_string() const override
	{
	        return ("King " + name);
	}

	King(std::string n, std::string s):Person(n, s)
	{}
};

std::string who_is_it( Person const& who )
{
        return who.to_string();
}

struct Greeting
{
        virtual std::string greet(Person const& x) const = 0;
};

struct Hello : Greeting
{
        std::string greet(Person const& x) const override
        {
                return ("Hello " + who_is_it(x) );
        }

	Hello() {};
};

struct Good_evening : Greeting
{
	std::string greet(Person const& x) const override
	{
		return ("Good evening " + who_is_it(x) );
	}

	Good_evening() {};
};

struct Farewell : Greeting
{
	std::string greet(Person const& x) const override
	{
		return ("Farewell " + who_is_it(x) );
	}

	Farewell() {};
};
#endif
