// Unsort.h
#ifndef UNSORT_H
#define UNSORT_H

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType> *next;
};

template <class ItemType>
class UnsortedType
{
public:
    UnsortedType();  // Class constructor
    ~UnsortedType(); // Class destructor
    bool full() const;
    int lengthIs() const;
    void makeEmpty();
    void retrieveItem(ItemType &item, bool &found);
    void insertItem(const ItemType &item);
    void deleteItem(const ItemType &item);
    void resetList();
    void getNextItem(ItemType &item);
    bool atEnd();
    void print();
    // New Function
    void findDel(ItemType item);
    void calcList();

private:
    NodeType<ItemType> *listData;
    int length;
    NodeType<ItemType> *currentPos;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    listData = nullptr;
    currentPos = nullptr;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    makeEmpty();
}

template <class ItemType>
bool UnsortedType<ItemType>::full() const
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
void UnsortedType<ItemType>::insertItem(const ItemType &item)
{
    NodeType<ItemType> *location;
    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

template <class ItemType>
void UnsortedType<ItemType>::makeEmpty()
{
    NodeType<ItemType> *tempPtr;
    while (listData != nullptr)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::retrieveItem(ItemType &item, bool &found)
{
    NodeType<ItemType> *location;
    location = listData;
    found = false;
    while (location != nullptr && !found)
    {
        if (location->info == item)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
        }
    }
}

template <class ItemType>
void UnsortedType<ItemType>::deleteItem(const ItemType &item)
{
    NodeType<ItemType> *location = listData;
    NodeType<ItemType> *tempLocation;

    // Handle case where item to delete is at the beginning of the list
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        // Find the node before the one to delete
        while (!(item == (location->next)->info))
        {
            location = location->next;
        }

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::resetList()
{
    currentPos = nullptr;
}

template <class ItemType>
void UnsortedType<ItemType>::getNextItem(ItemType &item)
{
    if (currentPos == nullptr)
    {
        currentPos = listData;
    }
    else
    {
        currentPos = currentPos->next;
    }
    item = currentPos->info;
}

template <class ItemType>
bool UnsortedType<ItemType>::atEnd()
{
    return (currentPos == nullptr || currentPos->next == nullptr);
}

template <class ItemType>
int UnsortedType<ItemType>::lengthIs() const
{
    return length;
}

template <class ItemType>
void UnsortedType<ItemType>::print()
{
    NodeType<ItemType> *temp = listData;
    while (temp != nullptr)
    {
        std::cout << temp->info << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// NEW FUNC DEFINATION

template <class ItemType>
void UnsortedType<ItemType>::findDel(ItemType item)
{
    NodeType<ItemType> *location = listData;
    NodeType<ItemType> *tempLocation = nullptr;

    // Check if the list is empty
    if (location == nullptr)
    {
        return;
    }

    // If the item to delete is at the beginning of the list
    if (item == location->info)
    {
        tempLocation = location;
        listData = listData->next;
        delete tempLocation;
        length--;
        return;
    }

    // Traverse the list to find the node to delete
    while (location != nullptr)
    {
        if (location->info == item)
        {
            tempLocation->next = location->next;
            delete location;
            length--;
            return;
        }
        tempLocation = location;
        location = location->next;
    }
}

template <class ItemType>
void UnsortedType<ItemType>::calcList()
{
    NodeType<ItemType> *temp = listData;
    double sum = 0;
    int count = 0;

    // Traverse the list to calculate sum and count
    while (temp != nullptr)
    {
        sum += temp->info;
        count++;
        temp = temp->next;
    }

    // Calculate average
    double average = sum / count;

    // Output sum, count, and average
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Count: " << count << std::endl;
    std::cout << "Average: " << average << std::endl;
}

#endif
