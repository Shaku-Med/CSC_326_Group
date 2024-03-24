#include <iostream>
#include "LQueue.h"

int main()
{
    // Problem 2: Usage of Que based on linked nodes
    std::cout << "Problem 2: Usage of Que based on linked nodes" << std::endl;
    double numbers[] = {25, 64, -3, 6.25, 36, -4.5, 86, 14, -12, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    Que<double> queue;
    std::cout << "Adding elements to the queue:" << std::endl;
    queue.changeQue(numbers, size);

    std::cout << "End of LQueue.cpp" << std::endl;

    return 0;
}
