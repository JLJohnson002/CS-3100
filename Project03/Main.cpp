#include <iostream>
#include <exception>
#include "sequence.h"

using namespace std;

int main()
{
    cout << "start" << endl;
    Sequence test0(0);
    Sequence test1(1);
    Sequence test5(5);
    test5.print(cout);
    test0.print(cout);
    // test5[0]=1;
    // test5[1]=2;
    // test5[4]=3;
    // Sequence testCopy(test5);

    cout << "end" << endl;
}