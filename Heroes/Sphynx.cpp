#include <iostream>
#include <string>
#include "Character.h"
#include "Sphynx.h"

using namespace std;

// Sphynx Child class
Sphynx::Sphynx(string sName, int sMax, int sHealth, int sMana, int sDefense, int sStrength, float sDodge, float sCritical, float sRegen):Character(sName, sMax, sHealth, sMana, sDefense, sStrength, sDodge, sCritical, sRegen)
{
    name = sName;
    max = sMax;
    health = sHealth;
    mana = sMana;
    defense = sDefense;
    strength = sStrength;
    dodge = sDodge;
    critical = sCritical;
    regen = sRegen;
}

// Ability