/*Your task is to determine the Next Higher Power of 2 to a given input number - or something like that...;-)

Here it's easy, you don't have to check errors or incorrect input values, every thing is ok without bad tricks, only int numbers as input and output;-)...

Some easy examples:

Input: 2      => Output: 4
Input: 7      => Output: 8
Input: -1     => Output: ?
Input: -128   => Output: -64

There are some static tests at the beginning and many random tests if you submit your solution.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int next_power_of_2 (int n);

int main() {
    int n = 536870912;
    next_power_of_2(n);
}

int next_power_of_2 (int n) {
    uint64_t x = 0;

    if (n > 0) {
        return powl(2, (int)sqrtl(n) + 1);

        printf("%lld\n", x);
    } else if (n < 0) {
        return -powl(2, sqrtl(abs(n)) - 1);
    }
}