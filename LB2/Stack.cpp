#include "Stack.h"
#include <iostream>
using namespace std;

template <class ItemType>
void replace(Stack<ItemType> &stack, const ItemType &oItem, const ItemType &nItem)
{
    Stack<ItemType> tempStack;
    //
    while (!stack.empty())
    {
        ItemType current = stack.top();
        stack.pop();

        if (current == oItem)
        {
            tempStack.push(nItem);
        }
        else
        {
            tempStack.push(current);
        }
    }
    // RECOVER THE MISSING ITEM
    while (!tempStack.empty())
    {
        stack.push(tempStack.top());
        tempStack.pop();
    }
}

int main()
{
    Stack<int> s1;
    Stack<int> s2;
    //
    int length = 4;
    //
    for (int i = 1; i < length; i++)
    {
        s1.push(i);
        if (i < length - 1)
        {
            s2.push(i);
        }
    }
    //
    cout << "\033[1;33m"
         << "S1 STACK SIZE: " << s1.size() << "\033[0m" << endl;
    //
    cout << "\033[1;33m"
         << "S2 STACK SIZE: " << s2.size() << "\033[0m" << endl;
    //
    cout << endl;
    //
    cout << "\033[1;36m"
         << "PRINT S1 CONTENTS: \n"
         << "\033[0m";
    //
    s1.print();
    //
    cout << "--------------------------" << endl;
    //
    cout << "\033[1;36m"
         << "PRINT S1 CONTENTS: \n"
         << "\033[0m";
    //
    s2.print();

    //

    //
    cout << endl;

    cout << "--------------------------" << endl;

    cout << "ARE S1 AND S2 IDENTICAL? "
         << (s1.identical(s2) ? "\033[1;32m" : "\033[1;31m") << (s1.identical(s2) ? "YES" : "NO") << "\033[0m" << endl;

    //

    replace(s1, 1, 4);

    cout << endl;

    cout << "--------------------------" << endl;

    s1.print();
}