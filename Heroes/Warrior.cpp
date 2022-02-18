#include <iostream>
#include <string>
#include "Character.h"
#include "Warrior.h"

using namespace std;

// Warrior child class
Warrior::Warrior(string aName, int aMax, int aHealth, int aMana, int aDefense, int aStrength, float aDodge, float aCritical, float aRegen):Character(aName, aMax, aHealth, aMana, aDefense, aStrength, aDodge, aCritical, aRegen)
{
    name = aName;
    max = aMax;
    health = aHealth;
    mana = aMana;
    defense = aDefense;
    strength = aStrength;
    dodge = aDodge;
    critical = aCritical;
    regen = aRegen;
}
// Warrior ability

