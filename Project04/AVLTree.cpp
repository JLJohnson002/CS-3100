#include "AVLTree.h"
#include <vector>

AVLTree::AVLTree()
// Empty constructor
{
    // Create an empty AVLTree
    root = nullptr;
    numElts = 0;
}

AVLTree::AVLTree(const AVLTree &s)
// Copies a given Tree
{
    AVLTree newTree;

    // copy root then left then right
    newTree.insert(s.root->key, s.root->value);
}

// Destructor
AVLTree::~AVLTree()
//   delete left then right then self
{
}

// Insert a new key/value pair into the tree.
// For this assignment the duplicate keys are not allowed.
// This function should return true if the key/value pair is successfully inserted into the map,
//  and false if the pair could not be inserted
//(for example, due to a duplicate key already found in the map).
// The time complexity for insert should be O(log2 n).
bool AVLTree::insert(int newKey, string newValue)
{
    return insert(newKey, newValue, root);
}
// Insert helper that receives node
bool AVLTree::insert(int newKey, string newValue, TreeNode *&cur)
{
    bool inserted = false;

    // Insert the new key and value

    if (cur == nullptr)
    {

        cur = new TreeNode(newKey, newValue);
        numElts++;

        inserted = true;
    }
    else if (newKey == cur->key)
    {

        inserted = false;
    }

    else if (newKey < cur->key)
    {

        inserted = insert(newKey, newValue, cur->left);
    }

    else
    {

        inserted = insert(newKey, newValue, cur->right);
    }
    // Update my height

    int leftChildHeight = getHeight(cur->left);

    int rightChildHeight = getHeight(cur->right);

    cur->height = max(leftChildHeight, rightChildHeight) + 1;

    // Find balance
    int bal = balance(cur);

    if (bal < -1) // negative unbalanced
    {
        if (balance(cur->right) < 0) // negative
        {
            leftRotate(cur);
        }
        else
        { // positive
            doubleLeftRotate(cur);
        }
    }
    else if (bal > 1) // positive unbalanced
    {
        if (balance(cur->left) > 0) // positive
        {
            rightRotate(cur);
        }
        else // negative
        {
            doubleRightRotate(cur);
        }
    }

    return inserted;

} /// ****************** END OF INSERT ***************************************************************

void AVLTree::leftRotate(TreeNode *&problem)
{ // Do this if balance is negative
    // Create Temp node pointers
    TreeNode *hook = problem->right;
    TreeNode *hookTemp = hook->left;

    // Move pointers
    hook->left = problem;
    problem->right = hookTemp;

    // Update heights, problem is now lowest so change it first
    int leftChildHeight = getHeight(problem->left);
    int rightChildHeight = getHeight(problem->right);
    problem->height = max(leftChildHeight, rightChildHeight) + 1;

    // Then change hook height
    leftChildHeight = getHeight(hook->left);
    rightChildHeight = getHeight(hook->right);
    hook->height = max(leftChildHeight, rightChildHeight) + 1;

    // Finally change problem pointer back to top of tree section
    problem = hook;
}

void AVLTree::rightRotate(TreeNode *&problem)
{ // Do this if balance is positive
    // Create Temp node pointers
    TreeNode *hook = problem->left;
    TreeNode *hookTemp = hook->right;

    // Move pointers
    hook->right = problem;
    problem->left = hookTemp;

    // Update heights, problem is now lowest so change it first
    int leftChildHeight = getHeight(problem->left);
    int rightChildHeight = getHeight(problem->right);
    problem->height = max(leftChildHeight, rightChildHeight) + 1;

    // Then change hook height
    leftChildHeight = getHeight(hook->left);
    rightChildHeight = getHeight(hook->right);
    hook->height = max(leftChildHeight, rightChildHeight) + 1;

    // Finally change problem pointer back to top of tree section
    problem = hook;
}

void AVLTree::doubleLeftRotate(TreeNode *&problem)
{
    rightRotate(problem->right);
    leftRotate(problem);
}

void AVLTree::doubleRightRotate(TreeNode *&problem)
{
    leftRotate(problem->left);
    rightRotate(problem);
}

// return the height of the AVL tree. The time complexity for getHeight should be O(1).
int AVLTree::getHeight()
{
    return getHeight(root);
}

// getHeight helper
int AVLTree::getHeight(TreeNode *cur)
{
    if (cur == nullptr)
    {
        return -1;
    }
    else
    {
        return cur->height;
    }
}

// Function for getting the balance of a node
int AVLTree::balance(TreeNode *cur)
{
    int left;
    int right;

    if (cur->left == nullptr)
    {
        left = -1;
    }
    else
    {
        left = cur->left->height;
    }

    if (cur->right == nullptr)
    {
        right = -1;
    }
    else
    {
        right = cur->right->height;
    }
    return left - right;
}

// Finds the max of two given numbers
int AVLTree::max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

// return the total number of nodes (key/value pairs) in the AVL tree.
// The time complexity for getSize should be O(1).
int AVLTree::getSize()
{
    return numElts;
}

// if the given key is found in the AVL tree,
// this function should return true and place the corresponding value in value.
// Otherwise this function should return false (and the value in value can be anything).
// The time complexity for find should be O(log2 n).
bool AVLTree::find(int findKey, string &putValue)
{
    return find(findKey, putValue, root);
}

// Find helper
bool AVLTree::find(int findKey, string &putValue, TreeNode *&cur)
{
    if (findKey == cur->key)
    {
        cur->value = putValue;
        return true;
    }
    else if (findKey < cur->key)
    {
        return find(findKey, putValue, cur->left);
    }
    else if (findKey > cur->key)
    {
        return find(findKey, putValue, cur->right);
    }
    else
    {
        return false;
    }
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
// This function should return a C++ vector of strings containing all of the values in the tree
// with keys ≥ lowkey and ≤ highkey. For each key found in the given range,
// there will be one value in the vector. If no matching key/value pairs are found,
// the function should return an empty vector.
{
    lowkey++;
    highkey++;
}

// Place code for printing sequence here
void AVLTree::print(ostream &os) const
{ // Prints all nodes in a sequence
    TreeNode *cur = root;
    if (root == nullptr)
    {
        os << "empty tree";
    }
    else
    { // Print right self left

        if (cur->right == nullptr && cur->left == nullptr)
        {
            int indent = cur->height;
            string indentSpace = "";
            for (int i = 0; i < indent; i++)
            {
                indentSpace += "    ";
            }
            os << indentSpace << cur->key << ", " << cur->value;
        }
        else
        {
            os << cur->right;
            os << cur->left;
        }
    }
}

// Don't modify, do the output in the print() method
ostream &operator<<(ostream &os, const AVLTree &s)
{
    s.print(os);
    return os;
}