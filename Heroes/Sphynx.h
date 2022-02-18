#ifndef SPHYNX__
#define SPHYNX__
#include <string>
#include "Character.h"

using namespace std;

class Sphynx : public Character
{
public:
        Sphynx(string sName, int sMax, int sHealth, int sMana, int sDefense, int sStrength, float sDodge, float sCritical, float sRegen);
        // Ability
};
#endif // Sphynx__