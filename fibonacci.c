/*
Create function fib that returns n'th element of Fibonacci sequence (classic programming task).
 */

#include <stdio.h>

int fib(int n);

int main() {
    int n = 7;
    printf("%d", fib(n));
}

int fib(int n) {
    int sFib = 0;
    if (n < 2) return sFib = 1;
    sFib = fib(n - 1) + fib(n - 2);

    return sFib;
}