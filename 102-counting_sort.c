#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 counting sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 **/
void counting_sort(int *array, size_t size)
{
	int max_val, i;
	int *count_array, *sorted_array;

	if (!array || size < 2)
		return;

	max_val = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	count_array = malloc(sizeof(int) * (max_val + 1));
	if (!count_array)
		return;

	for (i = 0; i <= max_val; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= max_val; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max_val + 1);

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array);
		return;
	}

	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count_array);
}
