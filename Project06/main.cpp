#include "shuffle.h"

#include <iostream> 
#include <array>

int main()
{
    array arrayShuffle = makeShuffledArray(); // you may have to say array<unsigned int, N> if compiler gives errors

    cout << "shuffled elements:";
    for (const int& number : arrayShuffle)
    {
        // this is just fancy loop syntax where the variable number loops through each element
        cout << ' ' << number;
    }
    cout << '\n';

    // example output:
    // shuffled elements: 5 2 10 9 16 8 13 17 11 1 12 3 14 15 7 4 6 18 19

    return 0;
}