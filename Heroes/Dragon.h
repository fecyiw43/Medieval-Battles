#ifndef DRAGON__
#define DRAGON__
#include <string>
#include "Character.h"

using namespace std;

class Dragon : public Character
{
public:
        Dragon(string dName, int dMax, int dHealth, int dMana, int dDefense, int dStrength, float dDodge, float dCritical, float dRegen);
};
#endif // Dragon__