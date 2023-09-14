// 1. Jimmy Johnson
// 2. 09/13/2023
// 3. Project 1 Dice Game

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int dieRoll();

int main() {
    srand ((unsigned) time(NULL));

    int rollCount;
    int totals [11] = {};

    cout << "How many rolls? ";
    cin >> rollCount;
    cout << "Simulating " << rollCount << " rolls..." << endl;


    for (int i = 0; i < rollCount; i ++){
        // Rolls a pair of dice however many times asked and tallies up the results

        totals [(dieRoll()-2)] ++;
    }

    cout << "Results:" << endl;
    for (int i = 0; i < 11; i++){
        // Prints out the results

        cout << i + 2 << " was rolled " << totals[i];
        if (totals[i] == 1){
            cout << " time" <<endl;
        }
        else{
        cout << " times" <<endl;
        }
    }
}

int dieRoll() {
    // Initilizes two dice and rolls them, then returns the product.

    int die1;
    int die2;

    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;

    return die1 + die2;
}