#include <iostream>
#include "trie.h"
using namespace std;

int main()
{
    Trie test1;
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
    cout << "length " << alphabet.length() << endl;
    for (char letter : alphabet)
    {
        cout << letter << " - " << (int)letter << endl;
        // test1.insert(""+letter+"");
    }
    cout << endl;
    cout << "start" << endl;
    // test1.insert("test");
    // test1.insert("tester");
    // test1.insert("testing");
    // test1.insert("testing");
    test1.insert("a");
    test1.insert("b");
    test1.insert("c");
    test1.insert("d");
    test1.insert("e");
    test1.insert("f");
    test1.insert("g");
    test1.insert("h");
    test1.insert("i");
    test1.insert("j");
    test1.insert("k");
    test1.insert("l");
    test1.insert("m");
    test1.insert("n");
    test1.insert("o");
    test1.insert("p");
    test1.insert("q");
    test1.insert("r");
    test1.insert("s");
    test1.insert("t");
    test1.insert("u");
    test1.insert("v");
    test1.insert("w");
    test1.insert("x");
    test1.insert("y");
    test1.insert("z");
    cout << "done" << endl;
}