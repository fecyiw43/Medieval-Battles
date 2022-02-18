#include <iostream>
#include <string>
#include "Character.h"
#include "item.h"
#include "Consumables.h"

// use of health potion
int Health_potion::use(Character Heroes, bool TEST_MODE)
{
    srand(time(NULL)); // randomise the random number generator seed
    int hp = Heroes.get_Health();
    int max = Heroes.get_Max();
    int random = 0;

    if (TEST_MODE == false)
    {
        random = rand() % 100 + 300;
        hp += random;
    }

    else if (TEST_MODE == true)
    {
        random = 300;
        hp += random;
    }

    if (hp > max)
    {
        cout << "player healed to: max hp" << endl;
        hp = max;
        return hp;
    }
    cout << "player healed by: " << random << " hp" << endl;
    return hp;
}

// use of damage potion
int Damage_potion::use(Character Heroes, bool TEST_MODE)
{
    srand(time(NULL));// randomise the random number generator seed
    int hp = Heroes.get_Health();
    int random = 0;

    if (TEST_MODE == false)
    {
        random = rand() % 100 + 150;
        hp -= random;
    }
    else if (TEST_MODE == true)
    {
        random = 150;
        hp -= random;
    }

    cout << "player damaged by: " << random << " hp" << endl;
    return hp;
}