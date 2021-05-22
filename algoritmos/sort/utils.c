#include "time.h"
#include "stdlib.h"
#include "utils.h"
#include <stdio.h>

int* gen_numbers(int n, int max){
    int rand_number = 0;
    int* numbers = calloc(n, sizeof(int));

    // define always a different seed
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        rand_number = rand() % max;
        numbers[i] = rand_number;
    }

    return numbers;
}

int is_ordered(int* numbers, size_t size){
    if (size == 1){
        return 1;
    }

    int is_ordered = 1;
    size_t i;
    for (i = 0; i < size - 1; i++){
        if (numbers[i] > numbers[i + 1]){
            is_ordered = 0;
            break;
        }
    }
    return is_ordered;
}


void copy_items(int* source, int* dest, size_t size){
    int i = 0;
    while (size) {
        dest[i] = source[i];
        --size;
        ++i;
    }
}

void log_vector_items(int* vector, size_t size){
    int i = 0;
    while(i < size) {
        printf("%d ", vector[i++]);
    }
    printf("\n");
}
