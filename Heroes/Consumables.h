#ifndef CONSUMABLES__
#define CONSUMABLES__
#include "item.h"
#include "Character.h"
#include <string>

class Health_potion : public item
{
public:
        virtual int use(Character Heroes, bool TEST_MODE);
};

class Damage_potion : public item
{
public:
        virtual int use(Character Heroes, bool TEST_MODE);
};

#endif