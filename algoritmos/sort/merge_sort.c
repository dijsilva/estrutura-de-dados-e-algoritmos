#include <stdlib.h>

#include "merge_sort.h"
#include "utils.h"

void merge(int* vector, int* left_vector, int* right_vector, size_t size){
    int left = 0, right = 0, i_vector = 0;
    size_t size_left = size / 2;
    size_t size_right = size - size_left;
    while ((left < size_left) && (right < size_right)) {
        if (left_vector[left] < right_vector[right]) {
            vector[i_vector] = left_vector[left];
            ++i_vector;
            ++left;
        } else {
            vector[i_vector] = right_vector[right];
            ++i_vector;
            ++right;
        }
    }

    while (left < size_left) {
        vector[i_vector] = left_vector[left];
        ++i_vector;
        ++left;
    }
    while (right < size_right) {
        vector[i_vector] = right_vector[right];
        ++i_vector;
        ++right;
    }
}

void merge_sort(int* vector, size_t size){
    if (size == 1) {
        return;
    }
    size_t middle = size / 2;
    int* left_vector = calloc(middle, sizeof(int));
    int* right_vector = calloc(size - middle, sizeof(int));
    copy_items(vector, left_vector, middle);
    copy_items(vector + middle, right_vector, size - middle);
    merge_sort(left_vector, middle);
    merge_sort(right_vector, size - middle);
    merge(vector, left_vector, right_vector, size);
    free(left_vector);
    free(right_vector);
}

