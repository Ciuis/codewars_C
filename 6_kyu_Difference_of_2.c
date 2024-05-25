/*
The objective is to return all pairs of integers from a given array of integers that have a difference of 2.
The result array should be sorted in ascending order of values.
Assume there are no duplicate integers in the array. The order of the integers in the input array should not matter.
Examples
[1, 2, 3, 4]  should return [[1, 3], [2, 4]]
[4, 1, 2, 3]  should also return [[1, 3], [2, 4]]
[1, 23, 3, 4, 7] should return [[1, 3]]
[4, 3, 1, 5, 6] should return [[1, 3], [3, 5], [4, 6]]*/

#include <stdlib.h>

typedef struct Integer_Pair {
    int a;
    int b;
} pair;

int compare(const void * a, const void * b) {
    return  *(const int*)a -  *(const int*)b;
}

pair *twos_difference(size_t n, const int array[n], size_t *z);

// N.B. assign the size of the return array to the pointer *z
pair *twos_difference(size_t n, const int array[n], size_t *z) {
    int* tmp = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) tmp[i] = array[i];
    qsort(tmp, n, sizeof(int), compare);

    *z = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (abs(tmp[i] - tmp[j]) == 2) {
                (*z)++;
                break;
            }
        }
    }
    pair* result = malloc((*z) * sizeof(pair));

    size_t k = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (abs(tmp[i] - tmp[j]) == 2) {
                result[k].a = tmp[i];
                result[k].b = tmp[j];
                k++;
                break;
            }
        }
    }
    return result;
}