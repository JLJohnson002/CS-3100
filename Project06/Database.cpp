// Jimmy Johnson
// 12/08/23
// Project 6 Hash Table

#include "Database.h"
// #include "HashTable.h"

Database::Database()
{
    filledSlots = 0;
}

bool Database::insert(const Record &newRecord, int &collisions)
{
    int index = 0;
    if (!hashTable.find(newRecord.getUID(), index, collisions))
    {
        recordStore.push_back(newRecord);
        index = recordStore.back();
    }
}

bool Database::remove(int key)
{
}

bool Database::find(int uid, Record &foundRecord, int &collisions)
{
}

float Database::alpha()
{
    return filledSlots / MAXHASH;
}

void Database::print(ostream &os) const
{
    /*
    Database contents:
    HashTable Slot : 9, recordStore slot 2 -- Gates, Bill (U00112233): Senior
    HashTable Slot : 4, recordStore slot 0 -- Cook, Tim (U00223344): Sopohomore
    HashTable Slot : 9, recordStore slot 2 -- Zuckerberg, Mark (U00334455): Freshman
    */
}

ostream &operator<<(ostream &os, const Database &s)
{
    s.print(os);
    return os;
}