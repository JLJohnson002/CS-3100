// 1. Jimmy Johnson
// 2. 12/8/23
// 3. Project 6 Hash Table

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
private:
    // Compontents of a Hash Table
    

public:
    // Constructor
    HashTable();

    bool insert(int key, int index, int &collisions);

    bool remove(int key);

    bool find(int key, int &index, int &collisions);

    float alpha();
    // Alpha = n/N

    void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const HashTable &s);
};