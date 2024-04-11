// FileSortedList.h: Header file for Sorted List ADT.
// Class is templated.

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType> *next;
};

template <class ItemType>
class SortedList
{
public:
    SortedList();
    ~SortedList();

    bool full() const;
    int lengthIs() const;
    void makeEmpty();
    void retrieveItem(ItemType &item, bool &found);
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    bool atEnd();
    void resetList();
    void getNextItem(ItemType &item);
    void print();
    void mergeLists(const SortedList<ItemType> &otherList, SortedList<ItemType> &mergedList);

private:
    NodeType<ItemType> *listData;
    int length;
    NodeType<ItemType> *currentPos;
};

template <class ItemType>
SortedList<ItemType>::SortedList()
{
    length = 0;
    listData = nullptr;
    currentPos = nullptr;
}

template <class ItemType>
SortedList<ItemType>::~SortedList() { makeEmpty(); }

template <class ItemType>
bool SortedList<ItemType>::full() const
{
    NodeType<ItemType> *ptr;
    ptr = new NodeType<ItemType>;
    if (ptr == nullptr)
        return true;
    else
    {
        delete ptr;
        return false;
    }
}

template <class ItemType>
void SortedList<ItemType>::makeEmpty()
{
    NodeType<ItemType> *tempPtr;
    while (listData != nullptr)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
    currentPos = nullptr;
}

template <class ItemType>
int SortedList<ItemType>::lengthIs() const
{
    return length;
}

template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item)
{
    NodeType<ItemType> *location = listData;
    NodeType<ItemType> *tempLocation;

    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while (!(item == (location->next)->info))
            location = location->next;
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void SortedList<ItemType>::resetList()
{
    currentPos = nullptr;
}

template <class ItemType>
void SortedList<ItemType>::retrieveItem(ItemType &item, bool &found)
{
    bool moreToSearch;
    NodeType<ItemType> *location;
    location = listData;
    found = false;
    moreToSearch = (location != nullptr);
    while (moreToSearch && !found)
    {
        if (location->info < item)
        {
            location = location->next;
            moreToSearch = (location != nullptr);
        }
        else if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
            moreToSearch = false;
    }
}

template <class ItemType>
void SortedList<ItemType>::insertItem(ItemType item)
{
    NodeType<ItemType> *newNode;
    NodeType<ItemType> *predLoc;
    NodeType<ItemType> *location;
    bool moreToSearch;
    location = listData;
    predLoc = nullptr;
    moreToSearch = (location != nullptr);

    while (moreToSearch)
    {
        if (location->info < item)
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != nullptr);
        }
        else
            moreToSearch = false;
    }

    newNode = new NodeType<ItemType>;
    newNode->info = item;

    if (predLoc == nullptr)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

template <class ItemType>
bool SortedList<ItemType>::atEnd()
{
    return currentPos == nullptr;
}

template <class ItemType>
void SortedList<ItemType>::getNextItem(ItemType &item)
{
    if (currentPos == nullptr)
        currentPos = listData;
    item = currentPos->info;
    currentPos = currentPos->next;
}

template <class ItemType>
void SortedList<ItemType>::print()
{
    NodeType<ItemType> *tempPtr;
    tempPtr = listData;
    while (tempPtr != nullptr)
    {
        cout << tempPtr->info << ' ';
        tempPtr = tempPtr->next;
    }
    cout << endl;
}

// THE NEW MEMBER FUNCTION FOR QUESTION -> (A)

template <class ItemType>
void SortedList<ItemType>::mergeLists(const SortedList<ItemType> &otherList, SortedList<ItemType> &mergedList)
{

    NodeType<ItemType> *current = listData;
    NodeType<ItemType> *other = otherList.listData;

    while (current != nullptr)
    {
        mergedList.insertItem(current->info);
        current = current->next;
    }

    current = mergedList.listData;
    while (other != nullptr)
    {
        if (other->info != current->info)
        {
            mergedList.insertItem(other->info);
        }
        current = current->next;
        other = other->next;
    }
}

/*
// THIS IS A TEMP MERGE CODE
template <class ItemType>
void SortedList<ItemType>::mergeLists(const SortedList<ItemType> &otherList, SortedList<ItemType> &mergedList)
{
    NodeType<ItemType> *current = listData;
    NodeType<ItemType> *other = otherList.listData;

    while (current != nullptr && other != nullptr)
    {
        if (current->info < other->info)
        {
            mergedList.length++;
            if (mergedList.listData == nullptr)
            {
                mergedList.listData = new NodeType<ItemType>;
                mergedList.listData->info = current->info;
                mergedList.listData->next = nullptr;
                current = current->next;
            }
            else
            {
                NodeType<ItemType> *temp = mergedList.listData;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = new NodeType<ItemType>;
                temp->next->info = current->info;
                temp->next->next = nullptr;
                current = current->next;
            }
        }
        else
        {
            mergedList.length++;
            if (mergedList.listData == nullptr)
            {
                mergedList.listData = new NodeType<ItemType>;
                mergedList.listData->info = other->info;
                mergedList.listData->next = nullptr;
                other = other->next;
            }
            else
            {
                NodeType<ItemType> *temp = mergedList.listData;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = new NodeType<ItemType>;
                temp->next->info = other->info;
                temp->next->next = nullptr;
                other = other->next;
            }
        }
    }

    while (current != nullptr)
    {
        mergedList.length++;
        if (mergedList.listData == nullptr)
        {
            mergedList.listData = new NodeType<ItemType>;
            mergedList.listData->info = current->info;
            mergedList.listData->next = nullptr;
            current = current->next;
        }
        else
        {
            NodeType<ItemType> *temp = mergedList.listData;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new NodeType<ItemType>;
            temp->next->info = current->info;
            temp->next->next = nullptr;
            current = current->next;
        }
    }

    while (other != nullptr)
    {
        mergedList.length++;
        if (mergedList.listData == nullptr)
        {
            mergedList.listData = new NodeType<ItemType>;
            mergedList.listData->info = other->info;
            mergedList.listData->next = nullptr;
            other = other->next;
        }
        else
        {
            NodeType<ItemType> *temp = mergedList.listData;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new NodeType<ItemType>;
            temp->next->info = other->info;
            temp->next->next = nullptr;
            other = other->next;
        }
    }
}

*/