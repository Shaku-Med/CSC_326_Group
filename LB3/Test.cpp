#include "SortedList.h"
#include <iostream>

using namespace std;

int main()
{
    // Creating 6 objects of class SortedList
    SortedList<int> intList1, intList2, intList3;
    SortedList<double> doubleList1, doubleList2, doubleList3;
    SortedList<char> charList1, charList2, charList3;

    // Inserting elements into lists
    intList1.insertItem(5);
    intList1.insertItem(10);
    intList1.insertItem(15);
    intList1.insertItem(20);
    intList1.insertItem(30);
    intList1.insertItem(50);

    intList2.insertItem(7);
    intList2.insertItem(12);
    intList2.insertItem(17);
    intList2.insertItem(19);
    intList2.insertItem(13);

    doubleList1.insertItem(2.5);
    doubleList1.insertItem(4.7);
    doubleList1.insertItem(6.3);
    doubleList1.insertItem(7.8);

    doubleList2.insertItem(3.1);
    doubleList2.insertItem(5.9);
    doubleList2.insertItem(8.2);
    doubleList2.insertItem(9.2);

    charList1.insertItem('a');
    charList1.insertItem('c');
    charList1.insertItem('e');
    charList1.insertItem('g');
    charList1.insertItem('t');

    charList2.insertItem('b');
    charList2.insertItem('d');
    charList2.insertItem('f');
    charList2.insertItem('z');

    // Merging lists
    intList1.mergeLists(intList2, intList3);
    doubleList1.mergeLists(doubleList2, doubleList3);
    charList1.mergeLists(charList2, charList3);

    // Printing merged lists
    cout << "Merged Integer List:" << endl;
    intList3.print();
    cout << "\n";
    cout << "Merged Double List:" << endl;
    doubleList3.print();
    cout << "\n";
    cout << "Merged Char List:" << endl;
    charList3.print();

    return 0;
}
