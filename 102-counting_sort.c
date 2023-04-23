#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: pointer to array of integers to be sorted
 * @size: size of the array to be sorted
 */
void counting_sort(int *array, size_t size)
{
    int *counting_array;
    int max, i;

    if (!array || size < 2)
        return;

    max = array[0];
    for (i = 1; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    counting_array = malloc(sizeof(int) * (max + 1));
    if (!counting_array)
        return;

    for (i = 0; i <= max; i++)
        counting_array[i] = 0;

    for (i = 0; i < (int)size; i++)
        counting_array[array[i]]++;

    printf("%d", counting_array[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", counting_array[i]);
    printf("\n");

    for (i = 1; i <= max; i++)
        counting_array[i] += counting_array[i - 1];

    for (i = (int)size - 1; i >= 0; i--)
    {
        array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    free(counting_array);
}
