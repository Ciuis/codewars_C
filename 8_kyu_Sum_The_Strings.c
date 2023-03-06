/*
Create a function that takes 2 integers in form of a string as an input, and outputs the sum (also as a string):

Example: (Input1, Input2 -->Output)

"4",  "5" --> "9"
"34", "5" --> "39"
"", "" --> "0"
"2", "" --> "2"
"-5", "3" --> "-2"

Notes:

If either input is an empty string, consider it as zero.

Inputs and the expected output will never exceed the signed 32-bit integer limit (2^31 - 1)*/
#include <stdio.h>
#include <stdlib.h>

char *sum_strings (char *sum, const char *a, const char *b);

int main(void) {
    const char* a = "";
    const char* b = "8";
    char* sum = (char*)malloc(100);

    printf("%s", sum_strings(sum, a, b));
}

char *sum_strings (char *sum, const char *a, const char *b) {
    char* ptr;
    int na = strtol(a, &ptr, 10);
    int nb = strtol(b, &ptr, 10);
    sprintf(sum,"%d", na + nb);

    return sum;
}