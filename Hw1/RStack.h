// RTStack.h: Templated class Stack based on a Run-Time Array

#ifndef RTSTACK
#define RTSTACK

#include <iostream>
#include <cassert>

using namespace std;

template <class ItemType>
class Stack
{
public:
    Stack();                // default constructor
    Stack(int numElements); // constructor initializer
    ~Stack();               // destructor
    bool empty() const;
    void makeEmpty();
    bool full() const;
    void push(const ItemType &value);
    ItemType top();
    void pop();
    void pop(ItemType &item);
    Stack(const Stack<ItemType> &original);                      // user-defined copy constructor
    Stack<ItemType> &operator=(const Stack<ItemType> &original); // user-defined assignment operator
    void print() const;

private:
    ItemType *myArrayPtr; // run-time allocated array
    int myCapacity;       // capacity of stack
    int myTop;            // top of stack
};

// Definitions of templated member functions

template <class ItemType>
Stack<ItemType>::Stack()
{
    myCapacity = 500;               // it could be less than 500 depending on your application
    myTop = -1;                     // created stack is empty
    myArrayPtr = new ItemType[500]; // dynamically allocates array with new operator
}

template <class ItemType>
Stack<ItemType>::Stack(int numElements)
{
    assert(numElements > 0);               // check precondition
    myCapacity = numElements;              // set stack capacity
    myArrayPtr = new ItemType[myCapacity]; // allocate array with capacity numElements
    assert(myArrayPtr != 0);               // check if memory available
    myTop = -1;                            // sets empty stacks
}

template <class ItemType>
Stack<ItemType>::~Stack()
{
    delete[] myArrayPtr;
}

template <class ItemType>
bool Stack<ItemType>::empty() const
{
    return (myTop == -1);
}

template <class ItemType>
void Stack<ItemType>::makeEmpty()
{
    myTop = -1;
}

template <class ItemType>
bool Stack<ItemType>::full() const
{
    return (myTop == myCapacity - 1);
}

template <class ItemType>
void Stack<ItemType>::push(const ItemType &value)
{
    ++myTop;
    myArrayPtr[myTop] = value;
}

template <class ItemType>
ItemType Stack<ItemType>::top()
{
    if (myTop >= 0)
        return myArrayPtr[myTop];
}

template <class ItemType>
void Stack<ItemType>::pop(ItemType &item)
{
    item = myArrayPtr[myTop];
    myTop--;
}

template <class ItemType>
void Stack<ItemType>::pop()
{
    myTop--;
}

template <class ItemType>
void Stack<ItemType>::print() const
{
    for (int i = myTop; i >= 0; i--)
        cout << myArrayPtr[i] << endl;
}

// Definition of user-defined copy constructor
template <class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType> &original)
{
    myCapacity = original.myCapacity;      // copy myCapacity member of original stack
    myTop = original.myTop;                // copy myTop member of original stack
    myArrayPtr = new ItemType[myCapacity]; // allocate array in copy with new operator
    assert(myArrayPtr != 0);               // check if memory available
    for (int pos = 0; pos <= myTop; pos++) // copy stack members of original stack
        myArrayPtr[pos] = original.myArrayPtr[pos];
}

// Definition of user-defined assignment operator
template <class ItemType>
Stack<ItemType> &Stack<ItemType>::operator=(const Stack<ItemType> &original)
{
    if (this != &original)
    {                        // check if current object is the original object
        delete[] myArrayPtr; // destroy previous array
        myArrayPtr = new ItemType[myCapacity];
        assert(myArrayPtr != 0);
        myCapacity = original.myCapacity;
        myTop = original.myTop; // copy in current object myTop, the same member of original object
        // copy stack members of original object into current object
        for (int pos = 0; pos < myCapacity; pos++)
            myArrayPtr[pos] = original.myArrayPtr[pos];
    }
    return *this; // return reference to this object
}

#endif // end file RTStack.h
