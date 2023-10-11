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
}

void Sequence::pop_back()
{
    throw exception();
}

void Sequence::insert(size_type position, value_type value)
{
    throw exception();
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
    return false;
}

Sequence::size_type Sequence::size() const
{
    return -1;
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
