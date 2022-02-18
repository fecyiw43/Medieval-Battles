#include <iostream>
#include <string>
#include "Character.h"

// constructing default character object
Character::Character()
{
    // in all classes
    name = "Unknown";
    max = 0;
    health = 0;
    mana = 0;
    defense = 0;
    strength = 0;
    dodge = 0;

    critical = 0; // not in creature class
    regen = 0; // not in human class
}

// constructing variable dependent object
Character::Character(string cname, int cMax, int cHealth, int cMana, int cDefense, int cStrength, float cDodge, float cCritical, float cRegen)
{
    name = cname;
    max = cMax;
    health = cHealth;
    mana = cMana;
    defense = cDefense;
    strength = cStrength;
    dodge = cDodge;
    critical = cCritical;
    regen = cRegen;
}

// this would show all the information of the current character
void Character::get_all()
{
    cout << "Name of the character is: "<< name << endl;
    cout << "Max health is: " << max << endl;
    cout << "Current health is: " << health << endl;
    cout << "Current mana is: " << mana << endl;
    cout << "Current defense is: " << defense << endl;
    cout << "Current strength is: " << strength << endl;
    cout << "Current dodge chance is: " << dodge*100 << "%" << endl;
    cout << "Current critical chance is: " << critical*100 << "%" << endl;
    cout << "Current regen rate is: " << regen*100 << "%" << endl;
}

// to return character's name
string Character::get_Name()
{
    return name;
}

int Character::get_Max()
{
    return max;
}

// to return character's health
int Character::get_Health()
{
    return health;
}

// to return character's mana
int Character::get_Mana()
{
    return mana;
}

// to return character's defense
int Character::get_Defense()
{
    return defense;
}

// to return character's strength
int Character::get_Strength()
{
    return strength;
}

// to return character's dodge chance
float Character::get_Dodge()
{
    return dodge;
}

// to return character's critical chance
float Character::get_Critical()
{
    return critical;
}

// to return character's regen chance
float Character::get_Regen()
{
    return regen;
}

// set character's name
void Character::set_Name(string nam)
{
    name = nam;
}

// set character's max health
void Character::set_Max(int maxx)
{
    max = maxx;
}

// set character's health
void Character::set_Health(int hp)
{
    health = hp;
}

// set character's mana
void Character::set_Mana(int ma)
{
    mana = ma;
}

// set character's defense
void Character::set_Defense(int def)
{
    defense = def;
}

// set character's strength
void Character::set_Strength(int str)
{
    strength = str;
}

// set character's dodge chance
void Character::set_Dodge(float dod)
{
    dodge = dod;
}

// set character's critical chance
void Character::set_Critical(float cri)
{
    critical = cri;
}

// set character's regen chance
void Character::set_Regen(float reg)
{
    regen = reg;
}
