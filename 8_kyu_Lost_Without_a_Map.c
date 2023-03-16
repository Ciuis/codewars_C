/*
Given an array of integers, return a new array with each value doubled.

For example:

[1, 2, 3] --> [2, 4, 6]
*/

#include <stddef.h>
#include <stdlib.h>

int *maps(const int *arr, size_t size) {
    int* res = calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i)
        res[i] = arr[i] * 2;

    return res;
}