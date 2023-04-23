#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int start, int middle, int end)
{
    int size1 = middle - start + 1;
    int size2 = end - middle;
    int left[size1], right[size2];
    
    for (int i = 0; i < size1; i++)
        left[i] = array[start + i];
    for (int j = 0; j < size2; j++)
        right[j] = array[middle + 1 + j];
    
    int i = 0, j = 0, k = start;
    
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < size1)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    
    while (j < size2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort_helper(int *array, int start, int end)
{
    if (start >= end)
        return;
    
    int middle = start + (end - start) / 2;
    
    merge_sort_helper(array, start, middle);
    merge_sort_helper(array, middle + 1, end);
    
    merge(array, start, middle, end);
}

void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    
    merge_sort_helper(array, 0, size - 1);
}

/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    merge_sort(arr, size);
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
