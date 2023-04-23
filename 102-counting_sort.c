#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max = 0, *count = NULL, *output = NULL;

	/* find the largest element in the array */
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* allocate memory for the count and output arrays */
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	/* initialize the count array */
	for (i = 0; i <= max; i++)
		count[i] = 0;
	/* count the occurrences of each element */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	/* print the count array */
	printf("%d", count[0]);
	for (i = 1; i <= max; i++)
		printf(", %d", count[i]);
	printf("\n");

	/* calculate the running sum */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	/* fill the output array */
	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* copy the output array to the input array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	/* free memory */
	free(count);
	free(output);
}
