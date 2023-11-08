// 1. Jimmy Johnson
// 2. 11/08/2023
// 3. Project 5 Uncompressed Alphabet Trie

#pragma once

#include <iostream>

using namespace std;

class Trie
{
public:
    class TrieNode
    {
    public:
        bool endOfWord = false;
        TrieNode *children[26];
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    // Constructor
    Trie();

    // Copy constructor
    // Trie(const Trie &s);

    // Deconstructor
    // ~Trie();

    bool insert(string word);

    int count();

    int getSize();

    bool find(string);

private:
    // Components of a Trie
    TrieNode *root;
    int numWords;
    int numNodes;
};