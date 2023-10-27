#include <iostream>
#include <iomanip>
#include <fstream>

#include "AVLTree.h"
using namespace std;

int main()
{
    cout << "Start" << endl;

    AVLTree test1;
    cout << test1 << endl;
    test1.insert(40, "fourty");
    test1.insert(50, "fifty");
    test1.insert(60, "sixty");
    test1.insert(70, "seventy");
    test1.insert(30, "thirty");
    if (test1.insert(30, "thirty") == true)
    {
        cout << "TRUE" << endl;
    }
    else if (test1.insert(30, "thirty") == false)
    {
        cout << "FALSE" << endl;
    }
    cout << test1 << endl;

    cout << "End" << endl;
}