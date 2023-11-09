// 1. Jimmy Johnson
// 2. 11/08/2023
// 3. Project 5 Uncompressed Alphabet Trie

#include <iostream>
#include <fstream>
#include <string>
#include "trie.h"
using namespace std;

// Used code from
// https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html
// to intake from a file

int main()
{
    Trie test1;
    test1.insert("test");
    test1.insert("tester");
    test1.insert("testing");

    Trie test2 = Trie(test1);
    cout << "done" << endl;
}
// Trie test1;
// string alphabet = "abcdefghijklmnopqrstuvwxyz";
// for (char letter : alphabet)
// {
//     cout << letter << " - " << (int)letter << " - " << (int)letter - 'a' << endl;
// }

// ifstream myfile("dictionary.txt");
// string word;
// cout << "start" << endl;
// if (myfile.is_open())
// {
//     while (myfile)
//     {
//         myfile >> word;
//         test1.insert(word);
//     }
// }
// cout << "words = " << test1.count() << endl;
// cout << "nodes = " << test1.getSize() << endl;
// cout << test1.find("a") << endl;
// if (test1.find("a"))
// {
//     cout << "found 'a'" << endl;
// }
// else
// {
//     cout << "did not find 'a'" << endl;
// }
// if (test1.find("aa"))
// {
//     cout << "found 'aa'" << endl;
// }
// else
// {
//     cout << "did not find 'aa'" << endl;
// }
// cout << test1.find("abracadabra") << endl;
// cout << test1.find("aa") << endl;
// cout << "done" << endl;

// char myChar = 'c';
// int slot = (int)myChar - 'a'; // = 2

// cout << slot << endl;
// cout << (int)'a' << endl; // = 97
// cout << (int)'c' << endl; // = 99
// cout << (int)'d' << endl; // = 100
// cout << (int)'~' << endl; // = 126
// cout << (int)'$' << endl; // = 36
// cout << (char)100 << endl
//      << endl; // = 100 D
// cout << endl;
// test1.insert("test");
// test1.insert("tester");
// test1.insert("testing");
// test1.insert("testing");
// test1.insert("a");
// test1.insert("b");
// test1.insert("c");
// test1.insert("d");
// test1.insert("e");
// test1.insert("f");
// test1.insert("g");
// test1.insert("h");
// test1.insert("i");
// test1.insert("j");
// test1.insert("k");
// test1.insert("l");
// test1.insert("m");
// test1.insert("n");
// test1.insert("o");
// test1.insert("p");
// test1.insert("q");
// test1.insert("r");
// test1.insert("s");
// test1.insert("t");
// test1.insert("u");
// test1.insert("v");
// test1.insert("w");
// test1.insert("x");
// test1.insert("y");
// test1.insert("z");