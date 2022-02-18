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

using namespace std;

extern int *get_Damage(int turn, Character Heroes_1, Character Heroes_2);
extern int *get_Item(string item_choice, int turn, Character Heroes_1, Character Heroes_2, bool TEST_MODE);

int main()
{
    // asks the user about test mode at start of the game
    cout << "Enter 0 to start the game" << endl;
    bool TEST_MODE;
    cin >> TEST_MODE;
    string random = ".";
    int game_end = 0; // if game_end is false
    string option = "0"; // 0 = main option page, 1 = game page, 3 = help page, 4 = credit page

    while (game_end == 0) // if game_end if false
    {
        // if test mode is off
        if (TEST_MODE == false)
        {
            system("clear"); // clear page
        }

        srand (time(NULL)); // initialise a random seed (for random critical/dodge/regen chance)

        // main option page
        if (option == "0")
        {
            cout << "Welcome to heroes rpg!" << endl;
            cout << "Please select one of the following options!" << endl;
            cout << "(1) Start game" << endl;
            cout << "(2) Help" << endl;
            cout << "(3) Credit" << endl;
            cout << "(4) End game" << endl;
            cin >> option;

            if (option == "1" || option == "2" || option == "3" || option == "4")
            {
                goto out;
            }

            while (option != "1" || option != "2" || option != "3" || option != "4")
            {
                system("clear");
                cout << "Please enter a valid whole number (1-4)" << endl;
                cin >> option;
                if (option == "1" || option == "2" || option == "3" || option == "4")
                {
                    goto out;
                }
            }

            // get out from the while loop
            out:

            // if test mode is off
            if (TEST_MODE == false)
            {
                system("clear"); // clear page
            }
        }

        // game page
        if (option == "1")
        {
            // initialising variables
            Character Heroes[3];
            string name[3];
            string choices[3];

            cout << "Welcome to the game!" << endl;

            // asking for player names
            for (int i = 1; i < 3; i++)
            {
                cout << "Please enter your name player " << i << endl;
                cin >> name[i];
            }

            // if test mode is off
            if (TEST_MODE == false)
            {
                system("clear"); // clear page
            }

            // asking player for character choices
            for (int i = 1; i < 3; i++)
            {
                cout << name[i] << ", Please select a character!" << endl;
                cout << "Hint: Human class have critical power, and creature class have regen power" << endl;
                cout << "Hint: Human class have lower dodge chance than creature class!" << endl;
                cout << "| Wizard(1) | Warrior(2) | Sphynx(3) | Dragon(4) |" << endl;
                cin >> choices[i];

                // prevent user entering values/letters/special characters that isn't a possible choice
                if (choices[i] == "1" || choices[i] == "2" || choices[i] == "3" || choices[i] == "4")
                {
                    goto end;
                }

                // if user didn't enter in 1,2,3 or 4
                while (choices[i] != "1" || choices[i] != "2" || choices[i] != "3" || choices[i] != "4")
                {
                    // repeat the loop until user enters 1,2,3,or 4
                    cout << "Failed, Please enter a valid number between 1-4" << endl;
                    cin >> choices[i];
                    if (choices[i] == "1" || choices[i] == "2" || choices[i] == "3" || choices[i] == "4")
                    {
                        goto end;
                    }
                }
                end:

                // if test mode is off
                if (TEST_MODE == false)
                {
                    system("clear"); // clear page
                }
            }

            // initialise the character picked by the player
            for (int i = 1; i < 3; i++)
            {
                if (choices[i] == "1") // Wizard
                {
                    // the order of the values: "name, manx, health, mana, defense, attack, dodge, crit, regen"
                    Character* player = new Wizard(name[i], 700, 700, 0, 40, 105, 0.10, 0.25, 0.0);
                    Heroes[i] = *player; // used to separate player 1 and 2
                }
                else if (choices[i] == "2") // Warrior
                {
                    Character* player = new Warrior(name[i], 800, 800, 0, 45, 85, 0.05, 0.40, 0.0);
                    Heroes[i] = *player;
                }
                else if (choices[i] == "3") // Sphynx
                {
                    Character* player = new Sphynx(name[i], 650, 650, 0, 55, 115, 0.33, 0.0, 0.70);
                    Heroes[i] = *player;
                }
                else if (choices[i] == "4") // Dragon
                {
                    Character* player = new Dragon(name[i], 900, 900, 0, 50, 105, 0.35, 0.0, 0.50);
                    Heroes[i] = *player;
                }
            }

            // initialising in-game variables
            string action; // asks the player what action they would like to act
            string item_choice; // asks the player which item they would like to use
            string again; // asks if the players want to play again

            int turn = 0; // turns in-game
            int item_number_1 = 3; // items in game for player 1
            int item_number_2 = 3; // items in game for player 2
            int name_space = 61 - (Heroes[1].get_Name()).length(); // constant spacing for name

            while ((Heroes[1].get_Health()) > 0 && (Heroes[2].get_Health()) > 0)
            {
                if (TEST_MODE == true)
                {
                    Heroes[1].set_Dodge(0);
                    Heroes[1].set_Critical(0);
                    Heroes[1].set_Regen(0);
                    Heroes[1].set_Strength(150);
                    Heroes[2].set_Dodge(0);
                    Heroes[2].set_Critical(0);
                    Heroes[2].set_Regen(0);
                    Heroes[2].set_Strength(150);
                }

                // if test mode is off
                if (TEST_MODE == false)
                {
                    system("clear"); // clear page
                }

                // if player uses "action"
                if (action == "Action" || action == "action" || action == "a" || action == "A")
                {
                    int *values = get_Damage(turn, Heroes[2], Heroes[1]); // function for attacking

                    if (turn % 2 == 0) // player 2 hits player 1
                    {
                        Heroes[1].set_Health(values[0]);
                        Heroes[2].set_Mana(values[1]);
                        Heroes[2].set_Health(values[2]);
                    }
                    else if (turn % 2 != 0) // player 1 hits player 2
                    {
                        Heroes[2].set_Health(values[0]);
                        Heroes[1].set_Mana(values[1]);
                        Heroes[1].set_Health(values[2]);
                    }

                    // delete dynamic array
                    delete [] values;
                }

                // if player uses "item"
                else if (action == "Item" || action == "item" || action == "I" || action == "i")
                {
                    // if there isn't any more item in your inventory
                    if ((turn % 2 != 0 && item_number_1 == 0)||(turn % 2 == 0 && item_number_2 == 0))
                    {
                        cout << "there isn't any items left in your inventory" << endl;
                        goto endloop; // exit item loop
                    }

                    // if there is item in your inventory
                    cout << "What item would you like to use?" << endl;
                    cout << "Health potion (H) (300~400) | Damage potion (D) (150~250)" << endl;
                    cin >> item_choice;

                    // if test mode is off
                    if (TEST_MODE == false)
                    {
                        system("clear"); // clear page
                    }

                    int *item = get_Item(item_choice, turn, Heroes[1], Heroes[2], TEST_MODE); // function for item use

                    if (turn % 2 == 0) // healing player 2
                    {
                        Heroes[1].set_Health(item[1]);
                        Heroes[2].set_Health(item[0]);
                        item_number_2--; // item count for player 2 minus 1
                    }
                    else if (turn % 2 != 0) // healing player 1
                    {
                        Heroes[2].set_Health(item[1]);
                        Heroes[1].set_Health(item[0]);
                        item_number_1--; // item count for player 1 minus 1
                    }

                    // delete the dynamic array
                    delete [] item;
                }

                endloop: // used for item

                // put all this inside a function instead
                int h1_space = 50 - to_string(Heroes[1].get_Health()).length(); // Spacing for health
                int m1_space = 52 - to_string(Heroes[1].get_Mana()).length(); // Spacing for mana
                int d1_space = 49 - to_string(Heroes[1].get_Defense()).length(); // Spacing for defense

        		// 4 digits max for stats of player 2
                int h2_space = 6 - to_string(Heroes[2].get_Health()).length();
                int m2_space = 6 - to_string(Heroes[2].get_Mana()).length();
                int d2_space = 6 - to_string(Heroes[2].get_Defense()).length();

        		// Main game page
                cout << "-------------------------------------------------------------------" << endl;
                cout << "|  " << Heroes[1].get_Name() << setw(name_space) << Heroes[2].get_Name() << "  |" << endl;
                cout << "|  health: " << Heroes[1].get_Health() << setw(h1_space) << "health: " << Heroes[2].get_Health() << setw(h2_space) << " |" << endl;
                cout << "|  mana: " << Heroes[1].get_Mana() << setw(m1_space) << "mana: " << Heroes[2].get_Mana() << setw(m2_space) <<" |" << endl;
                cout << "|  defense: " << Heroes[1].get_Defense() << setw(d1_space) << "defense: " << Heroes[2].get_Defense() << setw(d2_space) << " |" << endl;
                cout << "|  " << setw(64) << " |" << endl;
                cout << "|  " << setw(64) << " |" << endl;
                cout << "|  Action"<< setw(55) << "Item ";
                if (turn % 2 == 0)
                {
                    cout << item_number_1;
                }
                else if (turn % 2 != 0)
                {
                    cout << item_number_2;
                }
                cout << " |" << endl;
                cout << "-------------------------------------------------------------------" << endl;
                cout << endl;

                // asks user what they want to do for their turn
                if (turn % 2 == 0) // asks player 1
                {
                    cout << "What would you like to do, " << Heroes[1].get_Name() << "?: ";
                }
                else if (turn % 2 != 0) // asks player 2
                {
                    cout << "What would you like to do, " << Heroes[2].get_Name() << "?: ";
                }

                cin >> action; // asks for action

                turn++; // turn in game plus 1
            }

            // if any player died
            if (Heroes[1].get_Health() <= 0) // if player 1 died
            {
                cout << Heroes[1].get_Name() << " has died, play again? (Yes/No)" << endl;
            }
            else if (Heroes[2].get_Health() <= 0) // if player 2 died
            {
                cout << Heroes[2].get_Name() << " has died, play again? (Yes/No)" << endl;
            }
            cin >> again; // asks user if they want to play again

            int play_again = 1;
            while (play_again == 1)
            {
                // if players choose to play again
                if (again == "Y" || again == "y" || again == "Yes" || again == "yes")
                {
                    cout << "Okey! have fun!" << endl;
                    cout << "Press Enter key to continue" << endl;
                    cin.ignore();
                    cin.get();
                    play_again = 0; // play again ends
                    option = "1"; // go back to game page
                }
                // if players choose to not play again
                else if (again == "N" || again == "n" || again == "No" || again == "no")
                {
                    play_again = 0; // play again ends
                    option = "0"; // go back to option page
                }
                // if players enter an invalid choice
                else
                {
                    // if test mode is off
                    if (TEST_MODE == false)
                    {
                        system("clear"); // clear page
                    }
                    cout << "Do you want to play again?" << endl;
                    cout << "please enter a valid choice! (Yes/No)" << endl;
                    cin >> again; // asks the user for valid choice
                }
            }
        }

        // help page
        else if (option == "2")
        {
            // explains the game
            cout << "Heroes is a 2 player game, of which the goal is to kill the other player" << endl;
            cout << "The initial values for each character is set, of which you'll have to pick one before starting" << endl;
            cout << "After the game starts, you are able to see your character's stats as well as the opponents" << endl;
            cout << "During the game, you are able to either use an action, an item or ability" << endl;
            cout << endl;
            cout << "Both actions and item all cost a turn" << endl;
            cout << "To use action, simply type 'a' when it is your turn" << endl;
            cout << "To use item, simply type 'i' when it is your turn" << endl;
            cout << "Be aware, you cannot use item if you don't have any in your inventory and you would waste a turn" << endl;
            cout << "Also, if you use an action that's not 'action' or 'item' would also waste a turn" << endl;
            cout << endl;
            cout << "Mana can be obtained through any successful hit to the opponent" << endl;
            cout << "Extra mana can be gained if a critical hit landed" << endl;
            cout << "Every 100 mana would be automatically turned into 100 health" << endl;
            cout << endl;

            cout << "Press Enter key to return" << endl;
            cin.ignore();
            cin.get();
            option = "0"; // go back to option page
        }
        // credit page
        else if (option == "3")
        {
            cout << "Idea: Frank" << endl;
            cout << "Design: Frank" << endl;
            cout << "Code: Frank" << endl;
            cout << "Conclusion: it is all done by Frank" << endl;
            cout << endl;

            cout << "Press Enter key to return" << endl;
            cin.ignore();
            cin.get();
            option = "0"; // go back to option page
        }

        else if (option == "4")
        {
            cout << "Thank you for playing this game!" << endl;
            cout << endl;

            cout << "Press Enter key to continue" << endl;
            cin.ignore();
            cin.get();
            game_end = 1; // end the game
        }
    }
    return 0;
}
