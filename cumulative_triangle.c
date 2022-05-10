/*Imagine a triangle of numbers which follows this pattern:

Starting with the number "1", "1" is positioned at the top of the triangle. As this is the 1st row, it can only support a single number.
The 2nd row can support the next 2 numbers: "2" and "3"
Likewise, the 3rd row, can only support the next 3 numbers: "4", "5", "6"
And so on; this pattern continues.

1
2 3
4 5 6
7 8 9 10
...

Given N, return the sum of all numbers on the Nth Row:

1 <= N <= 10,000*/
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull cumulative_triangle(ull n);

int main() {
    int n = 4;

    printf("%u", cumulative_triangle(n));
}

ull cumulative_triangle(ull n) {
    ull a = (n * (n - 1)) / 2 + 1;
    ull b = a + (n - 1);
    ull sum = 0;

    for (int i = a; i <= b; ++i) {
        sum += i;
    }

    return sum;
}

/*
ull cumulative_triangle(ull n) {
    return (pow(n, 3) + n) / 2;
}*/
