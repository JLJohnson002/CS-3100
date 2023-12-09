#include "HashTable.h"
#include "Database.h"

#include <iostream>
#include <array>
using namespace std;

int main()
{
    int collisions = 0;

    HashTable test;

    test.insert(112233, 2, collisions);
    cout << "after first " << collisions << endl;
    test.insert(112233, 0, collisions);
    cout << "after second " << collisions << endl;
    test.insert(334455, 1, collisions);

    cout << test.alpha() << endl;
    cout << collisions << endl;

    cout << test;
    Database test1;


}
/*
code hashtable
code database
put hashtable in database
make main file
main file control database
database control hashtable
*/