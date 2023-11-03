#pragma once

#include <iostream>

using namespace std;

class Trie
{
public:
    class TrieNode
    {
    public:
        int key;

        // TrieNode *97;// Int pointers dont work
        TrieNode *a;// char pointers do work
        TrieNode *right; // string pointer works

        TrieNode(int newKey)
        {
            key = newKey;

            for (int i = 97; i < 123; i++)
            {
                char child = (char)i;
                TrieNode *child = nullptr;
            }
        }
    };

    // Constructor
    Trie();

    // Copy constructor
    Trie(const Trie &s);

    // Deconstructor
    ~Trie();

    bool insert(string word);
private:
    // Components of a Trie
    TrieNode *root;
    int numElts;
};