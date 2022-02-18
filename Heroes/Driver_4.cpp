#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include <cstdlib>
#include <stdlib.h>

using namespace std;

int main()
{
    bool TEST_MODE;
    cin >> TEST_MODE;
    string name[3];
    string choices[3];

    // asking for player names
    for (int i = 1; i < 3; i++)
    {
        cout << "Please enter your name player " << i << endl;
        cin >> name[i];
    }

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

        if (choices[i] == "1" || choices[i] == "2" || choices[i] == "3" || choices[i] == "4")
        {
            goto end;
        }

        while (choices[i] != "1" || choices[i] != "2" || choices[i] != "3" || choices[i] != "4")
        {
            cout << "Failed, Please enter a valid number between 1-4" << endl;
            cin >> choices[i];
            if (choices[i] == "1" || choices[i] == "2" || choices[i] == "3" || choices[i] == "4")
            {
                goto end;
            }
        }
        end:

        if (TEST_MODE == false)
        {
            system("clear"); // clear page
        }
    }
    cout << "Success" << endl;

    return 0;
}
