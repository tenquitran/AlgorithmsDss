#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace AlgorithmsDss_CStyle;

//////////////////////////////////////////////////////////////////////////


void AlgorithmsDss_CStyle::selectionSort(int arr[], size_t count)
{
    // Index of the minimum element.
    size_t minIndex = {};

    // Outer loop: move forward over the array.
    // Iterating over the last element of the array is possible but unnecessary: 
    // by the end of the outer loop, the largest element will already be at the end of the array.
    for (size_t i = {}; i < (count - 1); ++i)
    {
        // Important: each new search for a new element should start one element further than the previous search.
        minIndex = i;

        // Inner loop: find a minimum element in the unsorted part of the array.
        for (size_t j = (i + 1); j < count; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // If necessary, swap the found minimum element with the first element of the unsorted part of the array.
        if (arr[i] > arr[minIndex])
        {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}
