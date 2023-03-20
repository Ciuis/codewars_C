/*
We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.
Example

add("123", "321"); // returns "444"
add("11", "99");   // returns "110"

Notes

        The input numbers are big.
The input is a string of only digits
The numbers are positives
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *add(const char *a, const char *b);

int main(void) {
    char num1[] = "90938498237058927340892374089";
    char num2[] = "1";

    //char* result = add(num1, num2);

    printf("%s", add(num1, num2));
}

char *add(const char *a, const char *b) {
    int max_len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char* res = (char*)malloc(sizeof(char) * (max_len + 2));
    res[max_len + 1] = '\0';

    int x_q = 0;
    for (size_t i = 0; i <= max_len; ++i) {
        int x_a = (i < strlen(a)) ? a[strlen(a) - 1 - i] - '0' : 0;
        int x_b = (i < strlen(b)) ? b[strlen(b) - 1 - i] - '0' : 0;
        int x_sum = x_a + x_b + x_q;
        res[max_len - i] = x_sum % 10 + '0';
        x_q = x_sum / 10;
    }

    if (res[0] == '0') {
        memmove(res, res + 1, max_len + 1);
        res[max_len] = '\0';
    }

    return res;
}