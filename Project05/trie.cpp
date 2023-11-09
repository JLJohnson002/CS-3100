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
    // root = s.root;
    numWords = s.numWords;
    numNodes = s.numNodes;
    copy(s.root, this->root);
}

// Copy Helper
void Trie::copy(const TrieNode *const &from, TrieNode *&to)
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
void Trie::kill(TrieNode *cur)
{
    for (int i = 0; i < 26; i++)
    {
        if (cur->children[i] != nullptr)
        {
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

// this function should return the number of words in the dictionary that begin with
// the given input string. If no matching words are found, the function should return zero.
int Trie::completeCount(string word)
{
    TrieNode *cur = root;
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int asciiConversion = (int)word[i] - 'a';

        if (cur->children[asciiConversion] == nullptr)
        {
            return 0;
        }
        else
        {
            cur = cur->children[asciiConversion];
        }
    }

    return countHelper(cur);
}

int Trie::countHelper(TrieNode *cur)
{
    int count = 0;

    if (cur->endOfWord)
    {
        count++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cur->children[i] != nullptr)
        {
            count += countHelper(cur->children[i]);
        }
    }

    return count;
}

// this function should return a C++ vector of strings
// containing all of the words in the dictionary
// that begin with the given input string.
// For each word found in the trie, there will be one value in the vector.
// If no matching words are found, the function should return an empty vector.
// Example: The call resultVector = myTrie.complete("addr")
// were called on a trie built with the wordlist.txt
// file provided with this project should return a vector containing the strings:
// {"address", "addressable", "addressed", "addressee",
// "addressees", "addresses", "addressing"}.
vector<string> Trie::complete(string word)
{
    TrieNode *cur = root;
    vector<string> list;
    for (unsigned int i = 0; i < word.length(); i++)
    {
        int asciiConversion = (int)word[i] - 'a';

        if (cur->children[asciiConversion] == nullptr)
        {
            return list;
        }
        else
        {
            cur = cur->children[asciiConversion];
        }
    }

    return completeHelper(cur, word);
}
vector<string> Trie::completeHelper(TrieNode *cur, string word)
{
    vector<string> list;

    if (cur->endOfWord)
    {
        list.push_back(word);
    }
    for (int i = 0; i < 26; i++)
    {
        if (cur->children[i] != nullptr)
        {
            word += (char)(cur->children[i] + 'a');
    vector<string> temp = completeHelper(cur->children[i], word);

            list;
        }
    }

    return list;
}

// trie1 = trie2 should remove all contents of trie1 (without memory leaks)
// and make an independent copy of trie2 in trie1.
Trie &Trie::operator=(const Trie &trie2)
{
    kill(root);
    numWords = trie2.numWords;
    numNodes = trie2.numNodes;
    this->copy(trie2.root, this->root);
    return *this;
}