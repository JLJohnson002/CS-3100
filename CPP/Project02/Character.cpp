#include "Character.h"
#include "iostream"

using namespace std;

// Constructors
Character::Character()
{
    name = "Null";
    role = "Void";
    health = 0;
    attackBonus = 0;
    damageBonus = 0;
    armorClass = 0;
}

Character::Character(string newName, string newRole,
                     int newHitPoints, int newAttackBonus,
                     int newDamageBonus, int newArmorClass)
{
    name = newName;
    role = newRole;
    health = newHitPoints;
    attackBonus = newAttackBonus;
    damageBonus = newDamageBonus;
    armorClass = newArmorClass;
}

// Getters
int Character::getHealth()
{
    return health;
}

int Character::getArmorClass()
{
    return armorClass;
}

string Character::getName()
{
    return name;
}

string Character::getRole()
{
    return role;
}

// Setters
void Character::setHealth(int newHealth)
{
    health = newHealth;
}

// Other Functions
void Character::print(ostream &os)
{
    os << "Character Summary" << endl;
    os << "-----------------" << endl;
    os << name << " the " << role << endl;
    os << "HP: " << health << endl;
    os << "AB: " << attackBonus << endl;
    os << "DB: " << damageBonus << endl;
    os << "AC: " << armorClass << endl;
    os << endl;
}

void Character::attack(Character &otherCharacter)
{
    int dieAttack;
    int dieDamage;

    dieAttack = rand() % 20 + 1;

    if (dieAttack + attackBonus >= otherCharacter.getArmorClass())
    {
        dieDamage = rand() % 10 + 1;
        otherCharacter.damage(dieDamage + damageBonus);
    }
}

void Character::damage(int amount)
{
    health -= amount;
    if (health < 0)
    {
        health = 0;
    }
}