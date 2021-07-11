#include "Sort.h"

void Sort::Merge(int *numbers, int i, int j, int k)
{
	int mergedSize = k - i + 1;
	int mergePos = 0, 
		leftPos = 0, 
		rightPos = 0;

	int *mergedNumbers = new int[mergedSize];

	leftPos = i;
	rightPos = j + 1;

	// Add smallest element from L or R partition to merged numbers
	while (leftPos <= j && rightPos <= k)
	{
		if (numbers[leftPos] <= numbers[rightPos])
		{
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
		}
		else
		{
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;
		}
		++mergePos;
	}

	// If L partition is not empty, add remaining elements to merged numbers
	while (leftPos <= j)
	{
		mergedNumbers[mergePos] = numbers[leftPos];
		++leftPos;
		++mergePos;
	}

	// Repeat for R partition
	while (rightPos <= k)
	{
		mergedNumbers[mergePos] = numbers[rightPos];
		++rightPos;
		++mergePos;
	}

	// Copy merge number back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos)
	{
		numbers[i + mergePos] = mergedNumbers[mergePos];
	}
}

void Sort::MergeSort(int *numbers, int i, int k)
{
	int j = 0;

	if (i < k)
	{
		j = (i + k) / 2;	// find midpoint
	}
	else if (i == k)
		return;

	// Recursively sort L and R partitions
	MergeSort(numbers, i, j);
	MergeSort(numbers, j + 1, k);

	// Merge L and R partitions in sorted order
	Merge(numbers, i, j, k);
}
