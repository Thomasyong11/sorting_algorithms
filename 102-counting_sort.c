#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order using the
 *                 Counting sort algorithm.
 * @array: pointer to the array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output, max = 0;
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL) {
        free(count);
        return;
    }

    for (i = 0; i <= (size_t)max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    printf("Counting array:\n");
    for (i = 0; i <= (size_t)max; i++) {
        printf("%d: %d\n", i, count[i]);
    }

    for (i = 1; i <= (size_t)max; i++) {
        count[i] += count[i - 1];
    }

    for (i = 0; i < size; i++) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(count);
    free(output);
}

int main(void)
{
    int array[] = {5, 3, 2, 7, 8, 6, 4, 1, 9, 0};
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;

    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    counting_sort(array, size);

    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
