#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merges two sorted sub-arrays
 * @array: the original array
 * @size: size of the array
 * @left: pointer to the left sub-array
 * @left_size: size of the left sub-array
 * @right: pointer to the right sub-array
 * @right_size: size of the right sub-array
 **/
void merge(int *array, size_t size, int *left, size_t left_size,
int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *tmp = malloc(size * sizeof(int));

	if (!tmp)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
		tmp[k++] = left[i] < right[j] ? left[i++] : right[j++];

	while (i < left_size)
		tmp[k++] = left[i++];

	while (j < right_size)
		tmp[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);

	free(tmp);
}
/**
 * merge_sort_helper - recursive helper function for merge sort
 * @array: the array to be sorted
 * @size: size of the array
 * @tmp: temporary array to store the sorted sub-arrays
 **/
void merge_sort_helper(int *array, size_t size, int *tmp)
{
	size_t mid, i;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;

	merge_sort_helper(left, mid, tmp);
	merge_sort_helper(right, size - mid, tmp);

	printf("Merging...\n[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);

	for (i = 0; i < mid; i++)
		tmp[i] = left[i];

	for (i = 0; i < size - mid; i++)
		tmp[mid + i] = right[i];

	merge(array, size, tmp, mid, tmp + mid, size - mid);
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(size * sizeof(int));

	if (!tmp)
		return;


	merge_sort_helper(array, size, tmp);

	free(tmp);
}
