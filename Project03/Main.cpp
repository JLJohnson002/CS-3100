#include <iostream>
#include <exception>
#include "sequence.h"

using namespace std;

int main()
{
    cout << "start" << endl;
    Sequence test5(5);
    test5.print(cout);
    test5[0]=1;
    test5[1]=2;
    test5[2]=3;
    test5[3]=4;
    test5[4]=5;
    test5.print(cout);
    test5.push_back(6);
    test5.print(cout);
    test5.pop_back();
    test5.pop_back();
    test5.pop_back();
    test5.print(cout);


    cout << "end" << endl;
}