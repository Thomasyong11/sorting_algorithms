#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * radix sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_value = array[0], exp = 1, *bucket = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	bucket = malloc(sizeof(int) * size);
	if (bucket == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	while (max_value / exp > 0)
	{
		int bucket_index[10] = {0};

		for (i = 0; i < size; i++)
			bucket_index[array[i] / exp % 10]++;

		for (i = 1; i < 10; i++)
			bucket_index[i] += bucket_index[i - 1];

		for (i = size - 1; (int) i >= 0; i--)
		{
			bucket[--bucket_index[array[i] / exp % 10]] = array[i];
		}

		for (i = 0; i < size; i++)
			array[i] = bucket[i];

		print_array(array, size);

		exp *= 10;
	}

	free(bucket);
}
