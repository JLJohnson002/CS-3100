// data

// name (string)            check
// role (string)            check
// hit points (int)         check
// attack bonus (int)       check
// Damage Bonus (int)       check
// armor class (int)        check

// functions

// print (ostream&)
// attack (Charcter &otherCharacter)
// damage  (int amount)

// gethealth () int
// getname () string
// getrole () string
#include <string>
using namespace std;

class Character
{

    // Data
    private:
    string name;
    string role;
    int hitPoints;
    int attackBonus;
    int damageBonus;
    int armorClass;

    public:
    // Constructors
    Character();

    Character(string, string, int, int, int, int);

    // Destructor
    //~Character();

    // Getters
    int getHealth();
    string getName();
    string getRole();

    // Other Functions
    void print(ostream &);
    void attack(Character &otherCharacter);
    void damage(int amount);
};