// 1. Jimmy Johnson
// 2. 12/08/23
// 3. Project 6 Hash Table Database

#include "HashTable.h"
#include "hashfunction.h"
#include "shuffle.h"

HashTable::HashTable()
{
    int collisions = 0;

    for (int i = 0; i < MAXHASH; i++)
    {
        hashTable[i] = Slot(); // FIXME do i need this or does it initalize in the .h
    }
    // int makeShuffledArray()// FIXME; 
    int probeOrder[].makeShuffledArray();
}

bool HashTable::insert(int key, int index, int &collisions)
{
    if (!find(key, index, collisions))
    {
        int hash = jsHash(key);

        if (hashTable[hash].isEmpty())
        {
            hashTable[hash].load(key, index);
            return true;
        }
        else
        {
            for (int i = 0; i < MAXHASH; i++)
            {
                collisions++;
                if (hashTable[hash+probeOrder[i]].isEmpty())
                {
                    hashTable[hash+probeOrder[i]].load(key, index);
                    return true;
                }
            }
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool HashTable::remove(int key)
{
}

bool HashTable::find(int key, int &index, int &collisions)
{
}

float HashTable::alpha()
{
}

void HashTable::print(ostream &os) const
{
    /*
    HashTable contents:
    HashTable Slot 9: Key = 112233, Index = 2
    HashTable Slot 4: Key = 223344, Index = 0
    HashTable Slot 2: Key = 334455, Index = 1
    */
}

ostream &operator<<(ostream &os, const HashTable &s)
{
}