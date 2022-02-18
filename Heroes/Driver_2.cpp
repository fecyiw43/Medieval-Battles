#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include <cstdlib>
#include <stdlib.h>

#include "item.h"
#include "Consumables.h"

#include "Character.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Dragon.h"
#include "Sphynx.h"

int main()
{
    // testing consumable class
    Character Heroes[2];
    Character* hero = new Wizard("Name", 1000, 500, 0, 100, 200, 0.1, 0.1, 0.1); // initialise pre-determined wizard class
    Heroes[0] = *hero;

    // set up the consumable classes
    Health_potion h_potion = Health_potion();
    Damage_potion d_potion = Damage_potion();
    // make sure test_mode is true
    bool TEST_MODE = true;

    string choice;
    cin >> choice;

    int hp = Heroes[0].get_Health();
    cout << Heroes[0].get_Health() << endl;

    if (choice == "Health")
    {
        hp = h_potion.use(Heroes[0], TEST_MODE);
        Heroes[0].set_Health(hp);
    }

    if (choice == "Damage")
    {
        hp = d_potion.use(Heroes[0], TEST_MODE);
        Heroes[0].set_Health(hp);
    }

    cout << Heroes[0].get_Health() << endl;

    return 0;
}