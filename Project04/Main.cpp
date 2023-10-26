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
    test1.insert(40,"fourty");
    cout << test1 << endl;



    cout << "End" << endl;
}