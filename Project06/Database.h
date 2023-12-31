// 1. Jimmy Johnson
// 2. 12/9/23
// 3. Project 6 Hash Table

#pragma once

#include <iostream>
#include <vector>
#include "HashTable.h"
#include "Record.h"

using namespace std;

class Database
{
private:
    // Compontents of a Database
    HashTable hashTable;
    vector<Record> recordStore;
    float filledSlots;

public:
    Database();

    bool insert(const Record &newRecord, int &collisions);

    bool remove(int key);

    bool find(int uid, Record &foundRecord, int &collisions);

    float alpha();

    void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Database &s);
};