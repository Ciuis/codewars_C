/*
A non-empty array a of length n is called an array of all possibilities if it contains all numbers between 0 and a.length - 1 (both inclusive).

Write a function that accepts an integer array and returns true if the array is an array of all possibilities, else false.

Examples:

[1,2,0,3] => True
# Includes all numbers between 0 and a.length - 1 (4 - 1 = 3)

[0,1,2,2,3] => False
# Doesn't include all numbers between 0 and a.length - 1 (5 - 1 = 4)

[0] => True
# Includes all numbers between 0 and a.length - 1 (1 - 1 = 0).*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool is_all_possibilities (size_t n, const int array[n]);

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int arr[] = {1, 0, 2, 3};
    size_t n = 4;

    printf("%d", is_all_possibilities(n, arr));

    return 0;
}

bool is_all_possibilities (size_t n, const int array[n]) {
    if (array == NULL) return false;
    int tmp[n];
    int v[n];
    for (int i = 0; i < n; ++i) {
        tmp[i] = array[i];
    }
    for (int i = 0 ; i < n; ++i) {
        v[i] = i;
    }

    qsort(tmp, n, sizeof(int), compare);

    for (int i = 0; i < n; ++i) {
        if (tmp[i] != v[i]) return false;
    }

    return true;

}