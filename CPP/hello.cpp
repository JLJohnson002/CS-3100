#include <iostream>
#include <cstdlib>


using namespace std;

int main() {
    int * p;
    int myArray[5] = {1,2,3,4,5};
    p = myArray;

    // Print myArray
    for (int value : myArray){
        cout << value << "  ";
    }

    cout << endl;

    // Add 1 to each in myArray
    for (int i = 0; i < 5; i++){
        *p += 1;
        p++;
    }

    // Print myArray
    for (int value : myArray){
        cout << value << "  ";
    }
    
    cout << endl;


    srand (1000);
    int randNum;

    randNum = rand();
    cout << randNum << endl;

    randNum = rand();
    cout << randNum << endl;

}
