/*
Make a function "add" that will be able to sum elements of list continuously and return a new list of sums.
For example:
add [1,2,3,4,5] == [1, 3, 6, 10, 15], because it's calculated like
this : [1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4, 1 + 2 + 3 + 4 + 5]
If you want to learn more see https://en.wikipedia.org/wiki/Prefix_sum*/

#include <stddef.h>

void add(size_t length, int array[length], int *output) {
    int s = array[0];
    for (int i = 0; i < length; ++i) {
        output[i] = s;
        s += array[i+1];
    }
}
