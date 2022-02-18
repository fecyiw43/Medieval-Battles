#ifndef WARRIOR__
#define WARRIOR__
#include <string>
#include "Character.h"

using namespace std;

class Warrior : public Character
{
public:
        Warrior(string aName, int aMax, int aHealth, int aMana, int aDefense, int aStrength, float aDodge, float aCritical, float aRegen);
        // Warrior ability goes here
};
#endif // Warrior__