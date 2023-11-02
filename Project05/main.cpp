#include <iostream>
using namespace std;

int main()
{
    char myChar = 'c';
    int slot = (int)myChar - 'a'; // = 2
    cout << slot << endl;
    cout << (int)'a' << endl; // = 97
    cout << (int)'c' << endl; // = 99
}