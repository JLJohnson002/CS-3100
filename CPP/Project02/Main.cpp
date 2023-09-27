// 1. Jimmy Johnson
// 2. 09/26/2023
// 3. Project 2 RPG Game

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Character.h"
#include <time.h>

using namespace std;

int main()
{   
    // Variable creation
    srand((unsigned)time(NULL));
    int attackingPlayer = 1;
    string name;
    string role;
    int health;
    int attackBonus;
    int damageBonus;
    int armorClass;

    // First character data input and creation
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

    Character player1 = Character(name, role, health, 
                                  attackBonus, damageBonus, armorClass);

    player1.print(cout);

    // Second player data input and creation
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

    Character player2 = Character(name, role, health, 
                                  attackBonus, damageBonus, armorClass);

    player2.print(cout);

    // Start of simulation output
    cout << "Simulated Combat:" << endl;

    // While the players have health left, keep fighting
    while (player1.getHealth() != 0 && player2.getHealth() != 0)
    {
        if (attackingPlayer == 1)// If player 1 is attacking
        {
            cout << player1.getName() << " attacks!" << endl;
            player1.attack(player2);
            attackingPlayer = 2;
        }
        else // If player 2 is attacking
        {
            cout << player2.getName() << " attacks!" << endl;
            player2.attack(player1);
            attackingPlayer = 1;
        }
    }

    // When either player gets to 0 health, they lose
    if (player1.getHealth() == 0)
    {
        cout << player2.getName() << " wins!" << endl;
    }
    else
    {
        cout << player1.getName() << " wins!" << endl;
    }
    cout << endl;
}