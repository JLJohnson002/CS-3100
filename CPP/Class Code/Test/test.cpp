// #include <iostream>
// using namespace std;
// int main() {
//   int i = 7;
//   int array[5];
//   int j = 12;

//   for (int index = 0; index < 7; index++) {
//     array[index] = index * 2;
//   }
//   cout << "done" << endl;
// }

#include <iostream>
#include <cstdlib>
// #include <stdlib.h>     /* srand, rand */
// #include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h>

using namespace std;

int main()
{
    int *p;
    int myArray[5] = {1, 2, 3, 4, 5};
    p = myArray;

    // Print myArray
    for (int value : myArray)
    {
        cout << value << "  ";
    }

    cout << endl;

    // Add 1 to each in myArray
    for (int i = 0; i < 5; i++)
    {
        *p += 1;
        p++;
    }

    // Print myArray
    for (int value : myArray)
    {
        cout << value << "  ";
    }

    cout << endl;

    srand(time(NULL));

    int randNum;

    randNum = rand() % 6 + 1;
    cout << randNum << endl;

    randNum = rand() % 6 + 1;
    cout << randNum << endl;
}