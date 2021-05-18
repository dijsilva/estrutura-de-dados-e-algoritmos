#include <stdlib.h>
#include <time.h>
#include "gen_numbers.h"


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
