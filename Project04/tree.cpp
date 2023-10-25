#include "tree.h"
#include <vector>

AVLTree::AVLTree()
// Constructor of size 'sz'
{
    // Create an empty AVLTree
    root = nullptr;
    numElts = 0;
}

AVLTree::AVLTree(const AVLTree &s)
// Copies a given Tree
{
    // copy root then left then right
}

AVLTree::~AVLTree()
{ // Destructor
  //   delete left then right then self
}

bool AVLTree::insert(int key, string value) {}
// Insert a new key/value pair into the tree.
// For this assignment the duplicate keys are not allowed.
// This function should return true if the key/value pair is successfully inserted into the map,
//  and false if the pair could not be inserted
//(for example, due to a duplicate key already found in the map).
// The time complexity for insert should be O(log2 n).

int AVLTree::getHeight()
// return the height of the AVL tree. The time complexity for getHeight should be O(1).
{
    return root->height;
}

int AVLTree::getSize()
// return the total number of nodes (key/value pairs) in the AVL tree.
// The time complexity for getSize should be O(1).
{
}

bool AVLTree::find(int key, string &value)
// if the given key is found in the AVL tree,
// this function should return true and place the corresponding value in value.
// Otherwise this function should return false (and the value in value can be anything).
// The time complexity for find should be O(log2 n).
{
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
// This function should return a C++ vector of strings containing all of the values in the tree
// with keys ≥ lowkey and ≤ highkey. For each key found in the given range,
// there will be one value in the vector. If no matching key/value pairs are found,
// the function should return an empty vector.
{
}

// Place code for printing sequence here
void AVLTree::print(ostream &os) const
{ // Prints all nodes in a sequence
    if (root == nullptr)
    {
        os << "null" << endl;
    }
    else
    {
        TreeNode *cur;
        cur = root;
        if (cur->left == nullptr){
            os << cur->key << endl;
        }

        // print(cur);
        // print(cur->right);
        // os << cur->elt << ", ";
        // cur = cur->next;
    }
    // os << cur->elt << endl;
}

// Don't modify, do the output in the print() method
ostream &operator<<(ostream &os, const AVLTree &s)
{
    s.print(os);
    return os;
}