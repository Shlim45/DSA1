#include <iostream>

#include "Sort.h"

int main()
{
    int numbers[] = { 88, 21, 28, 24, 36, 71, 58, 11, 29 };
    int numSize = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Unsorted Numbers: [";
    for (int i = 0; i < numSize; ++i)
    {
        std::cout << numbers[i];
        if (i < (numSize - 1))
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    Sort Sort;
    Sort.MergeSort(numbers, 0, numSize - 1);

    std::cout << "Sorted Numbers: [";
    for (int i = 0; i < numSize; ++i)
    {
        std::cout << numbers[i];
        if (i < (numSize - 1))
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << std::endl;
    system("pause");
}
