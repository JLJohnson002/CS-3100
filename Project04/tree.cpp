#include "tree.h"
#include <vector>


AVLTree::AVLTree(size_type sz)
// Constructor of size 'sz'
{
    // Create an empty sequence
    head = nullptr;
    tail = nullptr;
    numElts = 0;

    // Create old node pointer
    TreeNode *oldNode;

    for (int i = 0; i < sz; i++)
    { // Creates one new node for the whole size of sz
        TreeNode *newNode = new TreeNode;
        numElts++;

        if (i == 0)
        { // First node
            head = newNode;
            tail = newNode;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            oldNode = newNode;
        }
        else
        { // NOT first node
            tail = newNode;
            newNode->next = nullptr;
            newNode->prev = oldNode;
            oldNode->next = newNode;
            oldNode = newNode;
        }
    }
}

AVLTree::AVLTree(const AVLTree &s)
// Copies a given Tree
{
    // Creates an empty Tree
    head = nullptr;
    tail = nullptr;
    numElts = 0;

    // Node pointer of the start of the given Tree
    TreeNode *copyNode = s.head;

    for (int i = 0; i < s.size(); i++)
    {
        TreeNode *newNode = new TreeNode;
        numElts++;

        if (i == 0)
        { // First node
            newNode->elt = copyNode->elt;
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
        }
        else
        { // NOT first node
            newNode->elt = copyNode->elt;
            tail = newNode;
            newNode->prev = copyNode->prev;
            newNode->next = nullptr;
        }
        copyNode = copyNode->next;
    }
}

AVLTree::~AVLTree()
{ // Destructor

    // Start the the head
    TreeNode *cur = head;

    if (numElts == 0)
    {
        delete cur;
    }
    else
    {
        while (cur->next != nullptr)
        { // Delete and move on until null
            TreeNode *deleteNext = cur->next;
            delete cur;
            cur = deleteNext;
        }
    }
}

AVLTree &AVLTree::operator=(const AVLTree &s)
{
    return *this;
}

AVLTree::value_type &AVLTree::operator[](size_type position)
{ // Sequence manipulation operator

    if (position < 0 || position > numElts - 1)
    { // Out of bounds position
        throw exception();
    }

    else
    { // Acceptable position

        // Start at head
        TreeNode *cur = head;

        // Find the position
        for (int i = 0; i < position; i++)
        {
            cur = cur->next;
        }
        // Return element at that position
        return (cur->elt);
    }
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
}

int AVLTree::getSize()
// return the total number of nodes (key/value pairs) in the AVL tree.
// The time complexity for getSize should be O(1).
{
}

friend ostream &operator<<(ostream &os, const AVLTree &me)
// print the tree using the << operator.
// You should overload the << operator to print the AVL tree “sideways”
// using indentation to show the structure of the tree.
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

void AVLTree::push_back(const value_type &value)
{ // Add to the back of the sequence

    // Create new node to add
    TreeNode *newNode = new TreeNode;
    numElts++;

    if (head == nullptr)
    { // if empty, new is only one
        head = newNode;
        newNode->prev = nullptr;
    }
    else
    { // Add new node as tail
        TreeNode *cur = tail;
        cur->next = newNode;
        newNode->prev = cur;
    }
    newNode->elt = value;
    tail = newNode;
    newNode->next = nullptr;
}

void AVLTree::pop_back()
{ // Remove last

    if (numElts > 0)
    { // if there is something to remove

        TreeNode *deleteMe = tail;
        if (numElts == 1)
        {
            delete deleteMe;
            numElts--;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete deleteMe;
            numElts--;
        }
    }
    else
    { // nothing to delete
        throw exception();
    }
}

void AVLTree::insert(size_type position, value_type value)
{ // Add node at position with value
    if (position < 0 || position > numElts - 1)
    { // Out of bounds position
        throw exception();
    }
    else
    { // In bounds position

        TreeNode *cur = head;
        TreeNode *insertMe = new TreeNode;
        insertMe->elt = value;
        numElts++;

        for (int i = 0; i < position; i++)
        { // Moves cur into position
            cur = cur->next;
        }
        if (cur->prev == nullptr)
        { // inserting at head, inserted is new head
            head = insertMe;
            head->next = cur;
            cur->prev = insertMe;
        }
        else
        { // Not inserting at head, more pointer manip needed
            insertMe->prev = cur->prev;
            cur->prev->next = insertMe;
            insertMe->next = cur;
            cur->prev = insertMe;
        }
    }
}

const AVLTree::value_type &AVLTree::front() const
{ // Returns first element

    if (numElts > 0)
    { // if there is an element to return
        return head->elt;
    }
    else
    { // If there is not an element in the AVLTree
        throw exception();
    }
}

const AVLTree::value_type &AVLTree::back() const
{
    throw exception();
}

bool AVLTree::empty() const
{ // returns true if empty

    if (numElts == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

AVLTree::size_type AVLTree::size() const
{
    return numElts;
}

void AVLTree::clear()
{
}

void AVLTree::erase(size_type position, size_type count)
{
    throw exception();
}

// Place code for printing sequence here
void AVLTree::print(ostream &os) const
{ // Prints all nodes in a sequence
    if (head == nullptr)
    {
        os << "null" << endl;
    }
    else
    {
        TreeNode *cur;
        cur = head;
        while (cur->next != nullptr)
        {
            os << cur->elt << ", ";
            cur = cur->next;
        }
        os << cur->elt << endl;
    }
}

// Don't modify, do the output in the print() method
ostream &operator<<(ostream &os, const AVLTree &s)
{
    s.print(os);
    return os;
}
