#include <iostream>
#include "DStack.h"
#include "LStack.h"

using namespace std;

template <class ItemType>
int length(const Stack<ItemType> &stack)
{
    int count = 0;
    NodeType<ItemType> *current = stack.getTopPtr();
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{
    // DSTACK TESTING
    DStack<int> dStack;
    dStack.push(1);
    dStack.push(2);
    dStack.push(3);
    //
    cout << "* -> Previous Stack: ";
    dStack.print();
    //
    DStack<int> reversedStack;
    dStack.reverse(reversedStack);

    cout << "* -> Reversed stack: ";
    reversedStack.print();

    cout << "............... DSTACK ENDS HERE ..............." << endl;
    cout << "\n";

    // LSTACK TESTING.
    //
    cout << "............... LSTACK STARTS HERE ..............." << endl;

    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    //
    cout << "* -> Previous Stack: ";
    stack1.print();
    //
    Stack<int> stack2;
    stack2.push(4);
    stack2.push(5);
    //
    cout << "* -> Added Stack: ";
    stack2.print();
    //
    stack1.catStack(stack2);

    cout << "* -> Current Stack: ";
    stack1.print();
    //
    cout << '\n';
    cout << "////// -> LENGTH OF THE STACK1 <- \\\\\\\\\\" << endl;
    cout << '\n';
    cout << "Length of STACK1: " << length(stack1) << endl;

    return 0;
}
