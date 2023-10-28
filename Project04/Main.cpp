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
    test1.insert(1, "1");
    test1.insert(2, "2");
    test1.insert(3, "3");
    test1.insert(4, "4");
    test1.insert(5, "5");
    test1.insert(6, "6");
    test1.insert(7, "7");
    test1.insert(8, "8");
    test1.insert(9, "9");
    test1.insert(100, "100");
    test1.insert(99, "99");
    test1.insert(88, "88");
    test1.insert(77, "77");
    test1.insert(66, "66");
    test1.insert(55, "55");
    test1.insert(44, "44");
    test1.insert(33, "33");
    test1.insert(22, "22");
    test1.insert(11, "11");
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