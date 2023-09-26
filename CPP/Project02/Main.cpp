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
    int stopLoop = 0;
    int attackingPlayer = 1;

    Character player1 = Character("Uglar", "Barbarian", 80, 5, 5, 24);
    Character player2 = Character("Zimzizz", "Wizard", 40, 5, 15, 18);

    player1.print(cout);
    player2.print(cout);

    while (player1.getHealth() != 0 && player2.getHealth() != 0)
    {
        if (attackingPlayer == 1)
        {
            player1.attack(player2);
            cout << "P2 health remaining: " << player2.getHealth();
            attackingPlayer = 2;
        }
        else
        {
            player2.attack(player1);
            cout << " --- P1 health remaining: " << player1.getHealth() << endl;
            attackingPlayer = 1;
        }
        stopLoop++;
        if (stopLoop > 5000)
        {
            cout << "LOOP BREAK" << endl;
            break;
        }
    }
    cout << endl;
    cout << "done" << endl;
}
