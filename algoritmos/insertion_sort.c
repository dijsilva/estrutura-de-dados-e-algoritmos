#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"

void insertion_sort(int** numbers, size_t size){
    size_t j;
    for (j = 1; j < size; j++) {
        int key = (*numbers)[j];
        int i = j - 1;
        while(i >= 0 && (*numbers)[i] > key) {
            (*numbers)[i+1] = (*numbers)[i];
            i--;
        }
        (*numbers)[i+1] = key;
    }
}
