// 1. Jimmy Johnson
// 2. 11/14/2023
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

/// @brief Inserts a given word into a trie
/// @param word 
/// @return true if inserted, false otherwise
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

// Returns the number of words in a trie
int Trie::count()
{
    return numWords;
}

// Returns the number of nodes in a trie
int Trie::getSize()
{
    return numNodes;
}

/// @brief 
/// @param word 
/// @return 
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

// Returns a vector containing all the strings that begin with the input string
vector<string> Trie::complete(string word)
{
    TrieNode *cur = root;
    while (!wordList.empty())
    {
        wordList.pop_back();
    }

    for (unsigned int i = 0; i < word.length(); i++)
    {
        int asciiConversion = (int)word[i] - 'a';

        if (cur->children[asciiConversion] == nullptr)
        {
            return wordList;
        }
        else
        {
            cur = cur->children[asciiConversion];
        }
    }

    return completeHelper(cur, word);
}
// Recursive helper to complete() function
vector<string> Trie::completeHelper(TrieNode *cur, string oldWord)
{

    if (cur->endOfWord)
    {
        wordList.push_back(oldWord);
    }

    for (int i = 0; i < 26; i++)
    {
        if (cur->children[i] != nullptr)
        {
            string newWord = oldWord + (char)(i + 'a');
            completeHelper(cur->children[i], newWord);
        }
    }

    return wordList;
}

// Removes all contents of trie1 and makes an independent copy of trie 2 in trie1
Trie &Trie::operator=(const Trie &trie2)
{
    kill(root);
    numWords = trie2.numWords;
    numNodes = trie2.numNodes;
    this->copy(trie2.root, this->root);
    return *this;
}