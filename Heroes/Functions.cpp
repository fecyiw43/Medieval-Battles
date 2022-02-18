#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include "item.h"
#include "Consumables.h"

#include "Character.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Dragon.h"
#include "Sphynx.h"

int *hitting_Turn(Character Hitter, Character Receiver);
int *item_Turn(string item_choice, Character Hitter, Character Receiver, bool TEST_MODE);

int *get_Damage(int turn, Character Heroes_1, Character Heroes_2)
{
    int* ptr = new int[3];
    ptr[0] = 0; // health player 1
    ptr[1] = 0; // mana
    ptr[2] = 0; // health player 2 (mana only)

    if (turn % 2 == 0) // p1 turn hitting p2
    {
        ptr = hitting_Turn(Heroes_1, Heroes_2);
    }
    else if (turn % 2 != 0) // p2 turn hitting p1
    {
        ptr = hitting_Turn(Heroes_2, Heroes_1);
    }

    return ptr;
}

int *hitting_Turn(Character Hitter, Character Receiver)
{
    int *ptr = new int [3];
    ptr[0] = 0; // health player 1
    ptr[1] = 0; // mana player 1
    ptr[2] = 0; // health player 2 (mana only)

    string name_1 = Receiver.get_Name(); // name
    int hp_1 = Receiver.get_Health(); // health
    int def_1 = Receiver.get_Defense(); // defense
    float dod_1 = Receiver.get_Dodge(); // dodge
    float reg_1 = Receiver.get_Regen(); // regen

    string name_2 = Hitter.get_Name(); // name
    int hp_2 = Hitter.get_Health(); // health (for mana use only)
    int max_2 = Hitter.get_Max(); // max health (for mana use only)
    int ma_2 = Hitter.get_Mana(); // mana
    int dmg_2 = Hitter.get_Strength(); // strength
    float cri_2 = Hitter.get_Critical(); // critical

    // random dodge, regen and critical chance generator
    int d_chance_1 = rand() % 100 + 1;
    int r_chance_1 = rand() % 100 + 1;
    int c_chance_2 = rand() % 100 + 1;

    // if mana exceeds 100
    if (ma_2 >= 100)
    {
        // mana - 100, health + 100
        ma_2 -= 100;
        hp_2 += 100;
        if (hp_2 >= max_2)
        {
            ma_2 = max_2;
        }
        cout << "Your 100 mana has exchanged to 100 health" << endl;
        ptr[2] = hp_2;
    }

    else if (ma_2 < 100)
    {
        ptr[2] = hp_2;
        ptr[1] = ma_2;
    }

    // receiver dodge chance
    if (d_chance_1 <= dod_1*100)
    {
        ma_2 = ma_2 + 20; // mana + 20 for dodged hits
        cout << "the hit was dodged" << endl;

        ptr[0] = hp_1;
        ptr[1] = ma_2;
        return ptr;
    }

    // receiver regen chance
    if (r_chance_1 <= reg_1*100)
    {
        hp_1 = hp_1 + (hp_1 * 0.05);
        cout << name_1 << " regenerated 0.05 of their current health" << endl;
    }

    // if hitters' damage is greater than receivers' defense
    if (dmg_2 > def_1)
    {
        // hitters' critical chance
        if (c_chance_2 <= cri_2*100)
        {
            // hitters' critical damage (4 times damage)
            hp_1 = hp_1 - 4*(dmg_2 - def_1);
            ma_2 = ma_2 + 30; // mana + 30 for critical hits

            cout << "critical hit! that dealt " << 4*(dmg_2 - def_1) << " damage to " << name_1 << endl;

            ptr[0] = hp_1;
            ptr[1] = ma_2;
            return ptr;
        }
        else
        {
            // hitters' normal damage
            hp_1 = hp_1 - (dmg_2 - def_1);
            ma_2 = ma_2 + 10; // mana + 10 for normal hits

            cout << "the hit dealt " << (dmg_2 - def_1) << " damage to " << name_1 << endl;

            ptr[0] = hp_1;
            ptr[1] = ma_2;
            return ptr;
        }
    }
    return nullptr;
}

int *get_Item(string item_choice, int turn, Character Heroes_1, Character Heroes_2, bool TEST_MODE)
{
    int *ptr = new int [2];
    ptr[0] = 0;
    ptr[1] = 0;

    if (turn % 2 == 0) // Hero 1 healing Hero 1 || Hero 1 poisoning Hero 2
    {
        ptr = item_Turn(item_choice, Heroes_2, Heroes_1, TEST_MODE);
        return ptr;
    }
    else if (turn % 2 != 0) // Hero 2 healing Hero 2 || Hero 2 poisoning Hero 1
    {
        ptr = item_Turn(item_choice, Heroes_1, Heroes_2, TEST_MODE);
        return ptr;
    }
    return nullptr;
}

int *item_Turn(string item_choice, Character Hitter, Character Receiver, bool TEST_MODE)
{
    int *ptr = new int [2];
    ptr[0] = 0;
    ptr[1] = 0;

    // initialising health and damage potions
    Health_potion h_potion = Health_potion();
    Damage_potion d_potion = Damage_potion();

    int hp_1 = Receiver.get_Health();
    int hp_2 = Hitter.get_Health();

    // if item choice is health potion
    if (item_choice == "H" || item_choice == "h" || item_choice == "Health" || item_choice == "health")
    {
        ptr[0] = h_potion.use(Hitter, TEST_MODE);
        ptr[1] = hp_1;
        return ptr;
    }
    // if item choice is damage potion
    else if (item_choice == "D" || item_choice == "d" || item_choice == "Damage" || item_choice == "damage")
    {
        ptr[0] = hp_2;
        ptr[1] = d_potion.use(Receiver, TEST_MODE);
        return ptr;
    }
    // if none of the choices was taken
    else
    {
        // return back their normal health
        ptr[0] = hp_2;
        ptr[1] = hp_1;
        return ptr;
    }
    return nullptr;
}