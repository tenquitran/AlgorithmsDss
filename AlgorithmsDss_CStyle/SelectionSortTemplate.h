#pragma once


namespace AlgorithmsDss_CStyle
{
    // Perform selection sort on the array (from smallest to largest): function template.
    // Parameters: arr   - array to sort;
    //             count - number of elements in the array.
    template <typename T>
    void selectionSort(T arr[], size_t count);
    
    // Helper function for selection sort: swap the array elements.
    template <typename T>
    void selectionSortSwap(T& a, T& b);
}

#include "SelectionSortTemplate.cpp"
