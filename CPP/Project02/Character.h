// data

// name (string)            check
// role (string)            check
// hit points (int)         check
// attack bonus (int)       check
// Damage Bonus (int)       check
// armor class (int)        check

// functions

// print (ostream&)         check
// attack (Charcter &otherCharacter)    todo
// damage  (int amount)                 todo

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
    int health;
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

    // Setters
    void setHealth(int);

    // Other Functions
    void print(ostream &);
    void attack(Character &otherCharacter);
    void damage(int amount);
};