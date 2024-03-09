#include <iostream>
#include "DStack.h"

using namespace std;

int main()
{
    Stack<int> intStack(5);
    //
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);
    intStack.push(5);

    cout << "Stack elements: ";
    intStack.print();
    //
    int poppedValue;
    intStack.pop(poppedValue);
    cout << "Popped value: " << poppedValue << endl;

    cout << "Stack elements after popping: ";
    intStack.print();
    //
    int topElement = intStack.top();
    cout << "Top element of the stack: " << topElement << endl;
    //
    Stack<char> charStack(3);
    //
    charStack.push('a');
    charStack.push('b');
    charStack.push('c');

    cout << "Character stack elements: ";
    charStack.print();
    return 0;
}
