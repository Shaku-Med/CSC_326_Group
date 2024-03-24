#include <iostream>
#include "Unsort.h"

int main()
{
    // Problem 1: Usage of UnsortedType
    std::cout << "Problem 1: Usage of UnsortedType" << std::endl;
    UnsortedType<int> list;
    list.insertItem(5);
    list.insertItem(10);
    list.insertItem(15);
    list.insertItem(20);

    int item;
    bool found;
    list.retrieveItem(item, found);
    if (found)
    {
        std::cout << "Item found: " << item << std::endl;
    }
    else
    {
        std::cout << "Item not found" << std::endl;
    }

    list.findDel(10); // Example usage of findDel

    // Output the list
    std::cout << "List after operations:" << std::endl;
    list.print();

    // Calculate sum, count, and average
    std::cout << "Calculating sum, count, and average..." << std::endl;
    list.calcList();

    std::cout << "End of Usort.cpp" << std::endl;

    return 0;
}
