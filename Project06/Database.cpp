// Jimmy Johnson
// 12/08/23
// Project 6 Hash Table

#include "Database.h"
#include "hashfunction.h"
#include "Slot.h"
#include "HashTable.h"
// #include "HashTable.h"

Database::Database()
{
    filledSlots = 0;
}

bool Database::insert(const Record &newRecord, int &collisions)
{
    int index = 0;

    if (filledSlots <= MAXHASH)
    {
        if (!hashTable.find(newRecord.getUID(), index, collisions))
        {
            recordStore.push_back(newRecord);
            index = recordStore.size() - 1;
            hashTable.insert(newRecord.getUID(), index, collisions);
            filledSlots++;
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Database::remove(int key)
{
    int index = 0;
    int collisions;
    int updateUID;

    if (hashTable.find(key, index, collisions))
    {
        recordStore[index].load(recordStore[recordStore.size() - 1].getFirstName(),
                                recordStore[recordStore.size() - 1].getLastName(),
                                recordStore[recordStore.size() - 1].getUID(),
                                recordStore[recordStore.size() - 1].getYear());
        updateUID = recordStore[index].getUID();
        recordStore.pop_back();

        hashTable.remove(key);

        hashTable.remove(updateUID);
        hashTable.insert(updateUID, index, collisions);
        filledSlots--;

        return true;
    }
    else
    {
        return false;
    }
}

bool Database::find(int uid, Record &foundRecord, int &collisions)
{
    int index = 0;
    collisions = 0;

    if (hashTable.find(uid, index, collisions))
    {
        foundRecord = recordStore[index];
        return true;
    }
    else
    {
        return false;
    }
}

float Database::alpha()
{
    return filledSlots / MAXHASH;
}

void Database::print(ostream &os) const
{
    os << "Database Contents:" << endl;

    for (int i = 0; i < MAXHASH; i++)
    {
        Slot temp = hashTable.getSlot(recordStore[i].getUID());
        if (temp.isNormal())
        {
            os << "HashTable Slot : " << i
               << ", recordStore slot " << i
               << " -- " 
               << recordStore[i].getLastName() << ", "
               << recordStore[i].getFirstName() << " (U"
               << recordStore[i].getUID() << "): "
               << recordStore[i].getYear() << endl;
        }
    }
}

ostream &operator<<(ostream &os, const Database &s)
{
    s.print(os);
    return os;
}