#include "Sequence.h"

Sequence::Sequence(size_type sz)
// Constructor of size 'sz'
{
    // Create an empty sequence
    head = nullptr;
    tail = nullptr;
    numElts = 0;

    // Create old node pointer
    SequenceNode *oldNode;

    for (int i = 0; i < sz; i++)
    { // Creates one new node for the whole size of sz
        SequenceNode *newNode = new SequenceNode;
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

Sequence::Sequence(const Sequence &s)
// Copies a given sequence
{
    // Creates an empty sequence
    head = nullptr;
    tail = nullptr;
    numElts = 0;

    // Node pointer of the start of the given sequence
    SequenceNode *copyNode = s.head;

    for (int i = 0; i < s.size(); i++)
    {
        SequenceNode *newNode = new SequenceNode;
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

Sequence::~Sequence()
{ // Destructor

    // Start the the head
    SequenceNode *cur = head;

    if (numElts == 0)
    {
        delete cur;
    }
    else
    {
        while (cur->next != nullptr)
        { // Delete and move on until null
            SequenceNode *deleteNext = cur->next;
            delete cur;
            cur = deleteNext;
        }
    }
}

Sequence &Sequence::operator=(const Sequence &s)
{
    return *this;
}

Sequence::value_type &Sequence::operator[](size_type position)
{ // Sequence manipulation operator

    if (position < 0 || position > numElts - 1)
    { // Out of bounds position
        throw exception();
    }

    else
    { // Acceptable position

        // Start at head
        SequenceNode *cur = head;

        // Find the position
        for (int i = 0; i < position; i++)
        {
            cur = cur->next;
        }
        // Return element at that position
        return (cur->elt);
    }
}

void Sequence::push_back(const value_type &value)
{ // Add to the back of the sequence

    // Create new node to add
    SequenceNode *newNode = new SequenceNode;
    numElts++;

    if (head == nullptr)
    {// if empty, new is only one
        head = newNode;
        newNode->prev = nullptr;
    }
    else
    {// Add new node as tail
        SequenceNode *cur = tail;
        cur->next = newNode;
        newNode->prev = cur;
    }
    newNode->elt = value;
    tail = newNode;
    newNode->next = nullptr;
}

void Sequence::pop_back()
{// Remove last

    if (numElts > 0)
    {// if there is something to remove

        SequenceNode *deleteMe = tail;
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
    {// nothing to delete
        throw exception();
    }
}

void Sequence::insert(size_type position, value_type value)
{// Add node at position with value
    if (position < 0 || position > numElts - 1)
    {// Out of bounds position
        throw exception();
    }
    else
    {// In bounds position

        SequenceNode *cur = head;
        SequenceNode *insertMe = new SequenceNode;
        insertMe->elt = value;
        numElts++;

        for (int i = 0; i < position; i++)
        {// Moves cur into position
            cur = cur->next;
        }
        if (cur->prev == nullptr)
        { // inserting at head, inserted is new head
            head = insertMe;
            head->next = cur;
            cur->prev = insertMe;
        }
        else
        {// Not inserting at head, more pointer manip needed
            insertMe->prev = cur->prev;
            cur->prev->next = insertMe;
            insertMe->next = cur;
            cur->prev = insertMe;
        }
    }
}

const Sequence::value_type &Sequence::front() const
{// Returns first element

    if (numElts > 0)
    {// if there is an element to return
        return head->elt;
    }
    else
    {// If there is not an element in the sequence
        throw exception();
    }
}

const Sequence::value_type &Sequence::back() const
{
    throw exception();
}

bool Sequence::empty() const
{// returns true if empty

    if (numElts == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Sequence::size_type Sequence::size() const
{
    return numElts;
}

void Sequence::clear()
{
}

void Sequence::erase(size_type position, size_type count)
{
    throw exception();
}

// Place code for printing sequence here
void Sequence::print(ostream &os) const
{// Prints all nodes in a sequence
    if (head == nullptr)
    {
        os << "null" << endl;
    }
    else
    {
        SequenceNode *cur;
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
ostream &operator<<(ostream &os, const Sequence &s)
{
    s.print(os);
    return os;
}
