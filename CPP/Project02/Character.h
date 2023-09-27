// 1. Jimmy Johnson
// 2. 09/26/2023
// 3. Project 2 RPG Game

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

    // Getters
    int getHealth();
    int getArmorClass();
    string getName();
    string getRole();

    // Setters
    void setHealth(int);

    // Other Functions
    void print(ostream &);
    void attack(Character &otherCharacter);
    void damage(int amount);
};