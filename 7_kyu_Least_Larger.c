/*
Given an array of numbers and an index, return either the index of the smallest number that is larger than the element at the given index, or -1 if there is no such index ( or, where applicable, Nothing or a similarly empty value ).

Notes
        Multiple correct answers may be possible. In this case, return any one of them.
The given index will be inside the given array.
The given array will, therefore, never be empty.

Example
least_larger({4, 1, 3, 5, 6}, 5, 0) ==  3;
least_larger({4, 1, 3, 5, 6}, 5, 4) == -1;*/

#include <sys/types.h>

ssize_t least_larger(const int *array, size_t n, size_t index) {
    ssize_t result = -1;
    ssize_t min = 9999;
    for (ssize_t i = 0; i < n; ++i) {
        if (array[i] > array[index] && array[i] < min) {
            min = array[i];
            result = i;
        }
    }
    return result;
}