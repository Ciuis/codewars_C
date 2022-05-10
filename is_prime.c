#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);

int main() {
    int num = 13;

    printf("%d", is_prime(num));
}

bool is_prime(int num) {
    if (num < 2 && num % 2== 0) {
        return false;
    }

    for (int i = 3; i * i <= num; i+=2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}