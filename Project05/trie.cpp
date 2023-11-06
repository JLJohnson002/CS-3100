// 1. Jimmy Johnson
// 2. 11/05/2023
// 3. Project 5 Uncompressed Alphabet Trie

#include "trie.h"

Trie::Trie()
{
    // TrieNode *root = new TrieNode();
    numWords = 0;
    numNodes = 1;
}

// Trie::Trie(const Trie &s)
// {
// }

// Trie::~Trie()
// {
// }

bool Trie::insert(string word)
{
    TrieNode *cur = root;
    for (unsigned int i = 0; i < word.length(); i++)
    {
        char letter = word[i];
        // FIXME can i put word[i] in (int)letter -- (int)word[i]
        int asciiConversion = (int)letter - 'a';

        if (cur->children[asciiConversion] == nullptr)
        {
            cur->children[asciiConversion] = new TrieNode();
            numNodes++;
            cur = cur->children[asciiConversion];
        }
        else
        {
            cur = cur->children[asciiConversion];
        }
    }
    if (cur->endOfWord)
    {
        return false;
    }
    else
    {
        cur->endOfWord = true;
        numWords++;
        return true;
    }
}

int Trie::count()
{
    return numWords;
}

int Trie::getSize()
{
    return numNodes;
}

bool Trie::find(string word)
{
    TrieNode *cur = root;
    for (unsigned int i = 0; i < word.length(); i++)
    {
        char letter = word[i];
        // FIXME can i put word[i] in (int)letter -- (int)word[i]
        int asciiConversion = (int)letter - 'a';

        if (cur->children[asciiConversion] == nullptr)
        {
            return false;
        }
        else
        {
            cur = cur->children[asciiConversion];
        }
    }
    if (cur->endOfWord)
    {
        return true;
    }
    else
    {
        return false;
    }
}
