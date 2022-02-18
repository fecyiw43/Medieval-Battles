#include <iostream>
#include <string>
#include <time.h>
#include "Character.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Dragon.h"
#include "Sphynx.h"

using namespace std;

int get_Damage(int turn, int hp_1, int ma_1, int dmg_1, int def_1, float dod_1, float cri_1, float reg_1, int hp_2, int ma_2, int dmg_2, int def_2, float dod_2, float cri_2, float reg_2);


int main()
{
    Character player[2];

    int game_end = 0;
    while (game_end == 0)
    {
        system("clear");
        srand (time(NULL)); // initialise a random seed

        int option = 0; // 0 = nothing, 1 = game start, 2 = help, 3 = credit, 4 = stats, 5 = endgame screen
        char random; // random test variable in game_start
        string c_Choice;
        string name_P1;
        int c_Choice_1; // player 1 character choice
        string name_P2;
        int c_Choice_2; // player 2 character choice

        if (option == 0)
        {
            cout << "Welcome to <name of the game>!" << endl;
            cout << "Please select one of the following options!" << endl;
            cout << "(1) Start game" << endl;
            cout << "(2) Help" << endl;
            cout << "(3) Credit " << endl;
            // cout << "(4) Statistics" << endl; // might implement
            cin >> option;
            system("clear");
        }

        // Polymorphism for individual characters
        // name, health, mana, defense, strength, dodge, critical, regen


        if (option == 1) // gamestart
        {
            cout << "What is your name player 1?" << endl;
            cin >> name_P1;
            cout << "What is your name player 2?" << endl;
            cin >> name_P2;
            system("clear");


            int pick = 1;

            if (pick == 1)
            {
                cout << "Please select a Character!" << endl;
                cout << "Player 1, which one would you pick?" << endl;
                cout << "Warrior(1) / Wizard(2) / Dragon(3) / Sphynx(4)" << endl;
                cin >> c_Choice_1;
                system("clear");


                if (c_Choice_1 == 1)
                {
                    Character* player_1 = new Warrior(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[1] = *player_1;
                    cout << "woo" << endl;
                    cout << player[1].get_Health() << endl;
                    cout << player[1].get_Mana() << endl;
                    cout << player[1].get_Defense() << endl;
                    cout << player[1].get_Strength() << endl;
                    cout << player[1].get_Critical() << endl;
                    cout << player[1].get_Dodge() << endl;
                    cout << player[1].get_Regen() << endl;
                }
                else if (c_Choice_1 == 2)
                {
                    Character* player_1 = new Wizard(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[1] = *player_1;
                }
                else if (c_Choice_1 == 3)
                {
                    Character* player_1 = new Dragon(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[1] = *player_1;
                }
                else if (c_Choice_1 == 4)
                {
                    Character* player_1 = new Sphynx(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[1] = *player_1;
                }

                cout << "Please select a Character!" << endl;
                cout << "Player 2, which one would you pick?" << endl;
                cout << "Warrior(1) / Wizard(2) / Dragon(3) / Sphynx(4)" << endl;
                cin >> c_Choice_2;
                system("clear");

                if (c_Choice_2 == 1)
                {
                    Character* player_2 = new Warrior(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[2] = *player_2;
                }
                else if (c_Choice_2 == 2)
                {
                    Character* player_2 = new Wizard(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[2] = *player_2;
                }
                else if (c_Choice_2 == 3)
                {
                    Character* player_2 = new Dragon(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[2] = *player_2;
                }
                else if (c_Choice_2 == 4)
                {
                    Character* player_2 = new Sphynx(name_P1, 1000, 0, 50, 110, 0.20, 0.70, 0.0);
                    player[2] = *player_2;
                }
                pick = 0;
            }


            int turn = 0;

            // war->get_all();
            // cout << war -> get_Health() << endl;
            // cout << endl;
            while ((player[1].get_Health()) > 0 && (player[2].get_Health()) > 0)
            {

            int hp_1 = player[1].get_Health();
            int ma_1 = player[1].get_Mana();
            int dmg_1 = player[1].get_Strength();
            int def_1 = player[1].get_Defense();
            float dod_1 = player[1].get_Dodge();
            float cri_1 = player[1].get_Critical();
            float reg_1 = player[1].get_Regen();

            int hp_2 = player[2].get_Health();
            int ma_2 = player[2].get_Mana();
            int dmg_2 = player[2].get_Strength();
            int def_2 = player[2].get_Defense();
            float dod_2 = player[2].get_Dodge();
            float cri_2 = player[2].get_Critical();
            float reg_2 = player[2].get_Regen();

            int health = get_Damage(turn, hp_1, ma_1, dmg_1, def_1, dod_1, cri_1, reg_1, hp_2, ma_2, dmg_2, def_2, dod_2, cri_2, reg_2);
            turn++;
            if (turn % 2 == 0)
            {
                player[1].set_Health(health);
            }
            else if (turn % 2 != 0)
            {
                player[2].set_Health(health);
            }
            cout << "Warrior health: " << player[1].get_Health() << endl;
            cout << "Wizard health: " << player[2].get_Health() << endl;
            cout << "that's all, press letter + enter to start the next turn" << endl;
            cin >> random;
            system("clear");
            }

            game_end = 1;

            // turn = 3;

            // cout << hp_1 << endl;
            // cout << get_Damage(turn, hp_1, ma_1, dmg_1, def_1, dod_1, cri_1, reg_1, hp_2, ma_2, dmg_2, def_2, dod_2, cri_2, reg_2);
            // cout << endl;
        }
        else if (option == 2) // help
        {
            cout << "This game is meant to be played by 2 players" << endl;
            cout << "get a friend first, then I'll explain the game to you xD" << endl;
            cout << "This is a turn based game, of which the goal is to kill the other player" << endl;
            cout << "During the game, you are able to either use an action, an item or a spell" << endl;
            cout << "you also have weapons, which can be upgraded using mana" << endl;
            cout << "mana can be obtained through a successful hit on the other player" << endl;
            cout << "the initial values for each character is set, of which you'll have to pick one before starting" << endl;
            cout << "each character has their own ability, it is important to know what their ability is" << endl;
            cout << "weapons can be upgraded, and each upgrade would significantly increase your power!" << endl;
            cout << "press any number + Enter to return to the main page" << endl;
            cin >> option;
            system("clear");
        }

        else if (option == 3) // credit
        {
            cout << "it's all done by Frank, the other 2 group member didn't help at all lol" << endl;
            cout << "press any number + Enter to return to the main page" << endl;
            cin >> option;
            system("clear");
        }
        else if (option == 4) // stats
        {
            // empty
        }

        else if (option == 5) // game end
        {
            // empty
        }

    }
    return 0;
}


int get_Damage(int turn, int hp_1, int ma_1, int dmg_1, int def_1, float dod_1, float cri_1, float reg_1, int hp_2, int ma_2, int dmg_2, int def_2, float dod_2, float cri_2, float reg_2)
{
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
            cout << "the hit was dodged" << endl;
            return hp_2;
        }

        // if player 1's damage is greater than player 2's defense
        if (dmg_1 > def_2)
        {
            // player 1's critical chance
            if (c_chance_1 <= cri_1*100)
            {
                // critical damage (3 times damage)
                hp_2 = hp_2 - 3*(dmg_1 - def_2);
                cout << "critical hit! that dealt " << 3*(dmg_1 - def_2) << " damage" << endl;
                return hp_2;
            }
            else
            {
                // normal damage
                hp_2 = hp_2 - (dmg_1 - def_2);
                cout << "the hit dealt " << (dmg_1 - def_2) << " damage" << endl;
                return hp_2;
            }
        }
    }
    else // player 2 hitting player 1's turn
    {
        // player 1 dodge chance
        if (d_chance_1 <= dod_1*100)
        {
            cout << "the hit was dodged" << endl;
            return hp_1;
        }

        // if player 2's damage is greater than player 1's defense
        if (dmg_2 > def_1)
        {
            // player 2's critical chance
            if (c_chance_2 <= cri_2*100)
            {
                // critical damage (3 times damage)
                hp_1 = hp_1 - 3*(dmg_2 - def_1);
                cout << "critical hit! that dealt " << 3*(dmg_2 - def_1) << " damage" << endl;
                return hp_1;
            }
            else
            {
                // normal damage
                hp_1 = hp_1 - (dmg_2 - def_1);
                cout << "the hit dealt " << (dmg_2 - def_1) << " damage" << endl;
                return hp_1;
            }
        }
    }
    return 0;
}