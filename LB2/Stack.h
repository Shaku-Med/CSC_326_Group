#ifndef STACK_TCA_H
#define STACK_TCA_H
#include <iostream>
using namespace std;

const int MAX_ITEMS = 128;

template <class ItemType>
class Stack
{
public:
    Stack();
    bool empty() const;
    bool full() const;
    void makeEmpty();
    void push(const ItemType &value);
    void print() const;
    ItemType top() const;
    void pop();
    void pop(ItemType &value);
    int size() const;
    bool identical(const Stack<ItemType> &other) const;

private:
    ItemType myArray[MAX_ITEMS];
    int myTop;
};

template <class ItemType>
Stack<ItemType>::Stack()
{
    myTop = -1;
}

template <class ItemType>
bool Stack<ItemType>::empty() const
{
    return (myTop == -1);
}

template <class ItemType>
bool Stack<ItemType>::full() const
{
    return (myTop == MAX_ITEMS - 1);
}

template <class ItemType>
void Stack<ItemType>::push(const ItemType &value)
{
    if (myTop < MAX_ITEMS - 1)
    {
        ++myTop;
        myArray[myTop] = value;
    }
    else
    {
        cerr << "*** Stack Full -- can't add new value *** \n"
                "Must increase value of MAX_ITEMS in Stack.h \n";
        exit(1);
    }
}

template <class ItemType>
void Stack<ItemType>::makeEmpty()
{
    myTop = -1;
}

template <class ItemType>
void Stack<ItemType>::print() const
{
    for (int i = myTop; i >= 0; i--)
        cout << myArray[i] << endl;
}

template <class ItemType>
ItemType Stack<ItemType>::top() const
{
    if (!empty())
        return (myArray[myTop]);
    else
    {
        cerr << "*** Stack is empty ***\n";
    }
}

template <class ItemType>
void Stack<ItemType>::pop()
{
    if (!empty())
        myTop--;
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}

template <class ItemType>
void Stack<ItemType>::pop(ItemType &value)
{
    value = myArray[myTop];
    myTop--;
}

template <class ItemType>
int Stack<ItemType>::size() const
{
    return myTop + 1;
}

template <class ItemType>
bool Stack<ItemType>::identical(const Stack<ItemType> &other) const
{
    if (size() != other.size())
    {
        return false;
    }
    else
    {
        for (int i = 0; i <= myTop; i++)
        {
            return myArray[i] != other.myArray[i] ? false : true;
        }
        return true;
    }
}

#endif