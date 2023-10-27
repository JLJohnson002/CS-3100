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
    test1.insert(30, "thirty");
    test1.insert(50, "fifty");
    test1.insert(35, "thirty-five");
    test1.insert(60, "sixty");
    test1.insert(70, "seventy");
    cout << test1.getSize() << endl;
    cout << test1.getHeight() << endl;
    if (test1.insert(30, "thirty") == true)
    {
        cout << "inserted-TRUE" << endl;
    }
    else if (test1.insert(30, "thirty") == false)
    {
        cout << "not inserted-FALSE" << endl;
    }

    cout << "End" << endl;
}