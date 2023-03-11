/*Caution: This kata does not currently have any known supported versions for C. It may not be completable due to dependencies on out-dated libraries/language versions.

In this simple exercise, you will build a program that takes a value, integer , and returns a list of its multiples up to another value, limit . If limit is a multiple of integer, it should be included as well. There will only ever be positive integers passed into the function, not consisting of 0. The limit will always be higher than the base.

For example, if the parameters passed are (2, 6), the function should return [2, 4, 6] as 2, 4, and 6 are the multiples of 2 up to 6.*/

#include <stddef.h>
#include <stdio.h>

typedef unsigned int uint;

void find_multiples (uint n, uint limit, size_t *count, uint multiples[]);

int main(void) {
    uint multiples[100] = {0};
    size_t* count = NULL;
    find_multiples(2, 12, &count, multiples);
}

void find_multiples (uint n, uint limit, size_t *count, uint multiples[]) {
    for(int i = 1; i <= (*count = limit / n); i++)  multiples[i-1] = n * i;
}