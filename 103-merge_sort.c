#include "sort.h"

/**
 * merge - Merge two sub-arrays of arr[]
 * @arr: Array of integers
 * @temp: Array to store the sorted sub-arrays
 * @left: Starting index of left sub-array
 * @mid: Middle index
 * @right: Ending index of right sub-array
 *
 * Return: Void
 */
void merge(int *arr, int *temp, int left, int mid, int right)
{
    int i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(arr + left, mid - left);
    printf("[right]: ");
    print_array(arr + mid, right - mid);

    for (i = left, j = mid, k = 0; i < mid && j < right; k++)
    {
        if (arr[i] <= arr[j])
            temp[k] = arr[i++];
        else
            temp[k] = arr[j++];
    }

    while (i < mid)
        temp[k++] = arr[i++];

    while (j < right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i < right; i++)
    {
        arr[i] = temp[k++];
    }

    printf("[Done]: ");
    print_array(arr + left, right - left);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: Void
 */
void merge_sort(int *array, size_t size)
{
    int *temp;
    size_t i, mid, right, left;

    if (!array || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    mid = size / 2;
    left = 0;
    right = size;

    merge_sort(array, mid);
    merge_sort(array + mid, right - mid);
    merge(array, temp, left, mid, right);

    free(temp);
}
