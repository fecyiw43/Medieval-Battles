#ifndef CHARACTER__
#define CHARACTER__
#include <string>

using namespace std;

class Character
{
public:
        // Constructors
        Character();
        Character(string cname, int cMax, int cHealth, int cMana, int cDefense, int cStrength, float cDodge, float cCritical, float cRegen);

        // Methods
        // getters
        void get_all();
        string get_Name();
        int get_Health();
        int get_Max();
        int get_Mana();
        int get_Defense();
        int get_Strength();
        float get_Dodge();
        float get_Critical();
        float get_Regen();

        // setters
        void set_Name(string nam);
        void set_Health(int hp);
        void set_Max(int maxx);
        void set_Mana(int ma);
        void set_Defense(int def);
        void set_Strength(int str);
        void set_Dodge(float dod);
        void set_Critical(float cri);
        void set_Regen(float reg);

protected:
        // variables (uninitialised)
        string name;
        int max;
        int health;
        int mana;
        int defense;
        int strength;
        float dodge;
        float critical;
        float regen;

        string nam;
        int maxx;
        int hp;
        int ma;
        int def;
        int str;
        float dod;
        float cri;
        float reg;

};
#endif // Character__