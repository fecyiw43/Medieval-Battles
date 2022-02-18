#include <iostream>
#include <string>
#include "Character.h"
#include "Dragon.h"

using namespace std;

// Dragon child class
Dragon::Dragon(string dName, int dMax, int dHealth, int dMana, int dDefense, int dStrength, float dDodge, float dCritical, float dRegen):Character(dName, dMax, dHealth, dMana, dDefense, dStrength, dDodge, dCritical, dRegen)
{
    name = dName;
    max = dMax;
    health = dHealth;
    mana = dMana;
    defense = dDefense;
    strength = dStrength;
    dodge = dDodge;
    critical = dCritical;
    regen = dRegen;
}

// int Dragon::skill(Character Hero)
// {
//     int def = Hero.get_Defense();
//     def = def*2;
//     return def;
// }