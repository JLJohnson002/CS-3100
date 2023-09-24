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


    cout << "Hello" << endl;
    Character player1 = Character("Jim", "Sloth", 5, 10, 15, 20);
    Character player2 = Character("Marie", "Beast", 50, 100, 150, 200);

    player1.print(cout);
    player2.print(cout);

    while (player1.getHealth() != 0 && player2.getHealth() != 0)
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
