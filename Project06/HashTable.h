// 1. Jimmy Johnson
// 2. 12/8/23
// 3. Project 6 Hash Table

#pragma once

#include <iostream>
#include <vector>
#include <array>

#include "Slot.h"
#include "Record.h"
#define MAXHASH 20

using namespace std;

class HashTable
{
private:
    // Compontents of a Hash Table
    Slot hashTable[MAXHASH];
    array<unsigned int, MAXHASH - 1> probeOrder;
    float filledSlots;

public:
    // Constructor
    HashTable();

    bool insert(int key, int index, int &collisions);

    bool remove(int key);

    bool find(int key, int &index, int &collisions);

    Slot getSlot(int key) const; // for print of database

    float alpha();

    void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const HashTable &s);
};