// 1. Jimmy Johnson
// 2. 11/08/2023
// 3. Project 5 Uncompressed Alphabet Trie

#include "trie.h"

// Constructor
Trie::Trie()
{
    root = new TrieNode();
    numWords = 0;
    numNodes = 1;
}

// Copy Constructor
Trie::Trie(const Trie &s)
{
    root = new TrieNode();
    root = s.root;
    numWords = s.numWords;
    numNodes = s.numNodes;
    // FIXME
    // copy(s.root, this->root);
    copy(s.root, this->root);
}

// Copy Helper
void Trie::copy(const TrieNode * const &from, TrieNode *&to)
{
    to = new TrieNode();
    to->endOfWord = from->endOfWord;
    for (int i = 0; i < 26; i++)
    {
        if (from->children[i] != nullptr)
        {
            copy(from->children[i], to->children[i]);
        }
    }
}

// Destructor
Trie::~Trie()
{
    kill(root);
}

// Destructor Helper
void Trie::kill(TrieNode *&cur)
{
    for (int i = 0; i < 26; i++)
    {
        if (cur->children[i]!=nullptr){
            kill(cur->children[i]);
        }
    }
    delete cur;
}

bool Trie::insert(string word)
{
    TrieNode *cur = root;
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int asciiConversion = (int)word[i] - 'a';

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
        int asciiConversion = (int)word[i] - 'a';

        if (cur->children[asciiConversion] == nullptr)
        {
            return false;
        }
        else
        {
            cur = cur->children[asciiConversion];
        }
    }
    return cur->endOfWord;
}
