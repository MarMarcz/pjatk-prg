#include <iostream>
#include "../include/s24566/Item.h"

int main()
{
Creature monster("Monster", 10);
Sword s;
Axe a;
Bow b;
Health_potion h;

show_monster_hp(monster);

std::cout << "Using sword! BUM\n";
s.use_on(monster, s.strength());
show_monster_hp(monster);

std::cout << "Using axe! BUM\n";
a.use_on(monster,a.strength());
show_monster_hp(monster);

std::cout << "Using health potion!\n";
h.use_on(monster, h.strength());
show_monster_hp(monster);

std::cout << "Using bow! BUM\n";
b.use_on(monster, b.strength());
show_monster_hp(monster);

std::cout << "Using health potion! Again but now it isn't working\n";
h.use_on(monster, h.strength());
show_monster_hp(monster);

return 0;
}
