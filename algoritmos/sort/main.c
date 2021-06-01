#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "utils.h"

#include "insertion_sort.h"
#include "merge_sort.h"

#define MAX_VALUE 10000000

int main() {
  int max_elements;

  printf("Max numbers in vector: ");
  scanf("%d", &max_elements);
  clock_t time_start = 0, time_end = 0;
  int ordered = -1;
  double time_insertion, time_merge, time_heap;
  int* numbers = gen_numbers(max_elements, 1000);
  int* insertion_numbers = calloc(max_elements, sizeof(int));
  int* merge_numbers = calloc(max_elements, sizeof(int));
  int* heap_numbers = calloc(max_elements, sizeof(int));
  copy_items(numbers, insertion_numbers, max_elements);
  copy_items(numbers, merge_numbers, max_elements);
  copy_items(numbers, heap_numbers, max_elements);


  ordered = is_ordered(numbers, max_elements);
  if (ordered) {
      printf("Already ordered.");
      exit(EXIT_FAILURE);
  }
  printf("Sorting with insertion sort...\n");
  time_start = clock();
  insertion_sort(&insertion_numbers, max_elements);
  time_end = clock();
  printf("Sorting complete\n");
  time_insertion = (double) ((time_end - time_start) / CLOCKS_PER_SEC);
  ordered = is_ordered(insertion_numbers, max_elements);
  if (!ordered) {
      printf("Vector not ordered by insertion sort algorithm");
      exit(EXIT_FAILURE);
  }

  printf("Sorting with merge sort...\n");
  time_start = clock();
  merge_sort(merge_numbers, max_elements);
  time_end = clock();
  printf("Sorting complete\n");
  time_merge = (double) ((time_end - time_start) / CLOCKS_PER_SEC);
  ordered = is_ordered(merge_numbers, max_elements);
  if (!ordered) {
      printf("Vector not ordered by merge sort algorithm");
      exit(EXIT_FAILURE);
  }

  printf("Sorting with heap sort...\n");
  time_start = clock();
  merge_sort(heap_numbers, max_elements);
  time_end = clock();
  printf("Sorting complete\n");
  time_heap = (double) ((time_end - time_start) / CLOCKS_PER_SEC);
  ordered = is_ordered(heap_numbers, max_elements);
  if (!ordered) {
      printf("Vector not ordered by merge sort algorithm");
      exit(EXIT_FAILURE);
  }

  printf("Insertion sort concluded in %lf seconds.\n", time_insertion);
  printf("Merge sort concluded in %lf seconds.\n", time_merge);
  printf("Heap sort concluded in %lf seconds.\n", time_heap);

  free(numbers);
  free(merge_numbers);
  free(insertion_numbers);
  free(heap_numbers);
  return 0;
}
