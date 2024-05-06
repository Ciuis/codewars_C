/*
At the annual family gathering, the family likes to find the oldest living family member’s age and the youngest family member’s age and calculate the difference between them.
You will be given an array of all the family members' ages, in any order. The ages will be given in whole numbers, so a baby of 5 months, will have an ascribed ‘age’ of 0. Return a new array (a tuple in Python) with [youngest age, oldest age, difference between the youngest and oldest age].
 */

#include <stdlib.h>

int find_max(size_t a, const int ages[a]) {
    int max = ages[0];
    for (int i = 0; i < a; ++i) {
        if (ages[i] > max) max = ages[i];
    }
    return max;
}

int find_min(size_t a, const int ages[a]) {
    int min = ages[0];
    for (int i = 0; i < a; ++i) {
        if (ages[i] < min) min = ages[i];
    }
    return min;
}

int *difference_in_ages(size_t a, const int ages[a]) {
    int* arr = malloc(3 * sizeof(int));
    arr[0] = find_min(a, ages);
    arr[1] = find_max(a, ages);
    arr[2] = arr[1] - arr[0];

    return arr;
}