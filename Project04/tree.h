#pragma once

#include <iostream>
#include <exception>
#include <vector>

using namespace std;

class AVLTree
{
public:
    //{
    // ASKME Only here for the unknown value of linked list. not needed for given int and string of AVLTree

    /// @brief Sequence::value_type is the data type of values in the sequence.
    /// Any primative C++ data type(int, double, bool, char, etc.), or a class
    /// with a default constructor, a destructor, an assignment operator, and a
    /// copy constructor can be used.
    typedef int value_type;

    /// @brief Sequence::size_type is the data type of any variable the number of
    /// items in a sequence.
    typedef unsigned int size_type;
    //}


    // CONSTRUCTORS for the sequence class:

    /// @brief Creates an empty AVL tree.
    AVLTree();

    /// @brief Creates a (deep) copy of sequence seq.
    /// @param s Sequence to be copied
    AVLTree(const AVLTree &s);

    /// @brief Destroys all items in the sequence and release the memory associated
    /// with the sequence
    ~AVLTree();

    ///*******************************************************************************************
    // Insert a new key/value pair into the tree.
    // For this assignment the duplicate keys are not allowed.
    // This function should return true if the key/value pair is successfully inserted into the map,
    // and false if the pair could not be inserted
    // (for example, due to a duplicate key already found in the map).
    // The time complexity for insert should be O(log2 n).
    bool insert(int key, string value);

    // return the height of the AVL tree. The time complexity for getHeight should be O(1).
    int getHeight();

    // return the total number of nodes (key/value pairs) in the AVL tree.
    // The time complexity for getSize should be O(1).
    int getSize();

    // if the given key is found in the AVL tree,
    // this function should return true and place the corresponding value in value.
    // Otherwise this function should return false (and the value in value can be anything).
    // The time complexity for find should be O(log2 n).
    bool find(int key, string &value);

    // This function should return a C++ vector of strings containing all of the values in the tree
    // with keys ≥ lowkey and ≤ highkey. For each key found in the given range,
    // there will be one value in the vector. If no matching key/value pairs are found,
    // the function should return an empty vector.
    vector<string> findRange(int lowkey, int highkey);

    /// @brief operator<< overload, this simply calls the print method
    ///	NOTE: you should not need to modify this, all the printing should be done in print()
    /// @param os ostream reference to output sequence
    /// @param s sequence to be output
    /// @return reference to the ostream passed in
    friend ostream &operator<<(ostream &os, const AVLTree &s);
    //*******************************************************************************************

    /// @brief printing method for entire sequence, outputs all elements
    /// 		ex: <4, 8, 15, 16, 23, 42>
    /// @param os the ostream to print to (ex: cout)
    void print(ostream &os) const;


    // YOU CAN MODIFY the following private declarations as needed to implement your sequence class
private:
    /// @brief private inner class for linked list nodes
    /// All data elements are public, since only class sequence can see SequenceNodes
    class TreeNode
    {
    public:
        //ASKME These are not pointers but require a * to initilize. 
        AVLTree::TreeNode *key;
        AVLTree::TreeNode *value;
        AVLTree::TreeNode *height;

        TreeNode *right; // pointer to next Node. 
        TreeNode *left; // pointer to previous Node. 

        /// @brief empty constructor, ensure next and prev are nullptr
        //ASKME What does the : mean for constructor?
        TreeNode() : right(nullptr), left(nullptr)
        {
            key = nullptr;
            value = nullptr;
            height = nullptr;
            // Not needed after the : above?
            // right = nullptr;
            // left = nullptr;
        }

        /// @brief parameterized constructor, next and prev are set to nullptr and the
        /// node's element is set to the given value
        /// @param item value the node's element will be set to
        TreeNode(int newKey, string newValue) : right(nullptr), left(nullptr), key(this->key), value (this->value)
        {
        }

        /// @brief node destructor. Think about what it would mean and whether anything
        /// should be done here
        ~TreeNode(){};
    };

    // MEMBER DATA.  These are the data items that each sequence object will contain.  For a
    // doubly-linked list, each sequence will have a head and tail pointer, and numElts
    TreeNode *root;
    size_type numElts; // Number of elements in the sequence

}; // End of class AVLTree