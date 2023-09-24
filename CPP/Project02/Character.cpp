#include "Character.h"
#include "iostream"

using namespace std;

Character::Character()
{
    name = "Null";
    role = "Void";
    hitPoints = 0;
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
    hitPoints = newHitPoints;
    attackBonus = newAttackBonus;
    damageBonus = newDamageBonus;
    armorClass = newArmorClass;
}

// Character::~Character()
// {
//     // fixme
// }

int Character::getHealth()
{
    return hitPoints;
}

string Character::getName()
{
    return name;
}

string Character::getRole()
{
    return role;
}

void Character::print(ostream &os)
{
    os << "Character Summary" << endl;
    os << "-----------------" << endl;
    os << name << " the " << role << endl;
    os << "HP: " << hitPoints << endl;
    os << "AB: " << attackBonus << endl;
    os << "DB: " << damageBonus << endl;
    os << "AC: " << armorClass << endl;
    os << endl;
}
void attack(Character &otherCharacter)
{
    // fixme
}
void damage(int amount)
{
    // fixme
}