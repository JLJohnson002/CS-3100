// 1. Jimmy Johnson
// 2. 11/14/2023
// 3. Project 5 Uncompressed Alphabet Trie

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Trie
{
public:
    // Global variable
    vector<string> wordList;

    // A node of a trie
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

    // Copy Constructor
    Trie(const Trie &s);

    // Copy Helper
    void copy(const TrieNode * const &from, TrieNode *&to);

    // Destructor
    ~Trie();

    // Destructor Helper
    void kill(TrieNode *cur);

    // Insert function
    bool insert(string word);

    // Count returns the number of words
    int count();

    // getSize returns the number of nodes
    int getSize();

    // Returns true if found and false otherwise
    bool find(string word);

    // Returns the number of words that start with a given string
    int completeCount(string);

    // Recursive helper for completeCount()
    int countHelper(TrieNode *cur);

    // Returns a vector with all strings starting with a given string
    vector<string> complete(string);

    // Recursive helper for complete()
    vector<string> completeHelper(TrieNode *cur, string word);

    // Overload for = constructor to copy tries
    Trie& operator=(const Trie &trie2);

private:
    // Components of a Trie
    TrieNode *root;
    int numWords;
    int numNodes;
};