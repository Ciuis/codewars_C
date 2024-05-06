/*
Given a triangle of consecutive odd numbers:

              1
           3     5
        7     9    11
    13    15    17    19
 21    23    25    27    29
...
find the triangle's row knowing its index (the rows are 1-indexed), e.g.:

odd_row(1)  ==  [1]
odd_row(2)  ==  [3, 5]
odd_row(3)  ==  [7, 9, 11]
Note: your code should be optimized to handle big inputs.*/

#include <stdlib.h>

unsigned long long *oddrow(size_t inx) {
    unsigned long long* result = malloc(inx * sizeof(unsigned long long));
    unsigned long long base = inx * (inx - 1);
    for (size_t i = 0; i < inx; ++i) result[i] = base + i * 2 + 1;
    return result;
}