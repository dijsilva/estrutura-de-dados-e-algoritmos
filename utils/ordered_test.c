#include <stdlib.h>
#include "ordered_test.h"

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
