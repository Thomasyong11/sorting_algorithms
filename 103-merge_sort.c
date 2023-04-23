#include <stdio.h>
#include <stdlib.h>

void merge(int *left_array, int left_size, int *right_array, int right_size, int *result) {
    int i = 0, j = 0, k = 0;
    
    while (i < left_size && j < right_size) {
        if (left_array[i] < right_array[j]) {
            result[k] = left_array[i];
            i++;
        } else {
            result[k] = right_array[j];
            j++;
        }
        k++;
    }
    
    while (i < left_size) {
        result[k] = left_array[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        result[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, size_t size) {
    if (size > 1) {
        int middle = size / 2;
        int *left_array = array;
        int left_size = middle;
        int *right_array = array + middle;
        int right_size = size - middle;
        
        merge_sort(left_array, left_size);
        merge_sort(right_array, right_size);
        
        int *result = malloc(size * sizeof(int));
        
        merge(left_array, left_size, right_array, right_size, result);
        
        for (int i = 0; i < size; i++) {
            array[i] = result[i];
        }
        
        free(result);
    }
}

