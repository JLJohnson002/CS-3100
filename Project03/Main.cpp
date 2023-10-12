#include <iostream>
#include <exception>
#include "sequence.h"

using namespace std;

int main()
{
    cout << "start" << endl;
    Sequence test5(5);
    test5.print(cout);
    for (int i = 0; i <= test5.size() - 1; i++)
    {
        test5[i] = i + 1;
    }
    test5.print(cout);
    test5.push_back(6);
    test5.print(cout);
    test5.pop_back();
    test5.pop_back();
    test5.pop_back();
    test5.print(cout);

    cout << "end" << endl;
}