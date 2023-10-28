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
    for (int i = 0; i < 10000; i++)
    {
        string value = ("junk");
        test1.insert(i, value);
    }
    cout << "SIZE" << test1.getSize() << endl;
    cout << "high" << test1.getHeight() << endl;
    cout << test1 << endl;
    test1.print(cout);
    if (test1.insert(10, "10") == true)
    {
        cout << "inserted-TRUE" << endl;
    }
    else if (test1.insert(10, "10") == false)
    {
        cout << "not inserted-FALSE" << endl;
    }
    string value = "one";
    test1.find(1, value);

    cout << "End" << endl;
}