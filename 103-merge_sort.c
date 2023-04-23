#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays of the given array
 *
 * @array: The array containing the two sub-arrays to be merged
 * @left: The left sub-array
 * @left_size: The size of the left sub-array
 * @right: The right sub-array
 * @right_size: The size of the right sub-array
 *
 * Return: Nothing
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc(sizeof(int) * (left_size + right_size));

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < left_size)
        temp[k++] = left[i++];

    while (j < right_size)
        temp[k++] = right[j++];

    for (i = 0; i < left_size + right_size; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t i, mid = size / 2;
        int *left = array, *right = array + mid;

        merge_sort(left, mid);
        merge_sort(right, size - mid);

        merge(array, left, mid, right, size - mid);
    }
}
