/*
Given a non-empty array of integers, return the result of multiplying the values together in order. Example:

[1, 2, 3, 4] => 1 * 2 * 3 * 4 = 24*/

#include <stddef.h>

int grow(size_t size, const int arr[size]) {
    int res = 1;
    for (int i = 0; i < size; ++i) {
        res *= arr[i];
    }
    return res;
}