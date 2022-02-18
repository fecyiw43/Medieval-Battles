#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include <cstdlib>
#include <stdlib.h>

#include "Character.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Dragon.h"
#include "Sphynx.h"

int main()
{
    // testing constructors + getters

    string name;
    string type;
    int max;
    int health;
    int mana;
    int defense;
    int strength;
    float dodge;
    float critical;
    float regen;

    cin >> name;
    cin >> type;
    cin >> max;
    cin >> health;
    cin >> mana;
    cin >> defense;
    cin >> strength;
    cin >> dodge;
    cin >> critical;
    cin >> regen;

    if (type == "Dragon")
    {
        Character* player = new Dragon(name, max, health, mana, defense, strength, dodge, critical, regen); // remember to input all data
        player -> get_all();
        player -> set_Name("Hello");
        player -> set_Max(1234);
        player -> set_Health(1234);
        player -> set_Mana(78);
        player -> set_Defense(999);
        player -> set_Strength(999);
        player -> set_Dodge(0.88);
        player -> set_Critical(0.78);
        player -> set_Regen(0.23);
        player -> get_all();
    }
    else if (type == "Wizard")
    {
        Character* player = new Wizard(name, max, health, mana, defense, strength, dodge, critical, regen); // remember to input all data
        player -> get_all();
        player -> set_Name("Hello");
        player -> set_Max(1234);
        player -> set_Health(1234);
        player -> set_Mana(78);
        player -> set_Defense(999);
        player -> set_Strength(999);
        player -> set_Dodge(0.88);
        player -> set_Critical(0.78);
        player -> set_Regen(0.23);
        player -> get_all();
    }
    else if (type == "Sphynx")
    {
        Character* player = new Sphynx(name, max, health, mana, defense, strength, dodge, critical, regen); // remember to input all data
        player -> get_all();
        player -> set_Name("Hello");
        player -> set_Max(1234);
        player -> set_Health(1234);
        player -> set_Mana(78);
        player -> set_Defense(999);
        player -> set_Strength(999);
        player -> set_Dodge(0.88);
        player -> set_Critical(0.78);
        player -> set_Regen(0.23);
        player -> get_all();
    }
    else if (type == "Warrior")
    {
        Character* player = new Warrior(name, max, health, mana, defense, strength, dodge, critical, regen); // remember to input all data
        player -> get_all();
        player -> set_Name("Hello");
        player -> set_Max(1234);
        player -> set_Health(1234);
        player -> set_Mana(78);
        player -> set_Defense(999);
        player -> set_Strength(999);
        player -> set_Dodge(0.88);
        player -> set_Critical(0.78);
        player -> set_Regen(0.23);
        player -> get_all();
    }



    return 0;
}