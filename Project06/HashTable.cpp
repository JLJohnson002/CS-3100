// 1. Jimmy Johnson
// 2. 12/08/23
// 3. Project 6 Hash Table Database

#include "HashTable.h"
#include "hashfunction.h"
#include "shuffle.h"

HashTable::HashTable()
{
    filledSlots = 0;
    probeOrder = makeShuffledArray();
}

bool HashTable::insert(int key, int index, int &collisions)
{

    if (!find(key, index, collisions))
    {
        collisions = 0;
        unsigned int hash = jsHash(key) % MAXHASH;

        if (hashTable[hash].isEmpty())
        {
            hashTable[hash].load(key, index);
            filledSlots++;
            return true;
        }
        else
        {
            for (size_t i = 0; i < MAXHASH; i++)
            {
                collisions++;
                if (hashTable[hash + probeOrder[i]].isEmpty())
                {
                    hashTable[hash + probeOrder[i]].load(key, index);
                    filledSlots++;
                    return true;
                }
            }
            return false;
        }
    }
    else
    {
        cout << "no insert" << endl;
        return false;
    }
}

bool HashTable::remove(int key)
{
    unsigned int hash = jsHash(key) % MAXHASH;

    if (hashTable[hash].getKey() == key)
    {
        hashTable[hash].load(-1, -1);
        hashTable[hash].kill();
        filledSlots--;
        return true;
    }
    else
    {
        for (size_t i = 0; i < MAXHASH; i++)
        {
            if (hashTable[hash + probeOrder[i]].getKey() == key)
            {
                hashTable[hash].load(-1, -1);
                hashTable[hash].kill();
                filledSlots--;
                return true;
            }
            if (hashTable[hash + probeOrder[i]].isEmptySinceStart())
            {
                return false;
            }
        }
        return false;
    }
}

bool HashTable::find(int key, int &index, int &collisions)
{
    unsigned int hash = jsHash(key) % MAXHASH;
    collisions = 0;

    if (hashTable[hash].getKey() == key)
    {
        index = hashTable[hash].getIndex();
        return true;
    }
    else
    {
        for (size_t i = 0; i < MAXHASH; i++)
        {
            collisions++;
            if (hashTable[hash + probeOrder[i]].getKey() == key)
            {
                index = hashTable[hash = probeOrder[i]].getIndex();
                return true;
            }
            if (hashTable[hash + probeOrder[i]].isEmptySinceStart())
            {
                return false;
            }
        }
        return false;
    }
}

float HashTable::alpha()
{
    return filledSlots / MAXHASH;
}

Slot HashTable::getSlot(int key) const
{
    return hashTable[jsHash(key) % MAXHASH];
}

void HashTable::print(ostream &os) const
{
    os << "HashTable Contents:" << endl;
    for (int i = 0; i < MAXHASH; i++)
    {
        if (hashTable[i].isNormal())
        {
            os << "HashTable Slot " << i << ": Key = " << hashTable[i].getKey()
               << ", Index = " << hashTable[i].getIndex() << endl;
        }
    }
}

ostream &operator<<(ostream &os, const HashTable &s)
{
    s.print(os);
    return os;
}