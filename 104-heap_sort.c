#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Repair the heap whose root element is at index 'start',
 * assuming the heaps rooted at its children are valid.
 * @array: The array to sort.
 * @start: The starting index of the heap.
 * @end: The ending index of the heap.
 * @size: The size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			int tmp = array[root];

			array[root] = array[swap];
			array[swap] = tmp;

			print_array(array, size);
			 root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             sift-down heap sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int tmp;
	size_t start, end;

	if (array == NULL || size < 2)
		return;

	for (start = (size - 2) / 2; start > 0; start--)
		sift_down(array, start, size - 1, size);

	sift_down(array, 0, size - 1, size);

	for (end = size - 1; end > 0; end--)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;

		print_array(array, size);

		sift_down(array, 0, end - 1, size);
	}
}
