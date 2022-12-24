/*
Primes that have only odd digits are pure odd digits primes, obvious but necessary definition. Examples of pure odd digit primes are: 11, 13, 17, 19, 31... If a prime has only one even digit does not belong to pure odd digits prime, no matter the amount of odd digits that may have.

Create a function, only_oddDigPrimes(), that receive any positive integer n, and output a list like the one below:

[number pure odd digit primes below n, largest pure odd digit prime smaller than n, smallest pure odd digit prime higher than n]

Let's see some cases:

only_oddDigPrimes(20) ----> [7, 19, 31]
///7, beacause we have seven pure odd digit primes below 20 and are 3, 5, 7, 11, 13, 17, 19
19, because is the nearest prime of this type to 20
31, is the first pure odd digit that we encounter after 20///

only_oddDigPrimes(40) ----> [9, 37, 53]

In the case that n, the given value, is a pure odd prime, should be counted with the found primes and search for the immediately below and the immediately after.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


typedef struct Pure_Odd_Digits_Primes_Data {
    unsigned lower, beneath, above;
} podp_data;

bool is_prime(unsigned num);
bool is_odd (unsigned num);
podp_data only_odd_digit_primes(unsigned number);

int main() {
    unsigned number = 20;

    only_odd_digit_primes(number);

    printf("%d, %d, %d", only_odd_digit_primes(number).lower, only_odd_digit_primes(number).beneath,
           only_odd_digit_primes(number).above);
}

bool is_prime(unsigned num) {
    if (num == 2 || num == 3) return true;
    if (num < 2 || num % 2 == 0) return false;

    for (unsigned i = 3; i < (pow(num, 0.5) + 1); ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool is_odd (unsigned num) {
    while (num) {
        if ((num % 10) % 2 == 0)
            return false;
        num /= 10;
    }

    return true;
}

podp_data only_odd_digit_primes(unsigned number) {
    podp_data res = { 0 };

    for (unsigned i = 3; i < number - 1; ++i) {
        if (is_odd(i) && is_prime(i)) {
            res.lower++;
            res.beneath = i;
        }
    }

    for (unsigned i = number + 1; ; ++i) {
        if(is_odd(i) && is_prime(i)) {
            res.above = i;
            break;
        }
    }

    return res;
}