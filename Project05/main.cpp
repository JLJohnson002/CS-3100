#include <iostream>
#include "trie.h"
using namespace std;

int main()
{
    char myChar = 'c';
    int slot = (int)myChar - 'a'; // = 2

    cout << slot << endl;
    cout << (int)'a' << endl; // = 97
    cout << (int)'c' << endl; // = 99
    cout << (int)'d' << endl; // = 100
    cout << (int)'~' << endl; // = 126
    cout << (int)'$' << endl; // = 36
    cout << (char)100 << endl
         << endl; // = 100 D
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (char letter : alphabet)
    {
        cout << letter << " - " << (int)letter << endl;
    }
}