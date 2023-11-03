#include "trie.h"

Trie::Trie()
{
    root = nullptr;
    numElts = 0;
}

bool Trie::insert(string word)
{
    for (char letter : word)
    {
        insert((int)letter);
    }
}

bool Trie::insert(int charInt)
{
    TrieNode *cur = root;
    if (root == nullptr)
    {
        root = new TrieNode(charInt);
        numElts ++;
        return true;
    }
    return false;
}
