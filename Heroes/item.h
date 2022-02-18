#ifndef ITEM__
#define ITEM__
#include <string>
#include "Character.h"

class item
{
public:
        item();
        // absolute virtual for item use
        virtual int use(Character Heroes, bool TEST_MODE) = 0;
};
#endif // item__