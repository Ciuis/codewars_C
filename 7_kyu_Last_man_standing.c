/*
Start with the first number on the left then remove every other number moving right until you reach the the end, then from the numbers remaining start with the first number on the right and remove every other number moving left, repeat the process alternating between left and right until only one number remains which you return as the "last man standing"

##Example

        given an input of `9` our set of numbers is `1 2 3 4 5 6 7 8 9`

start by removing from the left    2   4   6   8
1   3   5   7   9


then from the right                2       6
4       8


then the left again                        6
2


until we end with `6` as the last man standing
        Note: due to the randomness of the tests it is possible that you will get unlucky and a few of the tests will be really large, so try submitting 2 or 3 times.

As allways any feedback would be much appreciated*/

#include <stdlib.h>

unsigned last_man_standing (unsigned n) {
    unsigned* arr = malloc(n * sizeof(unsigned));
    for(unsigned i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    size_t len = n;

    while (len > 1) {
        size_t tmp_len = len / 2;
        unsigned* tmp = malloc(tmp_len * sizeof(unsigned));
        for (unsigned i = 1; i < len; i += 2) {
            tmp[(i - 1)/2] = arr[i];
        }
        free(arr);
        arr = tmp;
        len = tmp_len;

        for(int i = 0; i < len / 2; ++i) {
            int t = arr[i];
            arr[i] = arr[len - 1 - i];
            arr[len - 1 - i] = t;
        }
    }
    unsigned res = arr[0];
    free(arr);
    return res;
}


/* SMARTER VERSION
unsigned last_man_standing (unsigned n)
{
    return n < 2 ? 1 : n + 2 - (n & 1) - (last_man_standing(n >> 1) << 1);
}*/
