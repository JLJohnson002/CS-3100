#pragma once

#include <iostream>
#include <exception>
#include <vector>

using namespace std;

class AVLTree
{
public:
    class TreeNode
    {
    public:
        int key;
        string value;
        int height;

        TreeNode *right; // pointer to right Node.
        TreeNode *left;  // pointer to left Node.

        TreeNode(int newKey, string newValue)
        {
            key = newKey;
            value = newValue;
            height = 0;
            right = nullptr;
            left = nullptr;
        }
    };
    // CONSTRUCTORS:

    // Creates an empty AVL tree
    AVLTree();

    // Copies a given tree
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

    bool insert(int key, string value, TreeNode *&node);// helper

    // return the height of the AVL tree. The time complexity for getHeight should be O(1).
    int getHeight();

    int getHeight(TreeNode *);// helper

    void leftRotate(TreeNode *problem);

    void rightRotate(TreeNode *problem);

    void doubleLeftRotate(TreeNode *problem);

    void doubleRightRotate(TreeNode *problem);

    int max(int left, int right);

    int balance(TreeNode *);

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

    /// @brief printing method for entire AVLTree, outputs all elements
    /// @param os the ostream to print to (ex: cout)
    void print(ostream &os) const;

private:
    /// @brief private inner class for linked list nodes
    /// All data elements are public, since only class sequence can see SequenceNodes

    // MEMBER DATA.  These are the data items that each sequence object will contain.  For a
    // doubly-linked list, each sequence will have a head and tail pointer, and numElts
    TreeNode *root;
    int numElts; // Number of elements in the sequence

}; // End of class AVLTree
