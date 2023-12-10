// 1. Jimmy Johnson
// 2. 12/9/23
// 3. Project 6 Hash Table

#include "Database.h"
#include "hashfunction.h"
#include "Slot.h"
#include "HashTable.h"

/// @brief Default constructor
Database::Database()
{
    filledSlots = 0;
}

/// @brief Adds a new record to the database
/// @param newRecord
/// @param collisions
/// @return True if inserted
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
    else
    {
        return false;
    }
}

/// @brief Removes all data from the database in association with the key
/// @param key
/// @return True if removed
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

/// @brief Searches the database for the UID and updates the foundRecord and collisions variables
/// @param uid
/// @param foundRecord
/// @param collisions
/// @return True if found
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

/// @brief Calculation function
/// @return The loading factor of n/N
float Database::alpha()
{
    return filledSlots / MAXHASH;
}

/// @brief Prints the database contents to the terminal
/// @param os
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