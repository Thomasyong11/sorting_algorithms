#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0;
    int *merged = malloc((left_size + right_size) * sizeof(int));

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }

    while (i < left_size)
        merged[k++] = left[i++];
    while (j < right_size)
        merged[k++] = right[j++];

    for (i = 0; i < k; i++)
        array[i] = merged[i];

    printf("[Done]: ");
    print_array(array, k);

    free(merged);
}

void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int mid = size / 2;
    int *left = array;
    int *right = array + mid;
    int left_size = mid;
    int right_size = size - mid;

    merge_sort(left, left_size);
    merge_sort(right, right_size);
    merge(array, left, left_size, right, right_size);
}
