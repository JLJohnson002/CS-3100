// 1. Jimmy Johnson
// 2. 09/23/2023
// 3. Project 2 RPG Game

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Character.h"
#include <time.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int attackingPlayer = 1;
    string name;
    string role;
    int health;
    int attackBonus;
    int damageBonus;
    int armorClass;

    cout << "First character's name?" << endl;
    cin >> name;
    cout << endl;
    cout << name << "'s role?" << endl;
    cin >> role;
    cout << endl;
    cout << name << " the " << role << "'s hit points?" << endl;
    cin >> health;
    cout << endl;
    cout << name << " the " << role << "'s attack bonus?" << endl;
    cin >> attackBonus;
    cout << endl;
    cout << name << " the " << role << "'s damage bonus?" << endl;
    cin >> damageBonus;
    cout << endl;
    cout << name << " the " << role << "'s armor class?" << endl;
    cin >> armorClass;
    cout << endl;
    // Character player1 = Character(name, role, health, attackBonus, damageBonus, armorClass);
    Character player1 = Character("Ulgar", "Barbarian", 20, 5, 5, 10);
    player1.print(cout);

    cout << "Second character's name?" << endl;
    cin >> name;
    cout << endl;
    cout << name << "'s role?" << endl;
    cin >> role;
    cout << endl;
    cout << name << " the " << role << "'s hit points?" << endl;
    cin >> health;
    cout << endl;
    cout << name << " the " << role << "'s attack bonus?" << endl;
    cin >> attackBonus;
    cout << endl;
    cout << name << " the " << role << "'s damage bonus?" << endl;
    cin >> damageBonus;
    cout << endl;
    cout << name << " the " << role << "'s armor class?" << endl;
    cin >> armorClass;
    cout << endl;
    // Character player2 = Character(name, role, health, attackBonus, damageBonus, armorClass);
    Character player2 = Character("Zimzizz", "Wizzard", 40, 6, 6, 9);
    player2.print(cout);
    cout << "Simulated Combat:" << endl;

    while (player1.getHealth() != 0 && player2.getHealth() != 0)
    {
        if (attackingPlayer == 1)
        {
            cout << player1.getName() << " attacks!" << endl;
            player1.attack(player2);
            attackingPlayer = 2;
        }
        else
        {
            cout << player2.getName() << " attacks!" << endl;
            player2.attack(player1);
            attackingPlayer = 1;
        }
    }
    if (player1.getHealth() == 0)
    {
        cout << player2.getName() << " wins!" << endl;
    }
    else
    {
        cout << player1.getName() << " wins!" << endl;
    }
    cout << endl;
    cout << "done" << endl;
}
// Simulated Combat:
// Uglar attacks!
// Attack roll: 14 + 5 = 19 --> HIT!
// Damage: 9 + 5 = 14
// Zimzizz has 26 hit points remaining

// Zimzizz attacks!
// Attack roll: 17 + 5 = 22 --> MISS!

// Uglar attacks!
// Attack roll: 13 + 5 = 18 --> HIT!
// Damage: 8 + 5 = 13
// Zimzizz has 13 hit points remaining

// Zimzizz attacks!
// Attack roll: 19 + 5 = 24 --> HIT!
// Damage:  8 + 15 = 23
// Uglar has 57 hit points remaining

// Uglar attacks!
// Attack roll: 16 + 5 = 21 --> HIT!
// Damage: 9 + 5 = 14
// Zimzizz has 0 hit points remaining

// Uglar wins!
