/*
We need prime numbers and we need them now!

Write a method that takes a maximum bound and returns all primes up to and including the maximum bound.

For example,

11 => [2, 3, 5, 7, 11]
*/

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//  assign values to pre-allocated array *primes
//  set *z as the length of this output

bool is_prime(int num);
void prime(unsigned m, size_t* z, unsigned *primes);

int main() {
    unsigned m = 5;
    size_t* z = {0};
    unsigned* primes = malloc(m * sizeof(int));

    prime(m, z, primes);
}

bool is_prime(int num) {
    if (num == 2 || num == 3) return true;
    if (num < 2 || num % 2 == 0) return false;

    for (int i = 3; i < (pow(num, 0.5) + 1); ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void prime(unsigned m, size_t* z, unsigned *primes) {
    int cnt = 0;

    for (int i = 0; i <= m; ++i) {
        if (is_prime(i) == true) {
            primes[cnt] = i;
            ++cnt;
            *z = cnt;
        }
    }
}