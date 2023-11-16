// 1. Jimmy Johnson
// 2. 11/15/2023
// 3. Project 5 Uncompressed Alphabet Trie

#include "trie.h"

/// @brief Constructor
Trie::Trie()
{
    root = new TrieNode();
    numWords = 0;
    numNodes = 1;
}

/// @brief Copy Constructor
/// @param s reference to a trie
Trie::Trie(const Trie &s)
{
    root = new TrieNode();
    numWords = s.numWords;
    numNodes = s.numNodes;
    copy(s.root, this->root);
}

/// @brief Copy Helper
/// @param from reference to constant pointer to constant trie node
/// @param to reference to a pointer to a trie node
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

/// @brief Destructor
Trie::~Trie()
{
    kill(root);
}

/// @brief Destructor Helper
/// @param cur pointer to trie node
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

/// @brief Getter function for the number of words in a trie
/// @return numWords (number of words)
int Trie::count()
{
    return numWords;
}

/// @brief Getter function for the number of nodes in a trie
/// @return numNodes (number of nodes)
int Trie::getSize()
{
    return numNodes;
}

/// @brief Searches a trie for the given word 
/// @param word A given word to look for
/// @return true if found, false otherwise
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

/// @brief Finds the number of words starting with a given string
/// @param word string given by the user
/// @return The number of words that start with the given string
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

/// @brief Recursive helper function for completeCount
/// @param cur pointer to a trie node
/// @return the number of words found after the given string
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

/// @brief Searches a trie for a given string and returns all words with that prefix
/// @param word string provided by user
/// @return vector of strings of all the words starting with the given string
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

/// @brief recursive helper function for complete
/// @param cur pointer to a trie node
/// @param oldWord string
/// @return wordList vector of strings
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

/// @brief Removes all contents of a trie and makes a copy of trie 2 in the first trie
/// @param trie2 reference to a trie
/// @return reference to a trie
Trie &Trie::operator=(const Trie &trie2)
{
    kill(root);
    numWords = trie2.numWords;
    numNodes = trie2.numNodes;
    this->copy(trie2.root, this->root);
    return *this;
}