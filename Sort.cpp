#include "Sort.h"

void Sort::Merge(int *numbers, int start, int mid, int end)
{
	int mergedSize = end - start + 1;
	int mergePos = 0, 
		leftPos = 0, 
		rightPos = 0;

	int *mergedNumbers = new int[mergedSize];

	leftPos = start;
	rightPos = mid + 1;

	// Add smallest element from L or R partition to merged numbers
	while (leftPos <= mid && rightPos <= end)
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
	while (leftPos <= mid)
	{
		mergedNumbers[mergePos] = numbers[leftPos];
		++leftPos;
		++mergePos;
	}

	// Repeat for R partition
	while (rightPos <= end)
	{
		mergedNumbers[mergePos] = numbers[rightPos];
		++rightPos;
		++mergePos;
	}

	// Copy merge number back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos)
	{
		numbers[start + mergePos] = mergedNumbers[mergePos];
	}
}

void Sort::MergeSort(int *numbers, int start, int end)
{
	int mid = 0;

	if (start < end)
	{
		mid = (start + end) / 2;	// find midpoint
	}
	else if (start == end)
		return;

	// Recursively sort L and R partitions
	MergeSort(numbers, start, mid);
	MergeSort(numbers, mid + 1, end);

	// Merge L and R partitions in sorted order
	Merge(numbers, start, mid, end);
}
