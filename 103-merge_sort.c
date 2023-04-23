#include "sort.h"
#include <stdio.h>

void merge(int *array, int *temp, size_t left_start, size_t right_start, size_t right_end)
{
    size_t left_end = right_start - 1;
    size_t temp_index = left_start;
    size_t size = right_end - left_start + 1;

    while (left_start <= left_end && right_start <= right_end)
    {
        if (array[left_start] <= array[right_start])
            temp[temp_index++] = array[left_start++];
        else
            temp[temp_index++] = array[right_start++];
    }

    while (left_start <= left_end)
        temp[temp_index++] = array[left_start++];

    while (right_start <= right_end)
        temp[temp_index++] = array[right_start++];

    for (size_t i = 0; i < size; i++, right_end--)
        array[right_end] = temp[right_end];
}

void merge_sort_helper(int *array, int *temp, size_t start, size_t end)
{
    if (start >= end)
        return;

    size_t middle = (start + end) / 2;

    merge_sort_helper(array, temp, start, middle);
    merge_sort_helper(array, temp, middle + 1, end);

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + start, middle - start + 1);
    printf("[right]: ");
    print_array(array + middle + 1, end - middle);
    merge(array, temp, start, middle + 1, end);
    printf("[Done]: ");
    print_array(array + start, end - start + 1);
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp = malloc(sizeof(int) * size);

    if (!temp)
        return;

    merge_sort_helper(array, temp, 0, size - 1);

    free(temp);
}
