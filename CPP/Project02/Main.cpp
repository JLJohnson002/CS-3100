// 1. Jimmy Johnson
// 2. 09/23/2023
// 3. Project 2 RPG Game

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Character.h"

using namespace std;

int main()
{
    int stopLoop = 0;

    Character player1 = Character("Uglar", "Barbarian", 80, 5, 5, 24);
    Character player2 = Character("Zimzizz", "Wizard", 40, 5, 15, 18);

    player1.print(cout);
    player1.setHealth(1);
    player1.print(cout);

    while (player1.getHealth() != 0 || player2.getHealth() != 0)
    {
        cout << "playing" << endl;
        stopLoop++;
        if (stopLoop < 10)
        {
            break;
        }
    }
    cout << "done" << endl;
}
