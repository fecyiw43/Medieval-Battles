#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include "Character.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Dragon.h"
#include "Sphynx.h"

using namespace std;

int *get_Damage(int turn, string name_1, int hp_1, int ma_1, int dmg_1, int def_1, float dod_1, float cri_1, float reg_1, string name_2, int hp_2, int ma_2, int dmg_2, int def_2, float dod_2, float cri_2, float reg_2);

int main()
{
    int game_end = 0;
    while (game_end == 0) // game_end == false
    {
        system("clear");
        srand (time(NULL)); // initialise a random seed (for random critical/dodge/regen chance)

        int option = 0; // 0 = main option page, 1 = game page, 2 = help page, 3 = credit page
        bool game_start = false;
        bool help = false;
        bool credit = false;
        char random; // random test variable in game_start (will be changed later)
        string c_Choice; // player choice for character

        // main option page
        if (option == 0)
        {
            cout << "Welcome to <name of the game>!" << endl;
            cout << "Please select one of the following options!" << endl;
            cout << "(1) Start game" << endl;
            cout << "(2) Help" << endl;
            cout << "(3) Credit " << endl;
            cout << "(4) Statistics" << endl; // might implement
            cin >> option;

            while (option > 5 || option < 0)
            {
                cout << "Please enter a valid whole number (1-4)" << endl;
                cin >> option;
            }
            system("clear");

        }

        // game page
        if (option == 1)
        {
            Character* player_1 = new Wizard(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
            Character* player_2 = new Sphynx(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);

            string action;
            string testing;
            int turn = 0; // turns in-game
            int name_space = 61 - (player_1->get_Name()).length(); // constant spacing

            system("clear"); // clear the page

            while ((player_1->get_Health()) > 0 && (player_2 -> get_Health()) > 0)
            {

            // put all this inside a function instead
            int h1_space = 50 - to_string(player_1->get_Health()).length(); // Spacing for health
            int m1_space = 52 - to_string(player_1->get_Mana()).length(); // Spacing for mana
            int d1_space = 49 - to_string(player_1->get_Defense()).length(); // Spacing for defense

    		// 4 digits max for stats of player 2
            int h2_space = 6 - to_string(player_2->get_Health()).length();
            int m2_space = 6 - to_string(player_2->get_Mana()).length();
            int d2_space = 6 - to_string(player_2->get_Defense()).length();

    		// Game page
            cout << "-------------------------------------------------------------------" << endl;
            cout << "|  " << player_1->get_Name() << setw(name_space) << player_2->get_Name() << "  |" << endl;
            cout << "|  health: " << player_1->get_Health() << setw(h1_space) << "health: " << player_2->get_Health() << setw(h2_space) << " |" << endl;
            cout << "|  mana: " << player_1->get_Mana() << setw(m1_space) << "mana: " << player_2->get_Mana() << setw(m2_space) <<" |" << endl;
            cout << "|  defense: " << player_1->get_Defense() << setw(d1_space) << "defense: " << player_2->get_Defense() << setw(d2_space) << " |" << endl;
            cout << "|  " << setw(64) << " |" << endl;
            cout << "|  " << setw(64) << " |" << endl;
            cout << "|  Action"<< setw(27) << "Item" << setw(31) << "Escape  |" << endl;
            cout << "-------------------------------------------------------------------" << endl;
            cout << endl;
            cout << "What would you like to do?: ";
            cin >> action;


            if (action == "Action" || action == "action" || action == "a" || action == "A")
            {
                string name_1 = player_1 -> get_Name();
                int hp_1 = player_1 -> get_Health();
                int ma_1 = player_1 -> get_Mana();
                int dmg_1 = player_1 -> get_Strength();
                int def_1 = player_1 -> get_Defense();
                float dod_1 = player_1 -> get_Dodge();
                float cri_1 = player_1 -> get_Critical();
                float reg_1 = player_1 -> get_Regen();

                string name_2 = player_2 -> get_Name();
                int hp_2 = player_2 -> get_Health();
                int ma_2 = player_2 -> get_Mana();
                int dmg_2 = player_2 -> get_Strength();
                int def_2 = player_2 -> get_Defense();
                float dod_2 = player_2 -> get_Dodge();
                float cri_2 = player_2 -> get_Critical();
                float reg_2 = player_2 -> get_Regen();

                // testing
                // cout << player_1->get_Health() << endl;
                // cout << player_2->get_Health() << endl;

                int *values = get_Damage(turn, name_1, hp_1, ma_1, dmg_1, def_1, dod_1, cri_1, reg_1, name_2, hp_2, ma_2, dmg_2, def_2, dod_2, cri_2, reg_2);

                // testing
                // cout << player_1->get_Health() << endl;
                // cout << player_2->get_Health() << endl;

                // 0 = hp_2, 1 = ma_2, 2 = hp_1, 3 = ma_1
                if (turn % 2 == 0) // player 1 hits player 2
                {
                    player_2->set_Health(values[0]);
                    player_1->set_Mana(values[1]);
                }
                else if (turn % 2 != 0) // player 2 hits player 1
                {
                    player_1->set_Health(values[2]);
                    player_2->set_Mana(values[3]);
                }
            }
            else
            {
                cout << "you wasted a turn, gg" << endl;
            }

            cout << "enter any letter to continue" << endl;
            cin >> random;
            turn++;
            system("clear");
            }
            game_end = true;
        }
        // help page
        else if (option == 2)
        {
            cout << "This game is meant to be played by 2 players" << endl;
            cout << "Get a friend first, then I'll explain the game to you xD" << endl;
            cout << "This is a turn based game, of which the goal is to kill the other player" << endl;
            cout << "During the game, you are able to either use an action, an item or a spell" << endl;
            cout << "You also have weapons, which can be upgraded using mana" << endl;
            cout << "Mana can be obtained through a successful hit on the other player" << endl;
            cout << "The initial values for each character is set, of which you'll have to pick one before starting" << endl;
            cout << "Each character has their own ability, it is important to know what their ability is" << endl;
            cout << "Weapons can be upgraded, and each upgrade would significantly increase your power!" << endl;
            cout << endl;
            cout << "Enter any number + Enter key to return to the main page" << endl;
            cin >> option;
            system("clear");
        }
        // credit page
        else if (option == 3)
        {
            cout << "This entire game was done by Frank" << endl;
            cout << endl;
            cout << "Enter any number + Enter key to return to the main page" << endl;
            cin >> option;
            system("clear");
        }

        else if (option == 4)
        {
            cout << "this is the credit page" << endl;
            cin >> option;
            system("clear");
        }
        // else if (game_end == true)
        // {
        //     cout << "play again (Y/N)?" << endl;
        //     cin >> choice;
        //     if (choice == "Y" || "y")
        //     {
        //         game_end == false;
        //     }
        //     else if (choice == "N" || "n")
        //     {
        //         cout << "cya!" << endl;
        //     }
        // }
    }
    return 0;
}


int *get_Damage(int turn, string name_1, int hp_1, int ma_1, int dmg_1, int def_1, float dod_1, float cri_1, float reg_1, string name_2, int hp_2, int ma_2, int dmg_2, int def_2, float dod_2, float cri_2, float reg_2)
{
    int *ptr = new int [4];
    ptr[0] = 0;
    ptr[1] = 0;
    ptr[2] = 0;
    ptr[3] = 0;


    int d_chance_1 = rand() % 100 + 1;
    int c_chance_1 = rand() % 100 + 1;

    int d_chance_2 = rand() % 100 + 1;
    int c_chance_2 = rand() % 100 + 1;

    // testing
    // cout << d_chance_1 << " " << c_chance_1 << endl;
    // cout << d_chance_2 << " " << c_chance_2 << endl;

    // cout << dod_1*100 << " " << cri_1*100 << endl;
    // cout << dod_2*100 << " " << cri_2*100 << endl;

    if (turn % 2 == 0) // player 1 hitting player 2's turn
    {
        // player 2 dodge chance
        if (d_chance_2 <= dod_2*100)
        {
            ma_1 = ma_1 + 20; // mana + 20 for dodge
            cout << "the hit was dodged" << endl;
        }

        // if player 1's damage is greater than player 2's defense
        if (dmg_1 > def_2)
        {
            // player 1's critical chance
            if (c_chance_1 <= cri_1*100)
            {
                // critical damage (5 times damage)
                hp_2 = hp_2 - 5*(dmg_1 - def_2);
                ma_1 = ma_1 + 30; // mana + 30 for critical
                cout << "critical hit! that dealt " << 5*(dmg_1 - def_2) << " damage to " << name_2 << endl;
            }
            else
            {
                // normal damage
                hp_2 = hp_2 - (dmg_1 - def_2);
                ma_1 = ma_1 + 10; // mana + 10 for normal
                cout << "the hit dealt " << (dmg_1 - def_2) << " damage to " << name_2 << endl;
            }
        }
        ptr[0] = hp_2;
        ptr[1] = ma_1;
        return ptr;
    }
    else if (turn % 2 != 0) // player 2 hitting player 1's turn
    {
        // player 1 dodge chance
        if (d_chance_1 <= dod_1*100)
        {
            ma_2 = ma_2 + 20; // mana + 20 for dodge
            cout << "the hit was dodged" << endl;
        }

        // if player 2's damage is greater than player 1's defense
        if (dmg_2 > def_1)
        {
            // player 2's critical chance
            if (c_chance_2 <= cri_2*100)
            {
                // critical damage (5 times damage)
                hp_1 = hp_1 - 5*(dmg_2 - def_1);
                ma_2 = ma_2 + 30; // mana + 30 for critical
                cout << "critical hit! that dealt " << 5*(dmg_2 - def_1) << " damage to " << name_1 << endl;
            }
            else
            {
                // normal damage
                hp_1 = hp_1 - (dmg_2 - def_1);
                ma_2 = ma_2 + 10; // mana + 10 for normal
                cout << "the hit dealt " << (dmg_2 - def_1) << " damage to " << name_1 << endl;
            }
        }
        ptr[2] = hp_1;
        ptr[3] = ma_2;
        cout << "1normal " << ptr[3] << endl;
        return ptr;
    }
    return 0;
}