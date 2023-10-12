#include "Sequence.h"

Sequence::Sequence(size_type sz)
{
    head = nullptr;
    tail = nullptr;
    numElts = 0;
    SequenceNode *oldNode;
    for (int i = 0; i < sz; i++)
    {
        SequenceNode *newNode = new SequenceNode;
        numElts++;

        if (i == 0)
        {
            head = newNode;
            tail = newNode;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            oldNode = newNode;
        }
        else
        {
            tail = newNode;
            newNode->next = nullptr;
            newNode->prev = oldNode;
            oldNode->next = newNode;
            oldNode = newNode;
        }
    }
}

Sequence::Sequence(const Sequence &s)
{
}

Sequence::~Sequence()
{
    SequenceNode *cur = head;

    while (cur->next != nullptr)
    {
        SequenceNode *deleteNext = cur->next;
        delete cur;
        cur = deleteNext;
    }
}

Sequence &Sequence::operator=(const Sequence &s)
{
    return *this;
}

Sequence::value_type &Sequence::operator[](size_type position)
{
    if (position < 0 || position > numElts - 1)
    {
        throw exception();
    }

    else
    {
        SequenceNode *cur = head;

        for (int i = 0; i < position; i++)
        {
            cur = cur->next;
        }
        return (cur->elt);
    }
}

void Sequence::push_back(const value_type &value)
{
    SequenceNode *cur = head;

    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    SequenceNode *newNode = new SequenceNode;
    numElts++;
    cur->next = newNode;
    newNode->elt = value;
    newNode->prev = cur;
    tail = newNode;
}

void Sequence::pop_back()
{
    if (numElts > 0)
    {
        SequenceNode *deleteMe = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete deleteMe;
        numElts--;
    }
    else
    {
        throw exception();
    }
}

void Sequence::insert(size_type position, value_type value)
{
    if (position < 0 || position > numElts - 1)
    {
        throw exception();
    }
    else
    {
        SequenceNode *cur = head;
        SequenceNode *insertMe = new SequenceNode;
        insertMe->elt = value;
        numElts++;
        for (int i = 0; i < position; i++)
        {
            cur = cur->next;
        }
        if (cur->prev == nullptr)
        {   // inserting at head, inserted is new head
            head = insertMe;
            head->next = cur;
            cur->prev = insertMe;
        }
        else
        {
            insertMe->prev = cur->prev;
            cur->prev->next = insertMe;
            insertMe->next = cur;
            cur->prev = insertMe;
        }
    }
}

const Sequence::value_type &Sequence::front() const
{
    throw exception();
}

const Sequence::value_type &Sequence::back() const
{
    throw exception();
}

bool Sequence::empty() const
{
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

// Place code for printing sequence here (well not here, inside the method)
void Sequence::print(ostream &os) const
{
    if (head == nullptr)
    {
        os << "null" << endl;
    }
    else
    {
        os << "Number of elts: " << numElts << endl;
        SequenceNode *cur;
        cur = head;
        while (cur->next != nullptr)
        {
            os << cur->elt << " ";
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
