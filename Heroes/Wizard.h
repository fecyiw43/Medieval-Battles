#ifndef WIZARD__
#define WIZARD__
#include <string>
#include "Character.h"

using namespace std;

class Wizard : public Character
{
public:
        Wizard(string wName, int wMax, int wHealth, int wMana, int wDefense, int wStrength, float wDodge, float wCritical, float wRegen);
        // Ability
};
#endif // Wizard__