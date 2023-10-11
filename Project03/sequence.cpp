#include "Sequence.h"

Sequence::Sequence(size_type sz)
{
    head = nullptr;
    tail = nullptr;
    numElts = 0;
    for (int i = 0; i < sz; i++)
    {
        SequenceNode *pointNode = new SequenceNode;
        SequenceNode newNode = SequenceNode();
        numElts++;

        if (i == 0)
        {
            head = pointNode;
            newNode.elt = i;
            newNode.prev = nullptr;
        }
        if (i > 0)
        {
            newNode.next = nullptr;
            newNode.prev = sequence[i-1];
        }
        if (i == sz - 1)
        {
            tail = pointNode;
            newNode.elt = i;
            newNode.next = nullptr;
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
    throw exception();
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

// Place code for printing sequence here
void Sequence::print(ostream &os) const
{
    os << "printing" << endl;
}

// Don't modify, do the output in the print() method
ostream &operator<<(ostream &os, const Sequence &s)
{
    s.print(os);
    return os;
}
