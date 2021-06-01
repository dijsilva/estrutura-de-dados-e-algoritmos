#include <stdlib.h>
#include "heap_sort.h"

void maxheapify(int* vector, size_t elem_index, size_t size){
  int left_child;
  int right_child;
  int largest_element;
  int temp_element;

  while (elem_index < size) {
    left_child = (elem_index * 2) + 1;
    right_child = (elem_index * 2) + 2;
    largest_element = elem_index;

    if (left_child < size && vector[left_child] > vector[largest_element]) {
      largest_element = left_child;
    }
    if (right_child < size && vector[right_child] > vector[largest_element]) {
      largest_element = right_child;
    }

    if (largest_element != elem_index) {
      // swap elements of node
      temp_element = vector[elem_index];
      vector[elem_index] = vector[largest_element];
      vector[largest_element] = temp_element;

      // go to largest element after swap
      elem_index = largest_element;
    } else {
      break;
    }
  }
}


void build_heap(int* vector, size_t size) {
  int middle = size / 2;

  for (int i = middle; i >= 0; i--) {
    maxheapify(vector, i, size);
  }
}

void heap_sort(int* vector, size_t size){
  build_heap(vector, size);
  int temp_element;
  for (int i = size - 1; i > 0; i--) {
    temp_element = vector[i];
    vector[i] = vector[0];
    vector[0] = temp_element;

    maxheapify(vector, 0, i);
  }
}
