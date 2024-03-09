#ifndef DSTACK_H
#define DSTACK_H
//
#include <iostream>
using namespace std;
//
template <class ItemType>
class DStack
{
public:
    DStack(int numElements = 128);
    ~DStack();
    DStack(const DStack<ItemType> &original);
    DStack<ItemType> &operator=(const DStack<ItemType> &original);
    void makeEmpty();
    bool full() const;
    bool empty() const;
    void push(const ItemType &value);
    ItemType top();
    void pop();
    void pop(ItemType &item);
    // Prototype of new member function reverse
    void reverse(DStack<ItemType> &otherStack);
    void print() const;

private:
    int myTop;
    int myCapacity;
    ItemType *myArrayPtr;
};

template <class ItemType>
DStack<ItemType>::DStack(int numElements)
{
    myCapacity = numElements;
    myArrayPtr = new ItemType[myCapacity];
    myTop = -1;
}

template <class ItemType>
DStack<ItemType>::~DStack()
{
    delete[] myArrayPtr;
}

template <class ItemType>
DStack<ItemType>::DStack(const DStack<ItemType> &original)
{
    myCapacity = original.myCapacity;
    myArrayPtr = new ItemType[myCapacity];
    myTop = original.myTop;
    for (int i = 0; i <= myTop; ++i)
        myArrayPtr[i] = original.myArrayPtr[i];
}

template <class ItemType>
DStack<ItemType> &DStack<ItemType>::operator=(const DStack<ItemType> &original)
{
    if (this != &original)
    {
        delete[] myArrayPtr;
        myCapacity = original.myCapacity;
        myArrayPtr = new ItemType[myCapacity];
        myTop = original.myTop;
        for (int i = 0; i <= myTop; ++i)
            myArrayPtr[i] = original.myArrayPtr[i];
    }
    return *this;
}

template <class ItemType>
void DStack<ItemType>::makeEmpty()
{
    myTop = -1;
}

template <class ItemType>
bool DStack<ItemType>::full() const
{
    return (myTop == myCapacity - 1);
}

template <class ItemType>
bool DStack<ItemType>::empty() const
{
    return (myTop == -1);
}

template <class ItemType>
void DStack<ItemType>::push(const ItemType &value)
{
    if (!full())
    {
        myArrayPtr[++myTop] = value;
    }
    else
    {
        cout << "DStack is full. Cannot push." << endl;
    }
}

template <class ItemType>
ItemType DStack<ItemType>::top()
{
    if (!empty())
    {
        return myArrayPtr[myTop];
    }
    else
    {
        cout << "DStack is empty. No top element." << endl;
        return ItemType();
    }
}

template <class ItemType>
void DStack<ItemType>::pop()
{
    if (!empty())
    {
        --myTop;
    }
    else
    {
        cout << "DStack is empty. Cannot pop." << endl;
    }
}

template <class ItemType>
void DStack<ItemType>::pop(ItemType &item)
{
    if (!empty())
    {
        item = myArrayPtr[myTop--];
    }
    else
    {
        cout << "DStack is empty. Cannot pop." << endl;
    }
}

template <class ItemType>
void DStack<ItemType>::print() const
{
    for (int i = myTop; i >= 0; --i)
    {
        cout << myArrayPtr[i];
        if (i > 0)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

template <class ItemType>
void DStack<ItemType>::reverse(DStack<ItemType> &oth)
{
    DStack<ItemType> tempStack(*this);
    while (!tempStack.empty())
    {
        ItemType item;
        tempStack.pop(item);
        oth.push(item);
    }
}

#endif