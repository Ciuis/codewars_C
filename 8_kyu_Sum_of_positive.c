/*
You get an array of numbers, return the sum of all of the positives ones.

Example [1,-4,7,12] => 1 + 7 + 12 = 20

Note: if there is nothing to sum, the sum is default to 0.
*/

#include <stddef.h>

int positive_sum(const int *values, size_t count) {
    int res = 0;
    for (size_t i = 0; i < count; ++i) {
        values[i] > 0 ? res += values[i] : res;
    }

    return res;
}


/*
int positive_sum(const int *val, size_t len) {
    int res = 0;
    while (len --> 0) res += val[len] > 0 ? val[len] : 0;

    return res;
}*/
