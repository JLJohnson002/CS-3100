#pragma once
// FILE: sequence.h
// CLASS PROVIDED: Sequence

#include <iostream>
#include <exception>
#include <vector>

using namespace std;

class AVLTree
{ // The following declarations describe the functions that you must implement.
  // You SHOULD NOT CHANGE any of the following PUBLIC declarations.
public:
    /// @brief Sequence::value_type is the data type of values in the sequence.
    /// Any primative C++ data type(int, double, bool, char, etc.), or a class
    /// with a default constructor, a destructor, an assignment operator, and a
    /// copy constructor can be used.
    typedef int value_type;

    /// @brief Sequence::size_type is the data type of any variable the number of
    /// items in a sequence.
    typedef unsigned int size_type;

    // CONSTRUCTORS for the sequence class:

    /// @brief Creates an empty sequence (numElts == 0) or
    ///	a sequence of numElts items indexed from 0 ... (numElts - 1).
    /// @param sz number of elements to create the sequence with
    AVLTree(size_type sz = 0);

    /// @brief Creates a (deep) copy of sequence seq.
    /// @param s Sequence to be copied
    AVLTree(const AVLTree &s);

    /// @brief Destroys all items in the sequence and release the memory associated
    /// with the sequence
    ~AVLTree();

    /// @brief The current sequence is released and replaced by a (deep) copy of
    /// sequence (seq). A reference to the copied sequence is returned.
    /// @param s the sequence to be copied
    /// @return *this with elements from s copied into
    AVLTree &operator=(const AVLTree &s);

    /// @brief The position satisfies ( position >= 0 && position <= last_index( ) ).
    /// The return value is a reference to the item at index position in the sequence.
    /// throws an exception	if the position is outside the bounds of the sequence
    /// @param p position of item being accessed
    /// @return reference to the item at index position in the sequence
    value_type &operator[](size_type p);

    ///*******************************************************************************************
    // Insert a new key/value pair into the tree.
    // For this assignment the duplicate keys are not allowed.
    // This function should return true if the key/value pair is successfully inserted into the map,
    // and false if the pair could not be inserted
    // (for example, due to a duplicate key already found in the map).
    // The time complexity for insert should be O(log2 n).
    bool AVLTree::insert(int key, string value);

    // return the height of the AVL tree. The time complexity for getHeight should be O(1).
    int AVLTree::getHeight();

    // return the total number of nodes (key/value pairs) in the AVL tree.
    // The time complexity for getSize should be O(1).
    int AVLTree::getSize();

    // print the tree using the << operator.
    // You should overload the << operator to print the AVL tree “sideways”
    // using indentation to show the structure of the tree.
    friend ostream &operator<<(ostream &os, const AVLTree &me);

    // if the given key is found in the AVL tree,
    // this function should return true and place the corresponding value in value.
    // Otherwise this function should return false (and the value in value can be anything).
    // The time complexity for find should be O(log2 n).
    bool AVLTree::find(int key, string &value);

    // This function should return a C++ vector of strings containing all of the values in the tree
    // with keys ≥ lowkey and ≤ highkey. For each key found in the given range,
    // there will be one value in the vector. If no matching key/value pairs are found,
    // the function should return an empty vector.
    vector<string> AVLTree::findRange(int lowkey, int highkey);

    //*******************************************************************************************
    /// @brief The value of item is append to the sequence.
    /// @param v item to be added
    void push_back(const value_type &v);

    /// @brief The size of the sequence is greater than zero. Postcondition: The item
    /// at the end of the sequence is deleted and size of the sequence is reduced by one.
    void pop_back();

    /// @brief The position satisfies ( position >= 0 && position <= last_index( ) ).
    // The value of item is inserted at position and the size of sequence is increased
    // by one.
    /// throws an exception	if the position is outside the bounds of the sequence
    /// @param p position where to inset value in the sequence
    /// @param v the value being inserted
    void insert(size_type p, value_type v);

    /// @brief The size of the sequence is greater than zero
    /// throws an exception	if the sequence is empty
    /// @return a reference to the first item in the sequence.
    const value_type &front() const;

    /// @brief The size of the sequence is greater than zero.
    /// throws an exception	if the sequence is empty
    /// @return a reference to the last item in the sequence.
    const value_type &back() const;

    /// @brief A true return value indicates size of the sequence is zero.
    /// @return true if sequence is empty, false if sequence has size > 0
    bool empty() const;

    /// @brief The return value is the number of items in the sequence.
    /// @return number of items in the sequence
    size_type size() const;

    /// @brief All items in the sequence deleted and the memory associated with
    /// the sequence is released.
    void clear();

    /// @brief The position satisfies
    /// 	( position >= 0 && position + count - 1 <= last_index( ) )
    /// throws an exception	if the sequence when called with invalid position and/or count
    /// The positions / items in the sequence at
    /// 	( position ... (position + count - 1) )
    /// are deleted and their memory is released
    /// @param p position of first item to be erased
    /// @param n number of items to be erased
    void erase(size_type p, size_type n = 1);

    /// @brief printing method for entire sequence, outputs all elements
    /// 		ex: <4, 8, 15, 16, 23, 42>
    /// @param os the ostream to print to (ex: cout)
    void print(ostream &os) const;

    /// @brief operator<< overload, this simply calls the print method
    ///			NOTE: you should not need to modify this, all the printing should be done in print()
    /// @param os ostream reference to output sequence
    /// @param s sequence to be output
    /// @return reference to the ostream passed in
    friend ostream &operator<<(ostream &os, const AVLTree &s);

    // YOU CAN MODIFY the following private declarations as needed to implement your sequence class
private:
    /// @brief private inner class for linked list nodes
    /// All data elements are public, since only class sequence can see SequenceNodes
    class TreeNode
    {
    public:
        TreeNode *next; // pointer to next Node. If node is the tail, next is nullptr
        TreeNode *prev; // pointer to previous Node. If node is the head, prev is nullptr
        value_type elt; // the element being stored in the node

        /// @brief empty constructor, ensure next and prev are nullptr
        TreeNode() : next(nullptr), prev(nullptr)
        {
        }

        /// @brief parameterized constructor, next and prev are set to nullptr and the
        /// node's element is set to the given value
        /// @param item value the node's element will be set to
        TreeNode(value_type item) : next(nullptr), prev(nullptr), elt(item)
        {
        }

        /// @brief node destructor. Think about what it would mean and whether anything
        /// should be done here
        ~TreeNode(){};
    };

    // MEMBER DATA.  These are the data items that each sequence object will contain.  For a
    // doubly-linked list, each sequence will have a head and tail pointer, and numElts
    TreeNode *head;
    TreeNode *tail;
    size_type numElts; // Number of elements in the sequence

}; // End of class Sequence
