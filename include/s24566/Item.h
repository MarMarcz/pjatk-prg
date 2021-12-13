#include <string>
#ifndef Item_h
#define Item_h

//IN PROGRESS

struct Creature
{
	std::string name;
	int hp; //health_points

	Creature (std::string n, int h)
	{
	name=n;
	hp=h;
	}
};

struct Item //bazowa
{
	virtual void use_on( Creature& ) = 0;
	virtual int strength() const;
};

struct Weapon : Item
{
	void use_on( Creature& x ) override
	{
	x.hp--;
	}

};

struct Potion : Item
{
	void use_on( Creature& x ) override
	{
	x.hp++;
	}

};

struct Sword : Item
{
	int strength() const override
	{
		return 5;
	}
};

struct Axe : Item
{
	int strength() const override
        {
                return 3;
        }
};

struct Bow : Item
{
	int strength() const override
        {
                return 2;
        }
};

struct Health_potion : Item
{
	int strength() const override
        {
                return 4;
        }
};

#endif
