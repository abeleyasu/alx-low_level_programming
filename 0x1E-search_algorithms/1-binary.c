#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - Searches for a value in a sorted array of integers using Binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index where value is located, or -1 if value is not present or array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left, right, mid;
    size_t i;  /* Declare the loop variable outside */

    if (array == NULL)
        return (-1);

    left = 0;
    right = size - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
            else
                printf("\n");
        }

        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}
