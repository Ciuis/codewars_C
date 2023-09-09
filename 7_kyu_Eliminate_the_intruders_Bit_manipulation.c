/*
Task
        You are given a string representing a number in binary. Your task is to delete all the unset bits in this string and return the corresponding number (after keeping only the '1's).

In practice, you should implement this function:

long eliminate_unset_bits(const char* number);
Examples
eliminate_unset_bits("11010101010101") ->  255 (= 11111111)
eliminate_unset_bits("111") ->  7
eliminate_unset_bits("1000000") -> 1
eliminate_unset_bits("000") -> 0*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

long eliminate_unset_bits(const char* number);

int main (void) {
    char* number = "10110101";
    printf("%lu", eliminate_unset_bits(number));
    return 0;
}

long eliminate_unset_bits(const char* number) {
    char* s = calloc(strlen(number) + 1, sizeof(char));
    int n = 0;
    long m = 0;
    for (int i = 0; i < strlen(number); ++i) {
        if (number[i] == '1') { s[n] = '1'; ++n; }
    }
    s[n] = '\0';

    m = strtol(s, NULL, 2);
    return m;
}