/*Create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits. For example:

12 ==> 21
513 ==> 531
2017 ==> 2071

If the digits can't be rearranged to form a bigger number, return -1 (or nil in Swift, None in Rust):

9 ==> -1
111 ==> -1
531 ==> -1*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
long long next_bigger_number(long long n);

int main(void) {
    long long n = 5051;
    printf("%lld", next_bigger_number(n));
}

int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

long long next_bigger_number(long long n) {
    int length = snprintf(NULL, 0, "%lld", n);
    char str[length + 1];
    sprintf(str, "%lld", n);

    for (int i = length - 2; i >= 0; i--) {
        if (str[i] < str[i + 1]) {
            for (int j = length - 1; j > i; j--) {
                if (str[j] > str[i]) {
                    char temp = str[j];
                    str[j] = str[i];
                    str[i] = temp;
                    qsort(str + i + 1, length - i - 1, sizeof(char), compare);
                    return atoll(str);
                }
            }
        }
    }

    return -1;
}


/*
long long next_bigger_number(long long n) {
    char str[20];
    sprintf(str, "%lld", n);
    int len = strlen(str);
    int i, j;
    for (i = len - 2; i >= 0; i--) {
        if (str[i] < str[i + 1]) {
            break;
        }
    }
    if (i < 0) {
        return -1;
    }
    for (j = len - 1; j > i; j--) {
        if (str[j] > str[i]) {
            break;
        }
    }
    char tmp;
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    for (i = i + 1, j = len - 1; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    long long result = 0;
    for (i = 0; i < len; i++) {
        result = result * 10 + str[i] - '0';
    }
    return result;
}*/
