#ifndef QUEUE_T_H
#define QUEUE_T_H

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType> *next;
};

template <class ItemType>
class Que
{
public:
    Que();                                     // Class constructor
    ~Que();                                    // Class destructor
    Que(const Que<ItemType> &original);        // User-defined copy constructor
    void operator=(Que<ItemType> &otherQueue); // User-defined assignment operator
    void makeEmpty();
    bool empty() const;
    bool full() const;
    void addQ(ItemType newItem);
    void removeQ(ItemType &item);
    void print() const;
    void changeQue(ItemType numbers[], int size);

private:
    NodeType<ItemType> *qFront;
    NodeType<ItemType> *qRear;
};

template <class ItemType>
Que<ItemType>::Que()
{
    qFront = nullptr;
    qRear = nullptr;
}

template <class ItemType>
Que<ItemType>::~Que()
{
    makeEmpty();
}

template <class ItemType>
Que<ItemType>::Que(const Que<ItemType> &original)
{
    NodeType<ItemType> *tempPtr;
    NodeType<ItemType> *newPtr;
    if (original.qFront == nullptr)
        qFront = qRear = nullptr;
    else
    {
        tempPtr = original.qFront;
        newPtr = new NodeType<ItemType>;
        newPtr->info = tempPtr->info;
        tempPtr = tempPtr->next;
        qFront = newPtr;
        while (tempPtr != nullptr)
        {
            newPtr->next = new NodeType<ItemType>;
            newPtr = newPtr->next;
            newPtr->info = tempPtr->info;
            tempPtr = tempPtr->next;
        }
        newPtr->next = nullptr;
        qRear = newPtr;
    }
}

template <class ItemType>
void Que<ItemType>::makeEmpty()
{
    NodeType<ItemType> *tempPtr;
    while (qFront != nullptr)
    {
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr;
    }
    qRear = nullptr;
}

template <class ItemType>
void Que<ItemType>::operator=(Que<ItemType> &otherQueue)
{
    // Copy elements from otherQueue to this queue
    makeEmpty(); // Clear this queue first

    NodeType<ItemType> *tempPtr = otherQueue.qFront;
    while (tempPtr != nullptr)
    {
        addQ(tempPtr->info);
        tempPtr = tempPtr->next;
    }
}

template <class ItemType>
bool Que<ItemType>::empty() const
{
    return (qFront == nullptr);
}

template <class ItemType>
bool Que<ItemType>::full() const
{
    NodeType<ItemType> *ptr = new NodeType<ItemType>;
    if (ptr == nullptr)
        return true;
    else
    {
        delete ptr;
        return false;
    }
}

template <class ItemType>
void Que<ItemType>::addQ(ItemType newItem)
{
    NodeType<ItemType> *newNode = new NodeType<ItemType>;
    newNode->info = newItem;
    newNode->next = nullptr;
    if (qFront == nullptr)
    {
        qFront = newNode;
        qRear = newNode;
    }
    else
    {
        qRear->next = newNode;
        qRear = newNode;
    }
}

template <class ItemType>
void Que<ItemType>::removeQ(ItemType &item)
{
    if (empty())
    {
        std::cerr << "Queue is empty." << std::endl;
        return;
    }
    NodeType<ItemType> *tempPtr = qFront;
    item = qFront->info;
    qFront = qFront->next;
    delete tempPtr;
}

template <class ItemType>
void Que<ItemType>::print() const
{
    NodeType<ItemType> *current = qFront;
    while (current != nullptr)
    {
        std::cout << current->info << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <class ItemType>
void Que<ItemType>::changeQue(ItemType numbers[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] > 0)
            addQ(sqrt(numbers[i]));
        else
            addQ(numbers[i] * numbers[i]);
    }

    // Display all values stored into info parts of the queue
    while (!empty())
    {
        ItemType item;
        removeQ(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

#endif
