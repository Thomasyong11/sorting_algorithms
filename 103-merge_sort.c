#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sorted subarrays into a single sorted array
 * @array: Pointer to the main array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 **/
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    int i = 0, j = 0, k = 0;
    int *merged_array = malloc(sizeof(int) * (left_size + right_size));

    if (!merged_array)
        return;

    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
            merged_array[k++] = left[i++];
        else
            merged_array[k++] = right[j++];
    }

    while (i < left_size)
        merged_array[k++] = left[i++];

    while (j < right_size)
        merged_array[k++] = right[j++];

    for (i = 0; i < k; i++)
        array[i] = merged_array[i];

    free(merged_array);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array to be sorted
 **/
void merge_sort(int *array, size_t size)
{
    size_t mid = size / 2;
    int *left = array, *right = array + mid;
    size_t left_size = mid, right_size = size - mid;

    if (size <= 1)
        return;

    merge_sort(left, left_size);
    merge_sort(right, right_size);
    merge(array, left, left_size, right, right_size);

    printf("[Done]: ");
    print_array(array, size);
}
