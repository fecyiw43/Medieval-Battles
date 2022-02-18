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
    string option = "0"; // 0 = main option page, 1 = game page, 3 = help page, 4 = credit page
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
            cout << "Please enter a valid whole number (1-4)" << endl;
            cin >> option;
            if (option == "1" || option == "2" || option == "3" || option == "4")
            {
                goto out;
            }
        }

        out:

        if (TEST_MODE == false)
        {
            system("clear"); // clear page
        }
    }
    cout << "Success" << endl;

    return 0;
}
