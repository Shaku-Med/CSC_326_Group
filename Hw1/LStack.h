// LStack.h: Stack based on Linked Structures
// Class is templated.

#ifndef LSTACKT_H
#define LSTACKT_H

#include <iostream>
#include <cassert>

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType> *next;
};

template <class ItemType>
class Stack
{
public:
    Stack();
    ~Stack();
    Stack(const Stack<ItemType> &original);
    void operator=(Stack<ItemType> &s);
    void makeEmpty();
    bool full() const;
    bool empty() const;
    void push(const ItemType &item);
    void pop(ItemType &item);
    void pop();
    ItemType top() const;
    void print() const;
    // Prototype of new member function catStack
    void catStack(Stack<ItemType> &otherStack);
    // I need to access the topPtr. Not by using the ItemType top function decleared. That's Y I created my own function.
    NodeType<ItemType> *getTopPtr() const
    {
        return topPtr;
    }

private:
    NodeType<ItemType> *topPtr;
};

// Templated member function definitions for LStack class

template <class ItemType>
Stack<ItemType>::Stack()
{
    topPtr = NULL;
}

template <class ItemType>
Stack<ItemType>::~Stack()
{
    makeEmpty();
}

template <class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType> &original)
{
    NodeType<ItemType> *ptr1;
    NodeType<ItemType> *ptr2;

    if (original.topPtr == NULL)
        topPtr = NULL;
    else
    {
        topPtr = new NodeType<ItemType>;
        topPtr->info = original.topPtr->info;
        ptr1 = original.topPtr->next;
        ptr2 = topPtr;

        while (ptr1 != NULL)
        {
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = NULL;
    }
}

template <class ItemType>
void Stack<ItemType>::operator=(Stack<ItemType> &s)
{
    if (this != &s)
    {
        makeEmpty();

        NodeType<ItemType> *ptr1;
        NodeType<ItemType> *ptr2;

        if (s.topPtr == NULL)
            topPtr = NULL;
        else
        {
            topPtr = new NodeType<ItemType>;
            topPtr->info = s.topPtr->info;
            ptr1 = s.topPtr->next;
            ptr2 = topPtr;

            while (ptr1 != NULL)
            {
                ptr2->next = new NodeType<ItemType>;
                ptr2 = ptr2->next;
                ptr2->info = ptr1->info;
                ptr1 = ptr1->next;
            }
            ptr2->next = NULL;
        }
    }
}

template <class ItemType>
void Stack<ItemType>::makeEmpty()
{
    NodeType<ItemType> *tempPtr;

    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template <class ItemType>
bool Stack<ItemType>::full() const
{
    NodeType<ItemType> *ptr = new NodeType<ItemType>;
    if (ptr == NULL)
        return true;
    else
    {
        delete ptr;
        return false;
    }
}

template <class ItemType>
bool Stack<ItemType>::empty() const
{
    return (topPtr == NULL);
}

template <class ItemType>
ItemType Stack<ItemType>::top() const
{
    assert(!empty());
    return (topPtr->info);
}

template <class ItemType>
void Stack<ItemType>::push(const ItemType &newItem)
{
    NodeType<ItemType> *ptr = new NodeType<ItemType>;
    assert(ptr != NULL);
    ptr->info = newItem;
    ptr->next = topPtr;
    topPtr = ptr;
}

template <class ItemType>
void Stack<ItemType>::pop(ItemType &item)
{
    if (!empty())
    {
        NodeType<ItemType> *tempPtr;
        tempPtr = topPtr;
        item = topPtr->info;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    else
        std::cerr << "*** Stack is empty -- can't remove a value ***\n";
}

template <class ItemType>
void Stack<ItemType>::pop()
{
    if (!empty())
    {
        NodeType<ItemType> *tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    else
        std::cerr << "*** Stack is empty -- can't remove a value ***\n";
}

template <class ItemType>
void Stack<ItemType>::print() const
{
    NodeType<ItemType> *tempPtr = topPtr;

    while (tempPtr != NULL)
    {
        std::cout << tempPtr->info;
        if (tempPtr->next != NULL)
        {
            std::cout << ", ";
        }
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}

template <class ItemType>
void Stack<ItemType>::catStack(Stack<ItemType> &otherStack)
{
    if (topPtr == nullptr)
    {
        topPtr = otherStack.topPtr;
    }
    else
    {
        NodeType<ItemType> *tempPtr = topPtr;
        while (tempPtr->next != nullptr)
        {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = otherStack.topPtr;
    }
    otherStack.topPtr = nullptr;
}

#endif
