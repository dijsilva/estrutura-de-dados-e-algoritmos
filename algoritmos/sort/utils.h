#ifndef __UTILS_H
#define __UTILS_H

#include <stdlib.h>

int* gen_numbers(int, int);
int is_ordered(int*, size_t size);
void copy_items(int* source, int* dest, size_t size);
void log_vector_items(int* vector, size_t size);

#endif
