#include <string>
#ifndef Item_h
#define Item_h

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
	virtual void use_on( Creature&, int ) = 0;
	virtual int strength() const = 0;
};

struct Weapon : Item
{
	void use_on( Creature& c, int x ) override
	{
		c.hp -= x;
	}

};

struct Potion : Item
{
	void use_on( Creature& c, int x ) override
	{
		c.hp += x;
	}

};

struct Sword : Weapon
{
	int strength() const override
	{
		return 5;
	}
};

struct Axe : Weapon
{
	int strength() const override
        {
                return 3;
	}
};

struct Bow : Weapon
{
	int strength() const override
        {
                return 2;
        }
};

int used = 0; //how many times it was used (Health_potion)

struct Health_potion : Potion
{
	int strength() const override
        {
		used += 1;
		if( used >= 2)
			return 0;
		else
                	return 4;
        }
};
#endif

void show_monster_hp( Creature& c )
{
	std::cout << "Monster has: " << c.hp << "hp\n";
}
