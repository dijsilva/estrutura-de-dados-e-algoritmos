#include <stdlib.h>
#include <stdio.h>

#include "utils_gen_numbers.h"
#include "utils_ordered_test.h"

#include "insertion_sort.h"

#define MAX_ITEMS 10

int main() {
    int* numbers = gen_numbers(MAX_ITEMS, 20);

    for (int i = 0; i < MAX_ITEMS; i++){
        printf("%d ", numbers[i]);
    }
    int ordered = is_ordered(numbers, MAX_ITEMS);
    ordered ? printf("Ordernado!\n") : printf("Nao ordernado!\n");

    insertion_sort(&numbers, MAX_ITEMS);
    for (int i = 0; i < MAX_ITEMS; i++){
        printf("%d ", numbers[i]);
    }
    ordered = is_ordered(numbers, MAX_ITEMS);
    ordered ? printf("Ordernado!\n") : printf("Nao ordernado!\n");

    free(numbers);
    return 0;
}
