#include <iostream>
#include <string>
#include "Character.h"
#include "Wizard.h"

using namespace std;

// Wizard child class
Wizard::Wizard(string wName, int wMax, int wHealth, int wMana, int wDefense, int wStrength, float wDodge, float wCritical, float wRegen):Character(wName, wMax, wHealth, wMana, wDefense, wStrength, wDodge, wCritical, wRegen)
{
    name = wName;
    max = wMax;
    health = wHealth;
    mana = wMana;
    defense = wDefense;
    strength = wStrength;
    dodge = wDodge;
    critical = wCritical;
    regen = wRegen;
}

// int Wizard::energy_shield(aTurn, Strength) {
//     int abilityTurn = aTurn;
//     this->Strength = Strength;

// }
