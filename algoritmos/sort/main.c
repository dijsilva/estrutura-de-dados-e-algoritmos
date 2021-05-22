#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "utils.h"

#include "insertion_sort.h"
#include "merge_sort.h"

#define MAX_ITEMS 200000
#define MAX_VALUE 10000000

int main() {
    clock_t time_start = 0, time_end = 0;
    int ordered = -1;
    double time_insertion, time_merge;
    int* numbers = gen_numbers(MAX_ITEMS, 1000);
    int* insertion_numbers = calloc(MAX_ITEMS, sizeof(int));
    int* merge_numbers = calloc(MAX_ITEMS, sizeof(int));
    copy_items(numbers, insertion_numbers, MAX_ITEMS);
    copy_items(numbers, merge_numbers, MAX_ITEMS);


    ordered = is_ordered(numbers, MAX_ITEMS);
    if (ordered) {
        printf("Already ordered.");
        exit(EXIT_FAILURE);
    }
    printf("Sorting with insertion sort...\n");
    time_start = clock();
    insertion_sort(&insertion_numbers, MAX_ITEMS);
    time_end = clock();
    printf("Sorting complete\n");
    time_insertion = (double) ((time_end - time_start) / CLOCKS_PER_SEC);
    ordered = is_ordered(insertion_numbers, MAX_ITEMS);
    if (!ordered) {
        printf("Vector not ordered by insertion sort algorithm");
        exit(EXIT_FAILURE);
    }

    printf("Sorting with merge sort...\n");
    time_start = clock();
    merge_sort(merge_numbers, MAX_ITEMS);
    time_end = clock();
    printf("Sorting complete\n");
    time_merge = (double) ((time_end - time_start) / CLOCKS_PER_SEC);
    ordered = is_ordered(merge_numbers, MAX_ITEMS);
    if (!ordered) {
        printf("Vector not ordered by merge sort algorithm");
        exit(EXIT_FAILURE);
    }

    printf("Insertion sort concluded in %lf seconds.\n", time_insertion);
    printf("Merge sort concluded in %lf seconds.\n", time_merge);

    free(numbers);
    free(merge_numbers);
    free(insertion_numbers);
    return 0;
}
