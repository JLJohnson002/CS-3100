// 1. Jimmy Johnson
// 2. 11/14/2023
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

    ifstream myfile("dictionary.txt");
    string word;
    if (myfile.is_open())
    {
        while (myfile)
        {
            myfile >> word;
            test1.insert(word);
        }
    }

    while (true)
    {
        string wordPrefix;
        string response;

        cout << "Please enter a word prefix (or press enter to exit): ";
        getline(cin, wordPrefix);

        if (wordPrefix == "")
        {
            break;
        }

        cout << "There are " << test1.completeCount(wordPrefix)
             << " completions for the prefix '" << wordPrefix
             << "'. Show completions? ";
        getline(cin, response);

        if (response == "yes")
        {
            cout << "-----------" << endl;
            test1.complete(wordPrefix);

            for (string each : test1.wordList)
            {
                cout << each << endl;
            }
            cout << endl;
        }
        else
        {
            continue;
        }
    }
}