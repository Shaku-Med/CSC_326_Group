```c++

template <class ItemType>
void SortedList<ItemType>::mergeLists(const SortedList<ItemType> &objList)
{
    NodeType<ItemType> *temp1 = listData;
    NodeType<ItemType> *temp2 = objList.listData;
    SortedList<ItemType> mergedList;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->info < temp2->info)
        {
            mergedList.insertItem(temp1->info);
            temp1 = temp1->next;
        }
        else if (temp2->info < temp1->info)
        {
            mergedList.insertItem(temp2->info);
            temp2 = temp2->next;
        }
        else
        {
            mergedList.insertItem(temp1->info);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != nullptr)
    {
        mergedList.insertItem(temp1->info);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        mergedList.insertItem(temp2->info);
        temp2 = temp2->next;
    }

    makeEmpty();

    temp1 = mergedList.listData;
    while (temp1 != nullptr)
    {
        insertItem(temp1->info);
        temp1 = temp1->next;
    }
}

```