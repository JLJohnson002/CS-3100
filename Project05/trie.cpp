#include "trie.h"

Trie::Trie()
{
    // TrieNode *root = new TrieNode();
    numElts = 0;
}

Trie::Trie(const Trie &s)
{
}

Trie::~Trie()
{
}

bool Trie::insert(string word)
{
    TrieNode *cur = root;

    for (int i = 0; i < word.length(); i++)
    {
        char letter = word[i];
        // FIXME can i put word[i] in (int)letter -- (int)word[i]
        int asciiConversion = (int)letter - 'a';

        if (cur->children[asciiConversion] == nullptr)
        {
            cur->children[asciiConversion] = new TrieNode();
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
        numElts++;
        return true;
    }
}
